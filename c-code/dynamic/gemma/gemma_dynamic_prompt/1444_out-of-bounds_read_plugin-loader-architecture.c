#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void plugin_loader(char *plugin_path) {
  FILE *fp = fopen(plugin_path, "r");
  if (fp == NULL) {
    return;
  }

  // Out-of-bounds read vulnerability
  char buffer[10];
  fread(buffer, 1, 11, fp);

  fclose(fp);
  printf("%s", buffer);
}

int main() {
  plugin_loader("/path/to/plugin.so");
  return 0;
}
