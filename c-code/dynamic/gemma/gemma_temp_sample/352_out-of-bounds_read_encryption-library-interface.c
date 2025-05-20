#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char* data = malloc(10);
  data[10] = 'A';
  printf("%c", data[10]);
  free(data);
  return 0;
}
