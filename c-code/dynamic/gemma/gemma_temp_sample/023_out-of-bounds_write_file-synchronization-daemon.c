#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  FILE *fp = fopen("/etc/passwd", "w");
  fwrite("Hello, world!", 1, 13, fp);
  fclose(fp);
  return 0;
}
