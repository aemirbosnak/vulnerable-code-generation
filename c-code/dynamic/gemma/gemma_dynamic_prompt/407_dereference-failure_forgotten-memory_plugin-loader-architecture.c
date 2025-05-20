#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void* plugin_loader(char* name) {
  void** ptr = (void**)malloc(1024);
  *ptr = (void*)fopen(name, "r");
  return *ptr;
}

int main() {
  plugin_loader("foo.txt");
  return 0;
}
