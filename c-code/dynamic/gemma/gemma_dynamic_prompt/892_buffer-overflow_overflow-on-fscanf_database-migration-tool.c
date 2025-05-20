#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char buffer[10];
  fscanf(stdin, "%s", buffer);

  // Overflow the buffer
  snprintf(buffer, 20, "This string is too long to fit into the buffer");

  printf("The modified string is: %s", buffer);

  return 0;
}
