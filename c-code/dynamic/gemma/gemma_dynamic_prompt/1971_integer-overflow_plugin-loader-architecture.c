#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

void* plugin_loader(char* filename) {
  FILE* file = fopen(filename, "r");
  if (file == NULL) {
    return NULL;
  }

  long size = 0;
  fseek(file, 0, SEEK_END);
  size = ftell(file);
  rewind(file);

  void* code = malloc(size);
  fread(code, size, 1, file);

  fclose(file);
  return code;
}

int main() {
  char* filename = "overflow.c";
  void* plugin_code = plugin_loader(filename);

  if (plugin_code) {
    printf("Plugin code: \n");
    printf("%s", (char*)plugin_code);
  } else {
    printf("Error loading plugin: %s", filename);
  }

  return 0;
}
