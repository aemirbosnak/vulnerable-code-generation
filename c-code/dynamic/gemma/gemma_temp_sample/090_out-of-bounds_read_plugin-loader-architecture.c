#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void* plugin_loader(char* plugin_name) {
  FILE* file = fopen(plugin_name, "r");
  if (file == NULL) {
    return NULL;
  }

  long size = 0;
  fseek(file, 0L, SEEK_END);
  size = ftell(file);
  rewind(file);

  void* plugin = malloc(size);
  fread(plugin, size, 1, file);
  fclose(file);

  return plugin;
}

int main() {
  char* plugin_name = "foo.plugin";
  void* plugin = plugin_loader(plugin_name);

  if (plugin) {
    printf("Plugin loaded: %s", plugin_name);
  } else {
    printf("Error loading plugin: %s", plugin_name);
  }

  return 0;
}
