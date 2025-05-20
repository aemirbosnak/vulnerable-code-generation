#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char buffer[10];
  scanf("%s", buffer);

  // Overflow on scanf
  buffer[9] = 'A';

  printf("You entered: %s", buffer);

  return 0;
}
