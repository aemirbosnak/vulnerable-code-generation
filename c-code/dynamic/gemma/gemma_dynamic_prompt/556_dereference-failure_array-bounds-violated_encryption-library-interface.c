#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
  int arr[] = {1, 2, 3, 4, 5};
  int i = 0;

  // Attempt to dereference an element beyond the bounds of the array
  arr[i] = 10;

  printf("The value of arr[i] is: %d", arr[i]);

  return 0;
}
