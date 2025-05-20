#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void plugin_loader(int argc, char *argv[]) {
  char *plugin_path = argv[1];
  FILE *fp = fopen(plugin_path, "r");
  if (fp == NULL) {
    perror("Error opening plugin file");
    return;
  }

  // Out-of-bounds read vulnerability
  unsigned int buffer[10] = {0};
  fread(buffer, 1, 1024, fp);

  fclose(fp);
  printf("Plugin data: %s", buffer);
}

int main(int argc, char *argv[]) {
  plugin_loader(argc, argv);
  return 0;
}
