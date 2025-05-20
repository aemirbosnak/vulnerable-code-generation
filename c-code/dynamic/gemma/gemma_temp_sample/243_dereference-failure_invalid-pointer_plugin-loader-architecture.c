#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void* plugin_loader(char* name) {
  void* plugin = NULL;

  // Malformed pointer
  plugin = (void*) (*(int*)name);

  // Use the plugin (unsafe!)
  printf("%s", plugin);

  return plugin;
}

int main() {
  plugin_loader("vulnerable.plugin");

  return 0;
}
