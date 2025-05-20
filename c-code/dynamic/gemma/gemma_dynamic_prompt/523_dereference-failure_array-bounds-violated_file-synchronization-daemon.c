#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int arr[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
  int index = 10;

  // Deliberate array bounds violation
  arr[index] = 100;

  printf("The value at index %d is %d\n", index, arr[index]);

  return 0;
}
