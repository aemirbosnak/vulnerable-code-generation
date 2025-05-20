#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  int arr[] = { 1, 2, 3, 4, 5 };
  int index = 10;

  printf("Array element at index %d: ", arr[index]);

  // Deliberate array bounds violation
  arr[index] = 100;

  printf("Updated array element at index %d: ", arr[index]);

  return 0;
}
