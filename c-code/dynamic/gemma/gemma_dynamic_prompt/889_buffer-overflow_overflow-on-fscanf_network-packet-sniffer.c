#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char buffer[1024];
  char packet_data[1024];

  printf("Enter packet data: ");
  scanf("%s", packet_data);

  // Overflow the buffer
  sprintf(buffer, "AAAAABBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB%s", packet_data);

  // Print the packet data
  printf("Packet data: %s", buffer);

  return 0;
}
