#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int data[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int size = sizeof(data) / sizeof(int);

  // Out-of-bounds read
  int out_of_bounds_index = size + 1;
  int value = data[out_of_bounds_index];

  printf("Value at out-of-bounds index: %d\n", value);

  return 0;
}
