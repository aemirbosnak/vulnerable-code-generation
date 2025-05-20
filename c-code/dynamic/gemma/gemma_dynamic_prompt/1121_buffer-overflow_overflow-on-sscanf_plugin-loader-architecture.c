#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

void load_plugin(char *plugin_path) {
  FILE *fp = fopen(plugin_path, "r");
  if (fp == NULL) {
    return;
  }

  char buffer[1024] = "";
  fscanf(fp, "%s", buffer);

  fclose(fp);
  printf("%s", buffer);
}

int main() {
  load_plugin("/path/to/plugin.txt");
  return 0;
}
