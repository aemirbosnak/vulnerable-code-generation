//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: Romeo and Juliet
/* 
  My dearest Juliet,

  I have written this program with the utmost love and care
  that it may assist us in our networking needs.

  Thou mayest input thy IP address and desired subnet mask,
  and this program shall calculate the resulting subnet
  and broadcast addresses for us.

  My heart swells with pride as I present to you, my dearest,
  our very own subnet calculator program.

  Yours forever,
  Romeo
*/

#include <stdio.h>
#include <stdint.h>

int main() {
  uint32_t ip_address, subnet_mask, subnet_address, broadcast_address;
  int i;

  printf("My beloved Juliet, please input our IP address: ");
  scanf("%u", &ip_address);

  printf("And now thy desired subnet mask, my sweet: ");
  scanf("%u", &subnet_mask);

  // Calculate subnet address
  subnet_address = ip_address & subnet_mask;

  // Calculate broadcast address
  broadcast_address = subnet_address | (~subnet_mask);

  // Print out results
  printf("\nAs I have calculated, our subnet address is %u.%u.%u.%u\n",
         (subnet_address >> 24) & 0xFF,
         (subnet_address >> 16) & 0xFF,
         (subnet_address >> 8) & 0xFF,
         subnet_address & 0xFF);
  
  printf("And our broadcast address is %u.%u.%u.%u\n",
         (broadcast_address >> 24) & 0xFF,
         (broadcast_address >> 16) & 0xFF,
         (broadcast_address >> 8) & 0xFF,
         broadcast_address & 0xFF);

  printf("\nForever yours,\nRomeo");

  return 0;
}