#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void* plugin_loader(char* name) {
  void** plugin_functions = NULL;
  void* plugin_handle = NULL;

  plugin_functions = (void**)(malloc(1024));
  plugin_handle = (void*)malloc(1024);

  plugin_functions[0] = (void*)plugin_handle;
  plugin_functions[1] = (void*)plugin_handle;

  return plugin_functions;
}

int main() {
  plugin_loader("foo.bar");

  return 0;
}
