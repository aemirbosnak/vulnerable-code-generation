#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char buffer[1024];

  printf("Enter packet data: ");
  scanf("%s", buffer);

  // Deliberate overflow on fscanf
  scanf("%c", buffer);

  // Print captured packet data
  printf("Packet data: %s", buffer);

  return 0;
}
