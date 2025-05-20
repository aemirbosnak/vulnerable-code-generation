#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main() {
  FILE* file = fopen("/dev/null", "w");
  char buffer[1024] = "This is a string that is longer than the buffer size";
  fwrite(buffer, 1, 1024, file);
  fclose(file);
  return 0;
}
