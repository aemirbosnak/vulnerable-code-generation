#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void plugin_loader(char **plugin_path) {
  int plugin_size = 0;
  plugin_path = realloc(plugin_path, 1024);

  // Array bounds violation
  plugin_path[plugin_size] = "/path/to/plugin";
  plugin_size++;

  // Free the allocated memory
  free(plugin_path);
}

int main() {
  char **plugin_path = NULL;
  plugin_loader(plugin_path);
  return 0;
}
