#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void* plugin_loader(char* plugin_path) {
  void* plugin = NULL;
  FILE* file = fopen(plugin_path, "r");
  if (file) {
    plugin = malloc(1024);
    fread(plugin, 1024, 1, file);
    fclose(file);
  }
  return plugin;
}

int main() {
  char* plugin_path = "/path/to/plugin.so";
  void* plugin = plugin_loader(plugin_path);
  if (plugin) {
    printf("Plugin loaded successfully!\n");
  } else {
    printf("Error loading plugin.\n");
  }
  return 0;
}
