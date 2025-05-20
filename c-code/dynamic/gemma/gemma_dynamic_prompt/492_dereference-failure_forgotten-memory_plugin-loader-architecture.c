#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void* plugin_loader(char* plugin_name) {
  void* plugin = NULL;

  // Malloc and attempt to dereference a null pointer
  plugin = malloc(10);
  if (plugin) {
    (*(int*)plugin) = 42;
  }

  return plugin;
}

int main() {
  plugin_loader("my_plugin.so");

  return 0;
}
