#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  char ip_addr[16], subnet_mask[16];
  int i, mask_len, broadcast_addr[4];

  if (argc != 3) {
    fprintf(stderr, "Usage: %s <ip_address> <subnet_mask>\n", argv[0]);
    exit(1);
  }

  sprintf(ip_addr, "%s", argv[1]);
  sprintf(subnet_mask, "%s", argv[2]);

  mask_len = atoi(subnet_mask);

  for (i = 0; i < 4; i++) {
    broadcast_addr[i] = (ip_addr[i] & ~((~0 << mask_len) >> i)) | 0xFF;
  }

  printf("Broadcast address: ");
  for (i = 0; i < 4; i++) {
    printf("%d.", broadcast_addr[i]);
  }
  printf("\n");

  return 0;
}
