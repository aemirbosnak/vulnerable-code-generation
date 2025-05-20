#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char buffer[100];
  scanf("%s", buffer);

  // Overflow the buffer
  buffer[99] = 'a';

  printf("The modified buffer is: %s", buffer);

  return 0;
}
