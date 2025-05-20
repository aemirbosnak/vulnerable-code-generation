#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void* plugin_loader(char* plugin_path) {
  void* plugin = NULL;

  // Open the plugin file
  FILE* plugin_file = fopen(plugin_path, "r");
  if (plugin_file == NULL) {
    return NULL;
  }

  // Allocate memory for the plugin
  plugin = malloc(1024);
  if (plugin == NULL) {
    fclose(plugin_file);
    return NULL;
  }

  // Read the plugin data
  fread(plugin, 1024, 1, plugin_file);

  // Close the plugin file
  fclose(plugin_file);

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
