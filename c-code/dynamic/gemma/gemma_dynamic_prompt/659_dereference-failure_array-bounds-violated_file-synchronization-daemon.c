#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int arr[5] = {1, 2, 3, 4, 5};
  int idx = 10;

  // Array bounds violation
  arr[idx] = 100;

  printf("Value at arr[%d] is: %d\n", idx, arr[idx]);

  return 0;
}
