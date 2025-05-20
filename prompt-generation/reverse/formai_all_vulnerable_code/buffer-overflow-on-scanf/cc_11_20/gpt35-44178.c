//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: Sherlock Holmes
/* The Adventure of the Subnet Calculator */

#include <stdio.h>
#include <stdlib.h>

#define MASK_MAX 32 

int main() {
    int netMask[MASK_MAX];
    int subnetMask[MASK_MAX];
    int ipAddr[4];
    int subnetNumber;
    int numBits;
    int i, j;

    printf("Welcome to the Subnet Calculator Game!\n\n");

    /* Get IP Address */
    printf("Please enter IP address in the format x.x.x.x: ");
    scanf("%d.%d.%d.%d", &ipAddr[0], &ipAddr[1], &ipAddr[2], &ipAddr[3]);

    /* Display IP Address */
    printf("\nDetective, you entered the following IP Address:\n");
    printf("%d.%d.%d.%d\n\n", ipAddr[0], ipAddr[1], ipAddr[2], ipAddr[3]);

    /* Get subnet number */
    printf("Please give me the subnet number you need to calculate: ");
    scanf("%d", &subnetNumber);

    numBits = 32 - subnetNumber;

    /* Calculate Netmask */
    for (i = 0; i < 32; i++) {
        if (i < subnetNumber) {
            netMask[i] = 1;
        }
        else {
            netMask[i] = 0;
        }
    }

    /* Calculate Subnet Mask */
    for (i = 0; i < 32; i++) {
        if (i % 8 == 0 && i != 0) {
            printf(".");
        }
        if (i < subnetNumber) {
            subnetMask[i] = 1;
        }
        else {
            subnetMask[i] = 0;
        }
        printf("%d", subnetMask[i]);
    }

    /* Display subnet mask */
    printf("\n\nDetective, the subnet mask for %d is:", subnetNumber);
    for (i = 0; i < 4; i++) {
        int num = 0;
        for (j = 0; j < 8; j++) {
            if (subnetMask[i * 8 + j] == 1) {
                num += 1 << (7-j);
            }
        }
        printf(" %d", num);
    }
    printf("\n\n");

    /* Calculate Network Address */
    unsigned long int networkAddr = 0;
    for (i = 0; i < 32; i++) {
        if (i < subnetNumber) {
            networkAddr += netMask[i] << (31-i);
        }
    }

    /* Display Network Address */
    printf("Detective, you have found the network address\n");
    printf("%lu.%lu.%lu.%lu/%d\n\n", (networkAddr >> 24) & 0xFF, (networkAddr >> 16) & 0xFF, (networkAddr >> 8) & 0xFF, networkAddr & 0xFF, subnetNumber);

    return 0; 
}