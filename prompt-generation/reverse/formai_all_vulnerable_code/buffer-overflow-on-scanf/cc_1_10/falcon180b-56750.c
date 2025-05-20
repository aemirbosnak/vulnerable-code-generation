//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate subnet mask
void calculate_subnet_mask(int ip[], int subnet_bits) {
    int i, j;
    char mask[16];
    memset(mask, '0', sizeof(mask));

    // Set the first subnet_bits bits to 1
    for (i = 0; i < subnet_bits; i++) {
        mask[i] = '1';
    }

    // Set the remaining bits to 0
    for (i = subnet_bits; i < 32; i++) {
        mask[i] = '0';
    }

    // Convert the mask from string to integer
    for (i = 0, j = 0; i < strlen(mask); i++) {
        if (mask[i] == '1') {
            ip[i] |= (1 << (7 - j));
            j++;
        }
    }
}

// Function to display the subnet information
void display_subnet_info(int ip[], int subnet_bits) {
    int i;
    printf("IP Address: ");
    for (i = 0; i < 4; i++) {
        printf("%d.%d.%d.%d ", ip[i] >> 24, (ip[i] >> 16) & 0xFF, (ip[i] >> 8) & 0xFF, ip[i] & 0xFF);
    }
    printf("\nSubnet Mask: ");
    for (i = 0; i < 4; i++) {
        printf("%d.%d.%d.%d ", (ip[i] >> 24) & 0xFF, (ip[i] >> 16) & 0xFF, (ip[i] >> 8) & 0xFF, ip[i] & 0xFF);
    }
    printf("\nSubnet Bits: %d\n", subnet_bits);
}

int main() {
    int ip[4];
    int subnet_bits;

    printf("Enter the IP Address: ");
    scanf("%d.%d.%d.%d", &ip[0], &ip[1], &ip[2], &ip[3]);

    printf("Enter the subnet bits: ");
    scanf("%d", &subnet_bits);

    calculate_subnet_mask(ip, subnet_bits);
    display_subnet_info(ip, subnet_bits);

    return 0;
}