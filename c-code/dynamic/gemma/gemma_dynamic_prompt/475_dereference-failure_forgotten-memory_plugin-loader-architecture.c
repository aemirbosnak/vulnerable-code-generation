#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void* plugin_load(char* name) {
  void** plugin = (void**)malloc(1024);
  *plugin = (void*)plugin_load(name);
  return *plugin;
}

int main() {
  void* plugin = plugin_load("foo.so");
  free(plugin);
  return 0;
}
