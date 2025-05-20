#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *buf = malloc(10);
  buf[0] = 'a';
  free(buf);

  // Use the freed memory
  buf[1] = 'b';
  printf("%s", buf);

  return 0;
}
