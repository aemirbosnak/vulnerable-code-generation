#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void *plugin_loader(char *plugin_path) {
  void *plugin = NULL;
  FILE *fp = fopen(plugin_path, "r");
  if (fp) {
    plugin = malloc(1024);
    fread(plugin, 1024, 1, fp);
    fclose(fp);
  }
  return plugin;
}

int main() {
  char *plugin_path = "/path/to/plugin.so";
  void *plugin = plugin_loader(plugin_path);
  (*(int *)plugin) = 42;
  free(plugin);
  return 0;
}
