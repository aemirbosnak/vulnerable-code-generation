#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void plugin_loader(char **plugin_path) {
  char buffer[1024];
  scanf("%s", buffer);
  plugin_path = malloc(strlen(buffer) + 1);
  strcpy(plugin_path, buffer);
}

int main() {
  char *plugin_path = NULL;
  plugin_loader(&plugin_path);
  printf("Plugin path: %s", plugin_path);
  free(plugin_path);
  return 0;
}
