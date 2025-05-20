#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

int main() {
  int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
  int n = sizeof(arr) / sizeof(int);

  // Out-of-bounds write
  arr[n] = 11;

  return 0;
}
