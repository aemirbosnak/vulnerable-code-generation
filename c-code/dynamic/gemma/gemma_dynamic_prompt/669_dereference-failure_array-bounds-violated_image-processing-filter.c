#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  int arr[] = {1, 2, 3, 4, 5};
  int* ptr = arr;
  ptr[5] = 10;
  printf("%d", arr[5]);
  return 0;
}
