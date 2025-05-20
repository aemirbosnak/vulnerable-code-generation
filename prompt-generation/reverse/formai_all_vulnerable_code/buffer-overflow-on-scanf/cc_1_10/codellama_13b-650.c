//Code Llama-13B DATASET v1.0 Category: Subnet Calculator ; Style: happy
// Subnet Calculator Example Program

#include <stdio.h>

// Function to calculate subnet mask from given IP address
void calculateSubnetMask(char *ipAddress) {
    int i, j;
    int ipAddressInt = 0;
    int subnetMaskInt = 0;
    int ipAddressOctet[4];

    // Convert IP address to integer
    for (i = 0; i < 4; i++) {
        ipAddressOctet[i] = ipAddress[i] - '0';
        ipAddressInt += ipAddressOctet[i] * pow(256, 3 - i);
    }

    // Calculate subnet mask
    for (i = 0; i < 4; i++) {
        if (ipAddressOctet[i] == 255) {
            subnetMaskInt += 255 * pow(256, 3 - i);
        } else if (ipAddressOctet[i] > 223) {
            subnetMaskInt += 224 * pow(256, 3 - i);
        } else if (ipAddressOctet[i] > 191) {
            subnetMaskInt += 192 * pow(256, 3 - i);
        } else if (ipAddressOctet[i] > 127) {
            subnetMaskInt += 128 * pow(256, 3 - i);
        } else if (ipAddressOctet[i] > 63) {
            subnetMaskInt += 64 * pow(256, 3 - i);
        } else if (ipAddressOctet[i] > 31) {
            subnetMaskInt += 32 * pow(256, 3 - i);
        } else if (ipAddressOctet[i] > 15) {
            subnetMaskInt += 16 * pow(256, 3 - i);
        } else if (ipAddressOctet[i] > 7) {
            subnetMaskInt += 8 * pow(256, 3 - i);
        } else if (ipAddressOctet[i] > 3) {
            subnetMaskInt += 4 * pow(256, 3 - i);
        } else if (ipAddressOctet[i] > 1) {
            subnetMaskInt += 2 * pow(256, 3 - i);
        } else if (ipAddressOctet[i] == 1) {
            subnetMaskInt += 1 * pow(256, 3 - i);
        }
    }

    // Print subnet mask
    printf("Subnet Mask: ");
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 8; j++) {
            if ((subnetMaskInt & (1 << (7 - j))) != 0) {
                printf("1");
            } else {
                printf("0");
            }
        }
        subnetMaskInt = subnetMaskInt >> 8;
        if (i < 3) {
            printf(".");
        }
    }
    printf("\n");
}

// Main function
int main() {
    char ipAddress[16];

    // Get IP address from user
    printf("Enter IP address: ");
    scanf("%s", ipAddress);

    // Calculate subnet mask
    calculateSubnetMask(ipAddress);

    return 0;
}