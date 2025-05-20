#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

int main() {
  int arr[] = { 1, 2, 3, 4, 5 };
  int* ptr = arr;
  int index = 10;

  *(ptr + index) = 100;

  return 0;
}
