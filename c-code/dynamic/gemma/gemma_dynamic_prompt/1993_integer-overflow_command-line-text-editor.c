#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main()
{
  char *buffer = malloc(1024);
  int size = 0;

  // Get the command-line input
  printf("Enter text: ");
  getline(buffer, &size, 1024);

  // Overflow the buffer
  size = size * 2;
  buffer = realloc(buffer, size);
  memset(buffer + size - 1, 0, size - 1);

  // Print the edited text
  printf("Edited text: \n");
  printf("%s", buffer);

  free(buffer);
  return 0;
}
