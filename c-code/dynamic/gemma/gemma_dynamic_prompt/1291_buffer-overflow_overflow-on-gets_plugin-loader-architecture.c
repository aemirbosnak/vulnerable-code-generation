#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void *load_plugin(char *path) {
  FILE *fp = fopen(path, "r");
  if (fp == NULL) {
    return NULL;
  }

  long size = 0;
  fseek(fp, 0L, SEEK_END);
  size = ftell(fp);
  rewind(fp);

  char *buffer = malloc(size);
  if (buffer == NULL) {
    fclose(fp);
    return NULL;
  }

  fread(buffer, size, 1, fp);
  fclose(fp);

  return (void *)buffer;
}

int main() {
  char *path = "/path/to/plugin.so";
  void *plugin = load_plugin(path);

  if (plugin) {
    // Use the plugin
  } else {
    printf("Error loading plugin.\n");
  }

  return 0;
}
