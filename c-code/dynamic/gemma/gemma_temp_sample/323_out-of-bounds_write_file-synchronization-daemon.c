#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  FILE *file = fopen("/etc/passwd", "w");
  char buffer[1000] = "Hello, world!";
  fwrite(buffer, 1, 1000, file);
  fclose(file);

  return 0;
}
