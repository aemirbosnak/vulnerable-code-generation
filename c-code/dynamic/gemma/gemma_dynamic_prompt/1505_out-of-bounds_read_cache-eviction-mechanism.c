#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
  int *arr = (int *)malloc(10 * sizeof(int));
  arr[0] = 10;
  arr[1] = 20;
  arr[2] = 30;
  arr[3] = 40;
  arr[4] = 50;

  int index = 10;
  arr[index] = 60; // Out-of-bounds read

  printf("%d", arr[index]);

  free(arr);
  return 0;
}
