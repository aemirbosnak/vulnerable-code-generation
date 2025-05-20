#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void* plugin_loader(char* filename) {
  FILE* file = fopen(filename, "r");
  if (file == NULL) {
    return NULL;
  }

  // Allocate memory for the plugin module
  void* plugin = malloc(1024);
  if (plugin == NULL) {
    fclose(file);
    return NULL;
  }

  // Read the plugin module from the file
  size_t read_size = fread(plugin, 1024, 1, file);
  fclose(file);

  // Return the plugin module
  return plugin;
}

int main() {
  char* filename = "test.so";
  void* plugin = plugin_loader(filename);

  if (plugin == NULL) {
    printf("Error loading plugin.\n");
  } else {
    printf("Plugin loaded successfully.\n");
  }

  return 0;
}
