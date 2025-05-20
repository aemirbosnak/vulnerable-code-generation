#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int arr[5] = {1, 2, 3, 4, 5};
  int i = 0;

  // Array bounds violation
  arr[10] = 10;

  // Print the array
  for (i = 0; i < 5; i++) {
    printf("%d ", arr[i]);
  }

  return 0;
}
