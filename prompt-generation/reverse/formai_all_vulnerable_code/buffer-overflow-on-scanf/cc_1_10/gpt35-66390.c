//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert decimal to binary
void decToBin(int n, char binary[]) {
    int i = 0;
    while (n > 0) {
        binary[i] = (n % 2) + '0';
        n /= 2;
        i++;
    }
    binary[i] = '\0';
}

/* Function to calculate the subnet mask from the number of bits 
   allocated for the network portion of the IP address */
void calcSubnetMask(int networkBits, char subnetMask[]) {
    int i;
    int dotCount = 0;  // Keep track of the number of dots to add in the subnet mask
    int pos = 0;  // Keep track of the current position in the subnet mask
    int maskByte = 0;  // Keep track of the value of each byte in the subnet mask
    for (i = 0; i < 32; i++) {
        if (i < networkBits) {
            maskByte = (maskByte << 1) + 1;  // Set the bit to 1
        } else {
            maskByte = maskByte << 1;  // Set the bit to 0
        }
        if ((i+1) % 8 == 0) {
            char byte[9];  // A string to hold the binary representation of each byte of the subnet mask
            decToBin(maskByte, byte);
            if (dotCount > 0) {
                subnetMask[pos] = '.';
                pos++;
            }
            strcat(subnetMask, byte);
            pos += 8;
            dotCount++;
            maskByte = 0;
        }
    }
}

int main() {
    // Initialize variables
    char ip[16];  // A string to hold the IP address
    int networkBits;  // The number of bits allocated for the network portion of the IP address
    char subnetMask[16] = "";  // A string to hold the subnet mask

    // Get user input
    printf("Enter IP address: ");
    scanf("%s", ip);
    printf("Enter number of network bits: ");
    scanf("%d", &networkBits);

    // Calculate the subnet mask
    calcSubnetMask(networkBits, subnetMask);

    // Print the results
    printf("IP address: %s\n", ip);
    printf("Subnet mask: %s\n", subnetMask);

    return 0;
}