#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdlib.h>
#include <stdio.h>

int main() {
  int i = 0;
  int *arr = NULL;
  arr = malloc(sizeof(int) * 100);
  for (i = 0; i < 100; i++) {
    arr[i] = i;
  }
  free(arr);
  return 0;
}
