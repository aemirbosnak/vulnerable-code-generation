#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  // Allocate memory for a string
  char *str = malloc(10);

  // Use the memory after free
  free(str);
  str[0] = 'A';

  // Print the string
  printf("%s", str);

  return 0;
}
