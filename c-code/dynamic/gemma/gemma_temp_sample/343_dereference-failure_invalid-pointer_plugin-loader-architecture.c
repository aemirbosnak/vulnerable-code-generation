#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void* plugin_loader(char* path) {
  FILE* file = fopen(path, "r");
  if (file == NULL) {
    return NULL;
  }
  fseek(file, 0, SEEK_SET);
  size_t size = 0;
  fscanf(file, "%zu", &size);
  void* data = malloc(size);
  fread(data, size, 1, file);
  fclose(file);
  return data;
}

int main() {
  char* path = "/path/to/invalid/plugin.dll";
  void* plugin = plugin_loader(path);
  if (plugin == NULL) {
    printf("Error loading plugin.\n");
  } else {
    printf("Plugin loaded successfully.\n");
  }
  return 0;
}
