#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

int main()
{
  int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  arr[20] = 11; // Out-of-bounds write
  printf("%d", arr[20]); // May result in undefined behavior
}
