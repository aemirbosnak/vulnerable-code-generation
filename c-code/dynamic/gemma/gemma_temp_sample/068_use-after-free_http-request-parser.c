#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *buffer = NULL;
  int size = 0;

  // Read the request body
  buffer = malloc(1024);
  size = read(0, buffer, 1024);

  // Print the request body
  printf("Request body:\n");
  printf("%s", buffer);

  free(buffer);

  return 0;
}
