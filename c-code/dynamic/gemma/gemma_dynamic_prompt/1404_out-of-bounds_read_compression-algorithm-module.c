#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE* file = fopen("file.txt", "r");
  if (file == NULL) {
    return 1;
  }

  int size = 0;
  char* data = NULL;
  size_t read_size = 0;

  while ((read_size = fread(data, 1, 1024, file)) > 0) {
    data = realloc(data, size + read_size);
    size += read_size;
  }

  fclose(file);

  return 0;
}
