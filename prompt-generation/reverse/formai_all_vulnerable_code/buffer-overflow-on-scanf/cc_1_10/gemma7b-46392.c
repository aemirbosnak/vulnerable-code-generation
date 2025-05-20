//Gemma-7B DATASET v1.0 Category: Subnet Calculator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

// Define a function to calculate the subnet mask
int subnet_mask(int cidr) {
  int mask = 0;
  switch (cidr) {
    case 0:
      mask = 0;
      break;
    case 1:
      mask = 254;
      break;
    case 2:
      mask = 252;
      break;
    case 3:
      mask = 250;
      break;
    case 4:
      mask = 248;
      break;
    case 5:
      mask = 246;
      break;
    case 6:
      mask = 244;
      break;
    case 7:
      mask = 242;
      break;
    case 8:
      mask = 240;
      break;
    case 9:
      mask = 238;
      break;
    case 10:
      mask = 236;
      break;
    case 11:
      mask = 234;
      break;
    case 12:
      mask = 232;
      break;
    case 13:
      mask = 230;
      break;
    case 14:
      mask = 228;
      break;
    case 15:
      mask = 226;
      break;
    default:
      mask = -1;
  }
  return mask;
}

int main() {
  int cidr;
  printf("Enter the CIDR subnet mask: ");
  scanf("%d", &cidr);

  int mask = subnet_mask(cidr);

  if (mask != -1) {
    printf("The subnet mask is: ");
    printf("%d", mask);
  } else {
    printf("Error: invalid CIDR subnet mask.");
  }

  return 0;
}