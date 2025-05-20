#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int *arr = NULL;
  arr = malloc(10);
  free(arr);
  printf("%p", arr);
  *arr = 5;
  return 0;
}
