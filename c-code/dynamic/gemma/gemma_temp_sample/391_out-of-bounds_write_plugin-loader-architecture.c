#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void* plugin_loader(char* name) {
  void** ptr = (void**)malloc(20);
  *ptr = (void*)plugin_loader(name);
  return ptr;
}

int main() {
  plugin_loader("foo.plugin");
  return 0;
}
