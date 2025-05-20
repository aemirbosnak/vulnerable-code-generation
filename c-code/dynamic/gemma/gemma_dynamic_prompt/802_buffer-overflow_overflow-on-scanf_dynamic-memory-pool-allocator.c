#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char *buffer = NULL;
  int size = 0;

  printf("Enter the size of the buffer: ");
  scanf("%d", &size);

  buffer = malloc(size);

  if (buffer == NULL) {
    printf("Error allocating memory.\n");
    exit(1);
  }

  printf("Enter data: ");
  scanf("%s", buffer);

  printf("The data is: %s\n", buffer);

  free(buffer);

  return 0;
}
