#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char *buffer = NULL;
  int size = 0;

  scanf("Enter the size of the memory pool: ", &size);

  buffer = (char *)malloc(size);

  printf("The memory pool has been allocated.\n");

  free(buffer);

  return 0;
}
