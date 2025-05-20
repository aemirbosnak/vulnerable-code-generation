#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

int main()
{
  int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
  int size = sizeof(arr) / sizeof(int);

  // Accessing an element beyond the bounds of the array
  int element = arr[size - 1];

  // Using the element
  printf("%d", element);

  return 0;
}
