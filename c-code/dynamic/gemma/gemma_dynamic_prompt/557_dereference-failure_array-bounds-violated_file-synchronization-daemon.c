#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int arr[5] = {1, 2, 3, 4, 5};
  int index = 10;

  // Array bounds violation - dereference failure
  int value = arr[index];

  // Print the value
  printf("Value: %d\n", value);

  return 0;
}
