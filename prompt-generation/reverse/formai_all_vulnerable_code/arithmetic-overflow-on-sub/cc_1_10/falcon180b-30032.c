//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate subnet mask
void calculate_subnet_mask(int num_hosts, int num_bits) {
    int i, j, k;
    char subnet_mask[16];

    // Initialize subnet mask to all 1's
    for (i = 0; i < num_bits; i++) {
        subnet_mask[i] = '1';
    }

    // Calculate subnet mask
    for (i = num_bits - 1; i >= 0; i--) {
        if (num_hosts & (1 << i)) {
            subnet_mask[i] = '0';
        }
    }

    // Add leading zeros if necessary
    for (i = 0; i < num_bits - 1; i++) {
        if (subnet_mask[i] == '1') {
            break;
        }
    }

    for (j = i; j < num_bits; j++) {
        if (subnet_mask[j] == '0') {
            k = j - i;
            while (k > 0) {
                subnet_mask[j - k] = '0';
                k--;
            }
            break;
        }
    }

    // Print subnet mask
    printf("Subnet mask: ");
    for (i = 0; i < num_bits; i++) {
        printf("%c", subnet_mask[i]);
    }
    printf("\n");
}

int main() {
    int num_hosts, num_bits;

    printf("Enter number of hosts: ");
    scanf("%d", &num_hosts);

    printf("Enter number of bits in subnet mask: ");
    scanf("%d", &num_bits);

    calculate_subnet_mask(num_hosts, num_bits);

    return 0;
}