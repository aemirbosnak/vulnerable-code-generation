#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int index = 11;
  int value = arr[index];

  printf("The value at index %d is: %d\n", index, value);

  return 0;
}
