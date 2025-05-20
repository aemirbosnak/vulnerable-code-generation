//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: post-apocalyptic
#include <stdio.h>

int main() {
  printf("\t\tWelcome to the Subnet Calculator\n\n");
  
  // Gathering inputs from user
  int octet1, octet2, octet3, octet4, subnet_bits;
  printf("Enter the IP address octets (separated by spaces): ");
  scanf("%d %d %d %d", &octet1, &octet2, &octet3, &octet4);
  printf("Enter the number of subnet bits: ");
  scanf("%d", &subnet_bits);
  
  // Validating inputs
  if (octet1 < 0 || octet1 > 255 || octet2 < 0 || octet2 > 255 || octet3 < 0 || octet3 > 255 || octet4 < 0 || octet4 > 255) {
    printf("\nERROR: Invalid IP address input.\n");
    return 0;
  }
  if (subnet_bits < 0 || subnet_bits > 32) {
    printf("\nERROR: Invalid subnet bits input (must be between 0 and 32).\n");
    return 0;
  }
  
  // Calculating subnet mask
  int mask_octet1, mask_octet2, mask_octet3, mask_octet4;
  int bits_left = subnet_bits;
  
  if (bits_left >= 8) {
    mask_octet1 = 255;
    bits_left -= 8;
  }
  else {
    mask_octet1 = (1 << bits_left) - 1;
    bits_left = 0;
  }
  
  if (bits_left >= 8) {
    mask_octet2 = 255;
    bits_left -= 8;
  }
  else {
    mask_octet2 = (1 << bits_left) - 1;
    bits_left = 0;
  }
  
  if (bits_left >= 8) {
    mask_octet3 = 255;
    bits_left -= 8;
  }
  else {
    mask_octet3 = (1 << bits_left) - 1;
    bits_left = 0;
  }
  
  mask_octet4 = (1 << bits_left) - 1;
  mask_octet4 <<= 8 - subnet_bits % 8;
  
  // Calculating network address
  int network_octet1 = octet1 & mask_octet1;
  int network_octet2 = octet2 & mask_octet2;
  int network_octet3 = octet3 & mask_octet3;
  int network_octet4 = octet4 & mask_octet4;
  
  // Printing output
  printf("\nSubnet Mask: %d.%d.%d.%d\n", mask_octet1, mask_octet2, mask_octet3, mask_octet4);
  printf("Network Address: %d.%d.%d.%d\n\n", network_octet1, network_octet2, network_octet3, network_octet4);
  
  return 0;
}