//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate the subnet mask
void calculate_subnet_mask(int network_address, int subnet_mask) {
    int i, j, k;
    char subnet[16];

    // Initialize the subnet mask with all 1's
    for (i = 0; i < subnet_mask; i++) {
        subnet[i] = '1';
    }

    // Calculate the subnet mask
    for (i = 0; i < 32; i++) {
        if ((network_address & (1 << i)) == 0) {
            for (j = 0; j < subnet_mask - 1; j++) {
                if (subnet[j] == '1') {
                    subnet[j] = '0';
                }
            }
            break;
        }
    }

    // Print the subnet mask
    printf("Subnet mask: ");
    for (k = 0; k < subnet_mask; k++) {
        printf("%c", subnet[k]);
    }
    printf("\n");
}

int main() {
    int network_address, subnet_mask;

    // Get the network address from the user
    printf("Enter the network address: ");
    scanf("%d", &network_address);

    // Get the subnet mask from the user
    printf("Enter the subnet mask: ");
    scanf("%d", &subnet_mask);

    // Calculate the subnet mask
    calculate_subnet_mask(network_address, subnet_mask);

    return 0;
}