#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
  if (argc < 3) {
    fprintf(stderr, "Usage: %s <ip_address> <subnet_mask>\n", argv[0]);
    return 1;
  }

  char *ip_address = argv[1];
  char *subnet_mask = argv[2];

  // Convert subnet mask to integer
  int subnet_mask_int = inet_aton(subnet_mask, NULL);

  // Calculate broadcast address
  int broadcast_address = (subnet_mask_int & ~(-1 << (32 - subnet_mask_int))) | 0x1;

  // Display broadcast address
  printf("Broadcast address: %s\n", inet_ntoa(broadcast_address));

  return 0;
}
