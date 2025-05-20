#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char *ptr = NULL;
  int i = 0;

  // Allocate memory for the pointer
  ptr = malloc(10);

  // Attempt to dereference the pointer
  ptr[i] = 'a';

  // Print the value of the pointer
  printf("%c", ptr[i]);

  // Free the memory allocated for the pointer
  free(ptr);

  return 0;
}
