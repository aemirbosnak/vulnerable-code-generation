#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void* plugin_loader(char* plugin_name) {
  void* plugin = NULL;
  FILE* file = fopen(plugin_name, "r");
  if (file) {
    plugin = malloc(1024);
    fread(plugin, 1024, 1, file);
    fclose(file);
  }
  return plugin;
}

int main() {
  char* plugin_name = "/path/to/plugin.so";
  void* plugin = plugin_loader(plugin_name);
  if (plugin) {
    printf("Plugin loaded: %p\n", plugin);
  } else {
    printf("Error loading plugin: %s\n", plugin_name);
  }
  return 0;
}
