#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char **arr = NULL;
  arr = malloc(5);
  arr[10] = 'a';

  printf("%c", arr[10]);

  free(arr);
  return 0;
}
