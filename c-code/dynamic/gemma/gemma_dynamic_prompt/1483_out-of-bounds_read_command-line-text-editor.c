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
  buffer = malloc(size);

  // Read data from the user
  char input[1024];
  printf("Enter text: ");
  fgets(input, 1024, stdin);

  // Write data to the buffer
  strcpy(buffer, input);

  // Print the data from the buffer
  printf("Your text: %s", buffer);

  // Free the memory allocated for the buffer
  free(buffer);

  return 0;
}
