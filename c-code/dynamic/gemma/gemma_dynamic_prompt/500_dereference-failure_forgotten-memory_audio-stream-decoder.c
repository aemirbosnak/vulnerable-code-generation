#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
  int *ptr = NULL;
  int i = 0;

  // Allocate memory for the pointer
  ptr = malloc(10);

  // Attempt to dereference the pointer
  *ptr = 5;

  // Print the value of the pointer
  printf("%d", *ptr);

  // Free the memory
  free(ptr);

  return 0;
}
