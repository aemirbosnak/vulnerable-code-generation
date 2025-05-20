#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *buffer = malloc(10);
  printf("Enter HTTP request: ");
  scanf("%s", buffer);

  free(buffer);
  buffer = NULL;

  printf("You entered: %s", buffer); // Use after free vulnerability

  return 0;
}
