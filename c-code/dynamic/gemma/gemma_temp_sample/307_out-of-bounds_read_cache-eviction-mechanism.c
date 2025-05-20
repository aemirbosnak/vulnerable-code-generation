#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char *arr = (char *)malloc(10);
  arr[0] = 'a';
  arr[1] = 'b';
  arr[2] = 'c';
  arr[3] = 'd';

  // Out-of-bounds read vulnerability
  int index = 10;
  printf("%c", arr[index]);

  free(arr);
  return 0;
}
