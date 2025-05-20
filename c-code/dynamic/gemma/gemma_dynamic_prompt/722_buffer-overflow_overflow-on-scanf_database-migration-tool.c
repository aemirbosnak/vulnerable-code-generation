#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>

int main() {
  char buffer[10];
  scanf("%s", buffer);

  // Overflow on scanf
  buffer[9] = 'a';
  buffer[10] = 'b';

  printf("The modified buffer is: %s", buffer);

  return 0;
}
