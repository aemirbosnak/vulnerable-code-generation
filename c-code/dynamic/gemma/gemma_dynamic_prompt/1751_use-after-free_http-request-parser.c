#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main()
{
  char *buffer = NULL;
  int length = 0;

  // Read the request body
  buffer = malloc(1024);
  length = read(0, buffer, 1024);

  // Print the request body
  printf("Request body:\n");
  printf("%s", buffer);

  free(buffer);

  return 0;
}
