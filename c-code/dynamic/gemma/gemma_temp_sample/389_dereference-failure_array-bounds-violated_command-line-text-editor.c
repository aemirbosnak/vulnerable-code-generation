#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

int main() {
  char **arr = NULL;
  int i = 0;

  arr = malloc(10);
  arr[0] = 'a';
  arr[1] = 'b';
  arr[2] = 'c';
  arr[3] = 'd';
  arr[4] = 'e';

  arr[i] = 'f';

  free(arr);
  return 0;
}
