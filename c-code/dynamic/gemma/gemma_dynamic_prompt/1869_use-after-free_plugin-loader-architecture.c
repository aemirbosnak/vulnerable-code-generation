#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void* plugin_loader(char* plugin_name) {
  void* plugin_ptr = NULL;
  FILE* plugin_file = fopen(plugin_name, "r");
  if (plugin_file) {
    plugin_ptr = malloc(1024);
    fread(plugin_ptr, 1024, 1, plugin_file);
    fclose(plugin_file);
  }
  return plugin_ptr;
}

int main() {
  char* plugin_name = "my_plugin.so";
  void* plugin_ptr = plugin_loader(plugin_name);
  if (plugin_ptr) {
    printf("Plugin data: %s", (char*)plugin_ptr);
  } else {
    printf("Error loading plugin: %s", plugin_name);
  }
  return 0;
}
