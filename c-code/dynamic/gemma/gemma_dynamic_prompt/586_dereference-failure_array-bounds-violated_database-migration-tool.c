#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int arr[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  int i = 0;
  int value = 10;

  for (i = 0; i < value; i++) {
    printf("%d ", arr[i]);
  }

  return 0;
}
