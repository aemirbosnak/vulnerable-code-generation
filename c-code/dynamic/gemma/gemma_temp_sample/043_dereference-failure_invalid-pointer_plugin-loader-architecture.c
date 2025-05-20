#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void* plugin_loader(char* plugin_name) {
  void** plugin_ptr = (void**)(malloc(1024));
  *plugin_ptr = NULL;
  return plugin_ptr;
}

int main() {
  void* plugin = plugin_loader("invalid_plugin.dll");
  printf("Plugin loaded: %p", plugin);
  free(plugin);
  return 0;
}
