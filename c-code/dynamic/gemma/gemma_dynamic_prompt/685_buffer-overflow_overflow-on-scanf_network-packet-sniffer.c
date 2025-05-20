#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char buffer[1024];
  printf("Enter a packet dump: ");
  scanf("%s", buffer);

  // Overflow the buffer
  buffer[1024 - 1] = '\x0a';

  // Print the sniffer's output
  printf("Sniffed packet:\n%s", buffer);

  return 0;
}
