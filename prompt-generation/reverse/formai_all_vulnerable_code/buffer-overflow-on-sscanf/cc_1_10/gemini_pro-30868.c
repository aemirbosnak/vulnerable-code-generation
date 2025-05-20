//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#define MAX_MASK_BITS 32
#define MAX_IP_ADDR_LEN 16

typedef struct {
  unsigned char octets[4];
} ip_addr_t;

typedef struct {
  unsigned char mask;
  unsigned int prefix_len;
} subnet_mask_t;

void print_ip_addr(ip_addr_t addr) {
  printf("%d.%d.%d.%d", addr.octets[0], addr.octets[1], addr.octets[2], addr.octets[3]);
}

void print_subnet_mask(subnet_mask_t mask) {
  printf("%d/%d", mask.mask, mask.prefix_len);
}

int parse_ip_addr(char *str, ip_addr_t *addr) {
  int octets[4];
  if (sscanf(str, "%d.%d.%d.%d", &octets[0], &octets[1], &octets[2], &octets[3]) != 4) {
    return -1;
  }
  for (int i = 0; i < 4; i++) {
    if (octets[i] < 0 || octets[i] > 255) {
      return -1;
    }
    addr->octets[i] = octets[i];
  }
  return 0;
}

int parse_subnet_mask(char *str, subnet_mask_t *mask) {
  int prefix_len;
  if (sscanf(str, "%d/%d", &mask->mask, &prefix_len) != 2) {
    return -1;
  }
  if (mask->mask < 0 || mask->mask > MAX_MASK_BITS) {
    return -1;
  }
  if (prefix_len < 0 || prefix_len > MAX_MASK_BITS) {
    return -1;
  }
  mask->prefix_len = prefix_len;
  return 0;
}

void subnet_calc(ip_addr_t addr, subnet_mask_t mask, unsigned char **subnets, 
size_t * num_subnets) {
  unsigned char subnet_mask = mask.mask;
  size_t prefix_len = mask.prefix_len;
  size_t num_bits_to_subnet = MAX_MASK_BITS - prefix_len;
  *num_subnets = 1 << num_bits_to_subnet;
  *subnets = malloc(*num_subnets * MAX_IP_ADDR_LEN);
  for (size_t i = 0; i < *num_subnets; i++) {
    unsigned char *subnet = *subnets + i * MAX_IP_ADDR_LEN;
    memcpy(subnet, addr.octets, sizeof(addr.octets));
    for (size_t j = prefix_len / 8; j < 4; j++) {
      subnet[j] &= subnet_mask;
      subnet_mask >>= 8;
    }
  }
}

void print_subnets(unsigned char **subnets, size_t num_subnets) {
  for (size_t i = 0; i < num_subnets; i++) {
    ip_addr_t subnet;
    memcpy(subnet.octets, subnets[i], sizeof(subnet.octets));
    print_ip_addr(subnet);
    printf(" ");
  }
  printf("\n");
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <ip_address> <subnet_mask>\n", argv[0]);
    return EXIT_FAILURE;
  }

  ip_addr_t addr;
  if (parse_ip_addr(argv[1], &addr) != 0) {
    fprintf(stderr, "Invalid IP address: %s\n", argv[1]);
    return EXIT_FAILURE;
  }

  subnet_mask_t mask;
  if (parse_subnet_mask(argv[2], &mask) != 0) {
    fprintf(stderr, "Invalid subnet mask: %s\n", argv[2]);
    return EXIT_FAILURE;
  }

  unsigned char **subnets;
  size_t num_subnets;
  subnet_calc(addr, mask, &subnets, &num_subnets);

  printf("Subnets:\n");
  print_subnets(subnets, num_subnets);

  free(subnets);
  return EXIT_SUCCESS;
}