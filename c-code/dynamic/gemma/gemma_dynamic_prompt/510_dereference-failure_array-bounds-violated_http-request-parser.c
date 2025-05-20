#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
  char *arr[] = {"abc", "def", "ghi"};
  int i = 5;

  // Attempt to dereference an element beyond the bounds of the array
  arr[i] = "hello";

  printf("%s", arr[i]);

  return 0;
}
