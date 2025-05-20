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

  char ip_address[16], subnet_mask[16];
  sscanf(argv[1], "%s", ip_address);
  sscanf(argv[2], "%s", subnet_mask);

  unsigned long ip_addr, subnet_mask_int;
  if (inet_aton(ip_address, &ip_addr) == -1) {
    fprintf(stderr, "Error parsing IP address: %s\n", ip_address);
    return 1;
  }
  if (inet_aton(subnet_mask, &subnet_mask_int) == -1) {
    fprintf(stderr, "Error parsing subnet mask: %s\n", subnet_mask);
    return 1;
  }

  unsigned long broadcast_addr = ip_addr | ~subnet_mask_int;
  printf("Broadcast address: %s\n", inet_ntoa(broadcast_addr));

  return 0;
}
