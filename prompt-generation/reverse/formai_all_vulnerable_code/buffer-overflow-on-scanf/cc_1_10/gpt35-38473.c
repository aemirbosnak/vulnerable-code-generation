//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: complete
#include <stdio.h>
#include <stdlib.h>

unsigned char get_subnet_from_mask(int mask);
unsigned char get_subnet_bit(int octet, int subnet);

int main() {
  unsigned int ip, mask, subnet_mask;
  unsigned char subnet_bits;

  // Get IP address
  printf("Enter IP address (in decimal format): ");
  scanf("%u", &ip);

  // Get mask as number of bits
  printf("Enter mask (as number of bits): ");
  scanf("%u", &mask);

  // Calculate subnet mask as integer
  subnet_mask = (~0) << (32 - mask);

  // Get subnet bits from subnet mask
  subnet_bits = get_subnet_from_mask(mask);

  // Print subnet mask and subnet bits
  printf("Subnet mask: %u.%u.%u.%u\n", 
         (subnet_mask >> 24) & 0xFF, 
         (subnet_mask >> 16) & 0xFF, 
         (subnet_mask >> 8) & 0xFF, 
         subnet_mask & 0xFF);
  printf("Subnet bits: %u\n", subnet_bits);

  // Calculate and print network address
  printf("Network address: %u.%u.%u.%u\n", 
         (ip & subnet_mask >> 24) & 0xFF, 
         (ip & subnet_mask >> 16) & 0xFF, 
         (ip & subnet_mask >> 8) & 0xFF, 
         ip & subnet_mask & 0xFF);

  // Calculate and print broadcast address
  printf("Broadcast address: %u.%u.%u.%u\n", 
         (ip & subnet_mask >> 24) & 0xFF | ~((1 << (32 - mask)) - 1) >> 24 & 0xFF, 
         (ip & subnet_mask >> 16) & 0xFF | ~((1 << (32 - mask)) - 1) >> 16 & 0xFF, 
         (ip & subnet_mask >> 8) & 0xFF | ~((1 << (32 - mask)) - 1) >> 8 & 0xFF, 
         ip & subnet_mask | ~((1 << (32 - mask)) - 1) & 0xFF);

  return 0;
}

// Returns number of subnet bits from mask
unsigned char get_subnet_from_mask(int mask) {
  int subnet_bits = 0;
  for (int i = 0; i < 4; i++) {
    subnet_bits += get_subnet_bit(0, mask - i * 8);
  }
  return subnet_bits;
}

// Returns subnet bit of octet at specified subnet position
unsigned char get_subnet_bit(int octet, int subnet) {
  return ((octet >> (8 - subnet)) & 1) ? 1 : 0;
}