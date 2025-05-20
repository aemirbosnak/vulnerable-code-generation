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

  // Allocate memory for the plugin data
  void* plugin = malloc(1024);
  if (!plugin) {
    fclose(file);
    return NULL;
  }

  // Read the plugin data from the file
  size_t read = fread(plugin, 1024, 1, file);
  fclose(file);

  // Return the plugin data
  return plugin;
}

int main() {
  char* path = "/path/to/plugin.so";
  void* plugin = plugin_loader(path);

  // Use the plugin data
  printf("Plugin data: %s", (char*)plugin);

  // Free the plugin data
  free(plugin);

  return 0;
}
