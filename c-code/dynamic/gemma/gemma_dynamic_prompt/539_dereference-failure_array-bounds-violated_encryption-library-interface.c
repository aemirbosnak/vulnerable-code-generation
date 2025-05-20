#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int arr[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  int index = 10;
  int value = arr[index];

  printf("Value at index %d: %d", index, value);

  return 0;
}
