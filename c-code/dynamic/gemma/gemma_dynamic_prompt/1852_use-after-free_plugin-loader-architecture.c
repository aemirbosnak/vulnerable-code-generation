#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>
#include <stdio.h>

void* plugin_loader(char* name) {
  FILE* file = fopen(name, "r");
  if (file == NULL) {
    return NULL;
  }

  size_t size = 0;
  char* data = NULL;
  fseek(file, 0L, SEEK_END);
  size_t file_size = ftell(file);
  rewind(file);

  data = malloc(file_size);
  if (data == NULL) {
    fclose(file);
    return NULL;
  }

  fread(data, file_size, 1, file);
  fclose(file);

  return data;
}

int main() {
  void* plugin = plugin_loader("foo.txt");
  if (plugin == NULL) {
    return 1;
  }

  // Use after free vulnerability
  free(plugin);

  return 0;
}
