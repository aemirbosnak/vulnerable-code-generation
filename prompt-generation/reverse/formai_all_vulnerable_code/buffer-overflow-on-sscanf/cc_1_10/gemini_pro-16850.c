//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IP_ADDR_LEN 16
#define MAX_SUBNET_MASK_LEN 16

struct ip_addr {
  unsigned char octet[4];
};

struct subnet_mask {
  unsigned char octet[4];
};

struct ip_subnet {
  struct ip_addr ip_addr;
  struct subnet_mask subnet_mask;
  unsigned int prefix_len;
};

void print_ip_addr(struct ip_addr *ip_addr) {
  printf("%d.%d.%d.%d\n", ip_addr->octet[0], ip_addr->octet[1],
         ip_addr->octet[2], ip_addr->octet[3]);
}

void print_subnet_mask(struct subnet_mask *subnet_mask) {
  printf("%d.%d.%d.%d\n", subnet_mask->octet[0], subnet_mask->octet[1],
         subnet_mask->octet[2], subnet_mask->octet[3]);
}

void print_ip_subnet(struct ip_subnet *ip_subnet) {
  print_ip_addr(&ip_subnet->ip_addr);
  print_subnet_mask(&ip_subnet->subnet_mask);
  printf("%u\n", ip_subnet->prefix_len);
}

int main(int argc, char **argv) {
  if (argc != 4) {
    fprintf(stderr, "Usage: %s <ip_addr> <subnet_mask> <prefix_len>\n",
            argv[0]);
    return EXIT_FAILURE;
  }

  struct ip_addr ip_addr;
  if (sscanf(argv[1], "%hhu.%hhu.%hhu.%hhu", &ip_addr.octet[0],
             &ip_addr.octet[1], &ip_addr.octet[2], &ip_addr.octet[3]) != 4) {
    fprintf(stderr, "Invalid IP address: %s\n", argv[1]);
    return EXIT_FAILURE;
  }

  struct subnet_mask subnet_mask;
  if (sscanf(argv[2], "%hhu.%hhu.%hhu.%hhu", &subnet_mask.octet[0],
             &subnet_mask.octet[1], &subnet_mask.octet[2],
             &subnet_mask.octet[3]) != 4) {
    fprintf(stderr, "Invalid subnet mask: %s\n", argv[2]);
    return EXIT_FAILURE;
  }

  unsigned int prefix_len;
  if (sscanf(argv[3], "%u", &prefix_len) != 1) {
    fprintf(stderr, "Invalid prefix length: %s\n", argv[3]);
    return EXIT_FAILURE;
  }

  struct ip_subnet ip_subnet;
  ip_subnet.ip_addr = ip_addr;
  ip_subnet.subnet_mask = subnet_mask;
  ip_subnet.prefix_len = prefix_len;

  print_ip_subnet(&ip_subnet);

  return EXIT_SUCCESS;
}