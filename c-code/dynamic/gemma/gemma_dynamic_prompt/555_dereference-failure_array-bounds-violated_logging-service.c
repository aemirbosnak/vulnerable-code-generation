#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int arr[5] = { 1, 2, 3, 4, 5 };
  int index = 10;

  // Attempt to dereference an element beyond the bounds of the array
  printf("%d", arr[index]);

  return 0;
}
