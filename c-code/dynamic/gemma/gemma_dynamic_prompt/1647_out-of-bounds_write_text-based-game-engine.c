#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
  char *buffer = NULL;
  int size = 0;

  // Allocate memory for the buffer
  buffer = malloc(1024);

  // Get the user input
  printf("Enter a message: ");
  scanf("%s", buffer);

  // Write out of bounds
  buffer[size] = 'A';

  // Free the memory
  free(buffer);

  return 0;
}
