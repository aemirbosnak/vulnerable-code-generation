#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char *buf = malloc(10);
  gets(buf);
  buf[9] = 'a';
  printf("%s", buf);
  free(buf);
  return 0;
}
