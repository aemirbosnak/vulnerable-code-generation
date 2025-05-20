//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

int main() {
  int octets[4];
  int mask;

  printf("Enter IP address octets (separated by periods)\n");
  scanf("%d.%d.%d.%d", &octets[0], &octets[1], &octets[2], &octets[3]);

  printf("Enter subnet mask in bits\n");
  scanf("%d", &mask);

  printf("---------------------\n");
  printf("|   S U R R E A L   |\n");
  printf("---------------------\n");

  printf("\n");

  printf("IP Address: %d.%d.%d.%d\n", octets[0], octets[1], octets[2], octets[3]);
  printf("Subnet Mask: %d\n", mask);

  printf("\n");

  if (octets[0] < 128) {
    printf("The first octet is in Wonderland.\n");
  } else if (octets[0] > 128 && octets[0] < 192) {
    printf("The first octet is in the Upside Down\n");
  } else if (octets[0] > 192 && octets[0] < 224) {
    printf("The first octet is in Oz.\n");
  } else {
    printf("The first octet is in Narnia.\n");
  }

  printf("\n");

  if (mask == 24) {
    printf("Your subnet is a mirror labyrinth.\n");
  } else if (mask == 16) {
    printf("Your subnet is a floating island.\n");
  } else if (mask == 8) {
    printf("Your subnet is a room made of chocolate.\n");
  } else {
    printf("Your subnet is a quantum leap into the unknown.\n");
  }

  printf("\n");

  int cidr = 0;

  for (int i = 0; i < 4; i++) {
    int bits = 0;

    for (int j = 7; j >= 0; j--) {
      if (octets[i] & (1 << j)) {
        bits++;
      }
    }

    cidr += bits;
  }

  printf("CIDR notation: /%d\n", cidr);

  printf("\n");

  printf("Mask in dotted decimal notation: %d.%d.%d.%d\n",
         ((unsigned int)(-1) << (32 - mask)) & 0xFF, ((unsigned int)(-1) << (32 - mask)) >> 8 & 0xFF,
         ((unsigned int)(-1) << (32 - mask)) >> 16 & 0xFF, ((unsigned int)(-1) << (32 - mask)) >> 24 & 0xFF);

  return 0;
}