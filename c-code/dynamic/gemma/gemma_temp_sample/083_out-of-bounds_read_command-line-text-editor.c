#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char buffer[1024];
  FILE *file = fopen("text.txt", "r");
  size_t size = fread(buffer, 1, 1024, file);
  buffer[size - 1] = '\0';
  printf("%s", buffer);
  fclose(file);
  return 0;
}
