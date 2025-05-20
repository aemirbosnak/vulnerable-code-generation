#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char buffer[1024];
  int size = 0;

  printf("Enter the size of the data: ");
  scanf("%d", &size);

  if (size > 1024) {
    printf("Error: the size of the data is too large.\n");
    exit(1);
  }

  printf("Enter the data: ");
  scanf("%s", buffer);

  // Overflow the buffer
  buffer[size] = '\0';

  printf("The data is: %s\n", buffer);

  return 0;
}
