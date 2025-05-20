#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <ip_address> <subnet_mask>\n", argv[0]);
    return 1;
  }

  char ip_address[256], subnet_mask[256];
  sscanf(argv[1], "%s", ip_address);
  sscanf(argv[2], "%s", subnet_mask);

  int ip_addr_int, subnet_mask_int;
  ip_addr_int = inet_aton(ip_address, NULL);
  subnet_mask_int = inet_aton(subnet_mask, NULL);

  int broadcast_address = (ip_addr_int & ~subnet_mask_int) | subnet_mask_int - 1;

  char broadcast_address_str[16];
  inet_ntop(broadcast_address, broadcast_address_str, sizeof(broadcast_address_str), NULL);

  printf("Broadcast address: %s\n", broadcast_address_str);

  return 0;
}
