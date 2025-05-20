#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void* plugin_loader(char* path) {
  FILE* file = fopen(path, "r");
  if (!file) {
    return NULL;
  }
  int size = 0;
  char buffer[1024];
  while (fgets(buffer, 1024, file) != NULL) {
    size++;
  }
  fclose(file);
  return (void*)malloc(size);
}

int main() {
  char* path = "/path/to/plugin.so";
  void* plugin = plugin_loader(path);
  if (plugin) {
    printf("Plugin loaded: %p", plugin);
  } else {
    printf("Error loading plugin");
  }
  return 0;
}
