#include <stdlib.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <string.h>

int main() {
  char ip[16];
  scanf("%s", ip);
  int mask = 0;
  int network = 0;
  int host = 0;

  mask = (ip[3] & 0xf0) >> 8;
  network = (ip[0] & 0xff) << 8 | (ip[1] & 0xff) << 16 | (ip[2] & 0xff) << 24;
  host = (ip[3] & 0x0f) << 8 | (ip[2] & 0x0f) << 16 | ip[1] & 0xff;

  printf("Subnet mask: %d\n", mask);
  printf("Network address: %d\n", network);
  printf("Host address: %d\n", host);

  return 0;
}
