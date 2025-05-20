#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char buffer[1024];
  char input[1024];

  printf("Enter the encoded audio stream: ");
  scanf("%s", input);

  // Overflow the buffer
  snprintf(buffer, 1024, "%s", input);

  printf("Decoded audio stream: %s", buffer);

  return 0;
}
