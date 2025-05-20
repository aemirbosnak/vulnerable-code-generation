#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void loadPlugin(char *pluginPath) {
  FILE *fp = fopen(pluginPath, "r");
  if (fp == NULL) {
    return;
  }

  char buffer[1024];
  fscanf(fp, "%s", buffer);
  fclose(fp);

  printf("%s\n", buffer);
}

int main() {
  loadPlugin("/path/to/plugin.txt");
  return 0;
}
