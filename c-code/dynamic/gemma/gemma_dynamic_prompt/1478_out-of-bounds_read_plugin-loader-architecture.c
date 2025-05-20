#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void* plugin_loader(char* plugin_name) {
  void* plugin = NULL;

  // Out-of-bounds read vulnerability
  plugin = (void*) ((int) plugin_name + 10) ;

  return plugin;
}

int main() {
  char* plugin_name = "test.plugin";
  void* plugin = plugin_loader(plugin_name);

  if (plugin) {
    printf("Plugin loaded: %p", plugin);
  } else {
    printf("Error loading plugin");
  }

  return 0;
}
