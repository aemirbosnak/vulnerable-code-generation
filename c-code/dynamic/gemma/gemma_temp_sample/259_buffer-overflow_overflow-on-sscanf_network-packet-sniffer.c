#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>
#include <sys/socket.h>

int main() {
  char buffer[1024];
  char data[1024];

  printf("Enter packet data: ");
  scanf("%s", data);

  // Overflow the buffer
  snprintf(buffer, 1024, "%s", data);

  // Print the sniffed packet
  printf("Packet data: %s", buffer);

  return 0;
}
