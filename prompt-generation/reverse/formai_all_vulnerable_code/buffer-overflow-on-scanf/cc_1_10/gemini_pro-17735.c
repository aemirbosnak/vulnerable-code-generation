//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_IP_LEN 16
#define MAX_MASK_LEN 32
#define MAX_SUBNETS 16

typedef struct {
  unsigned char octets[4];
} ip_addr_t;

typedef struct {
  unsigned char bits;
} subnet_mask_t;

typedef struct {
  ip_addr_t ip_addr;
  subnet_mask_t subnet_mask;
  unsigned int num_subnets;
  ip_addr_t subnet_addresses[MAX_SUBNETS];
  ip_addr_t broadcast_addresses[MAX_SUBNETS];
} subnet_info_t;

// Converts an IP address string to an ip_addr_t struct
int ip_addr_from_str(const char *ip_str, ip_addr_t *ip_addr) {
  int octet_count = 0;
  char *octet_str = strtok((char *)ip_str, ".");
  while (octet_str != NULL && octet_count < 4) {
    ip_addr->octets[octet_count] = atoi(octet_str);
    octet_count++;
    octet_str = strtok(NULL, ".");
  }
  if (octet_count < 4) {
    return -1;
  }
  return 0;
}

// Converts a subnet mask string to a subnet_mask_t struct
int subnet_mask_from_str(const char *mask_str, subnet_mask_t *subnet_mask) {
  int bit_count = 0;
  char *bit_str = strtok((char *)mask_str, ".");
  while (bit_str != NULL && bit_count < 4) {
    subnet_mask->bits += atoi(bit_str) * (8 - bit_count);
    bit_count++;
    bit_str = strtok(NULL, ".");
  }
  if (bit_count < 4) {
    return -1;
  }
  return 0;
}

// Calculates the subnet information for a given IP address and subnet mask
int calculate_subnet_info(subnet_info_t *subnet_info) {
  // Calculate the subnet address
  for (int i = 0; i < 4; i++) {
    subnet_info->subnet_addresses[0].octets[i] = subnet_info->ip_addr.octets[i] & subnet_info->subnet_mask.bits;
  }

  // Calculate the broadcast address
  for (int i = 0; i < 4; i++) {
    subnet_info->broadcast_addresses[0].octets[i] = subnet_info->subnet_addresses[0].octets[i] | ~subnet_info->subnet_mask.bits;
  }

  // Calculate the number of subnets
  subnet_info->num_subnets = pow(2, 32 - subnet_info->subnet_mask.bits);

  // Calculate the remaining subnet addresses and broadcast addresses
  for (int i = 1; i < subnet_info->num_subnets; i++) {
    for (int j = 3; j >= 0; j--) {
      if (subnet_info->subnet_addresses[i - 1].octets[j] == 255) {
        subnet_info->subnet_addresses[i].octets[j] = 0;
        subnet_info->broadcast_addresses[i].octets[j] = 255;
      } else {
        subnet_info->subnet_addresses[i].octets[j] = subnet_info->subnet_addresses[i - 1].octets[j] + 1;
        subnet_info->broadcast_addresses[i].octets[j] = subnet_info->broadcast_addresses[i - 1].octets[j] + 1;
        break;
      }
    }
  }

  return 0;
}

// Prints the subnet information
void print_subnet_info(subnet_info_t *subnet_info) {
  printf("Subnet Information:\n");
  printf("IP Address: %d.%d.%d.%d\n", subnet_info->ip_addr.octets[0], subnet_info->ip_addr.octets[1], subnet_info->ip_addr.octets[2], subnet_info->ip_addr.octets[3]);
  printf("Subnet Mask: %d.%d.%d.%d\n", subnet_info->subnet_mask.bits / 8, (subnet_info->subnet_mask.bits / 4) % 8, (subnet_info->subnet_mask.bits / 2) % 4, subnet_info->subnet_mask.bits % 2);
  printf("Number of Subnets: %d\n", subnet_info->num_subnets);
  printf("Subnet Addresses:\n");
  for (int i = 0; i < subnet_info->num_subnets; i++) {
    printf("%d.%d.%d.%d\n", subnet_info->subnet_addresses[i].octets[0], subnet_info->subnet_addresses[i].octets[1], subnet_info->subnet_addresses[i].octets[2], subnet_info->subnet_addresses[i].octets[3]);
  }
  printf("Broadcast Addresses:\n");
  for (int i = 0; i < subnet_info->num_subnets; i++) {
    printf("%d.%d.%d.%d\n", subnet_info->broadcast_addresses[i].octets[0], subnet_info->broadcast_addresses[i].octets[1], subnet_info->broadcast_addresses[i].octets[2], subnet_info->broadcast_addresses[i].octets[3]);
  }
}

int main() {
  char ip_str[MAX_IP_LEN];
  char mask_str[MAX_MASK_LEN];

  // Get the user input
  printf("Enter the IP address: ");
  scanf("%s", ip_str);
  printf("Enter the subnet mask: ");
  scanf("%s", mask_str);

  // Convert the input to ip_addr_t and subnet_mask_t structs
  ip_addr_t ip_addr;
  subnet_mask_t subnet_mask;
  if (ip_addr_from_str(ip_str, &ip_addr) != 0) {
    printf("Invalid IP address.\n");
    return -1;
  }
  if (subnet_mask_from_str(mask_str, &subnet_mask) != 0) {
    printf("Invalid subnet mask.\n");
    return -1;
  }

  // Calculate the subnet information
  subnet_info_t subnet_info;
  subnet_info.ip_addr = ip_addr;
  subnet_info.subnet_mask = subnet_mask;
  if (calculate_subnet_info(&subnet_info) != 0) {
    printf("Error calculating subnet information.\n");
    return -1;
  }

  // Print the subnet information
  print_subnet_info(&subnet_info);

  return 0;
}