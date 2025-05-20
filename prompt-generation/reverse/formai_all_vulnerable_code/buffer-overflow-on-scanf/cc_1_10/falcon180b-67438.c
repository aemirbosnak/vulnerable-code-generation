//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate the subnet mask
void subnet_mask(char *ip, char *mask) {
    int i, j;
    char *p;
    int num = 0, mask_num = 0;
    char *tokens[4];

    // Split the IP address into four parts
    p = strtok(ip, ".");
    tokens[0] = p;
    p = strtok(NULL, ".");
    tokens[1] = p;
    p = strtok(NULL, ".");
    tokens[2] = p;
    p = strtok(NULL, ".");
    tokens[3] = p;

    // Convert the IP address from string to integer
    for (i = 0; i < 4; i++) {
        num <<= 8;
        num |= atoi(tokens[i]);
    }

    // Calculate the subnet mask
    for (i = 0; i < 4; i++) {
        mask_num <<= 8;
        mask_num |= 0xff;
    }

    // Convert the subnet mask from integer to string
    for (i = 3; i >= 0; i--) {
        sprintf(mask + i * 3, "%d", mask_num >> 24);
        mask_num <<= 8;
    }
}

int main() {
    char ip[16], mask[16];

    // Get the IP address from the user
    printf("Enter the IP address: ");
    scanf("%s", ip);

    // Calculate the subnet mask
    subnet_mask(ip, mask);

    // Print the subnet mask
    printf("Subnet mask: %s\n", mask);

    return 0;
}