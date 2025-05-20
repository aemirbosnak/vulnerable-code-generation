#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char buffer[10];
  printf("Enter a string: ");
  scanf("%s", buffer);

  // Overflow on fscanf
  scanf("%c", buffer);

  printf("Your input: %s", buffer);

  return 0;
}
