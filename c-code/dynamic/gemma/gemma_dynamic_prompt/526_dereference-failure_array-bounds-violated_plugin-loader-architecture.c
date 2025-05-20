#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void* plugin_loader(char** argv) {
  int i = 0;
  char** plugins = argv;
  for (i = 0; plugins[i] != NULL; i++) {
    printf("Loading plugin: %s\n", plugins[i]);
  }
  return NULL;
}

int main() {
  plugin_loader(NULL);
  return 0;
}
