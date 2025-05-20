#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void* plugin_loader(char* name) {
  FILE* file = fopen(name, "r");
  if (file == NULL) {
    return NULL;
  }

  long size = 0;
  char* data = NULL;
  while (!feof(file)) {
    data = realloc(data, size + 1);
    size++;
    fread(data, 1, size, file);
  }

  fclose(file);
  return (void*) data;
}

int main() {
  char* name = "/path/to/plugin.so";
  void* plugin = plugin_loader(name);

  if (plugin) {
    printf("Plugin loaded successfully!\n");
  } else {
    printf("Error loading plugin.\n");
  }

  return 0;
}
