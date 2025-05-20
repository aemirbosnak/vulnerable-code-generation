#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void* plugin_loader(char* plugin_name) {
  FILE* plugin_file = fopen(plugin_name, "r");
  if (plugin_file == NULL) {
    return NULL;
  }

  // Allocate memory for the plugin
  void* plugin_data = malloc(1024);
  if (plugin_data == NULL) {
    return NULL;
  }

  // Read the plugin code from the file
  int read_size = fread(plugin_data, 1, 1024, plugin_file);
  if (read_size != 1024) {
    return NULL;
  }

  // Close the plugin file
  fclose(plugin_file);

  // Return the plugin data
  return plugin_data;
}

int main() {
  char* plugin_name = "foo.txt";
  void* plugin_data = plugin_loader(plugin_name);

  if (plugin_data) {
    printf("Plugin data: %s", plugin_data);
  } else {
    printf("Error loading plugin: %s", plugin_name);
  }

  return 0;
}
