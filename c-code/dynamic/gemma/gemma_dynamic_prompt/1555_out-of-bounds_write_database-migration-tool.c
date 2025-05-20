#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE* file = fopen("database.txt", "w");
  char buffer[1024] = "Hello, world!";
  fwrite(buffer, 1, 1024, file);
  fclose(file);

  return 0;
}
