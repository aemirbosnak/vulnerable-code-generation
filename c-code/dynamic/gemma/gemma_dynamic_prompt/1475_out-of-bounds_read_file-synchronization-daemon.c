#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  FILE *file = fopen("/etc/passwd", "r");
  char buffer[1024];
  size_t read_size = fread(buffer, 1, 1024, file);
  buffer[read_size] = '\0';
  printf("%s", buffer);
  fclose(file);
  return 0;
}
