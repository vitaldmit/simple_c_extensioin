#define PY_SSIZE_T_CLEAN
#include <Python.h>

static PyObject* hello_world(PyObject* self, PyObject* args) {
    return PyUnicode_FromString("Hello from C!");
}

static PyMethodDef MyMethods[] = {
    {"hello", hello_world, METH_NOARGS, "Returns a hello message"},
    {NULL, NULL, 0, NULL}
};

static struct PyModuleDef mymodule = {
    PyModuleDef_HEAD_INIT,
    "mymodule",
    "Example module that provides a simple C function",
    -1,
    MyMethods
};

PyMODINIT_FUNC PyInit_mymodule(void) {
    return PyModule_Create(&mymodule);
}
