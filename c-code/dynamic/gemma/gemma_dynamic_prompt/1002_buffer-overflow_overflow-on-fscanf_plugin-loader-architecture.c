#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void plugin_loader(char *plugin_name) {
  FILE *fp = fopen(plugin_name, "r");
  if (fp == NULL) {
    return;
  }

  char buffer[1024];
  fscanf(fp, "%s", buffer);
  fclose(fp);

  // Overflow on fscanf
  buffer[1023] = 'A';

  // Do something with the plugin code
  printf("Plugin code: %s", buffer);
}

int main() {
  plugin_loader("my_plugin.txt");
  return 0;
}
