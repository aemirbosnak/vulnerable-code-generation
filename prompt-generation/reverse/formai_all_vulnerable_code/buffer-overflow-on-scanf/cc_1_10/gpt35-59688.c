//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: Donald Knuth
/* SUBNET CALCULATOR USING BITWISE OPERATORS, DONALD KNUTH STYLE */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert IP address to binary format
void ipToBinary(char ipAddress[], int *address) {

    int i = 0, j = 0, k = 0, num = 0;

    // Iterate over each octet of the IP address
    for (i = 0; i < 4; i++) {
        char octet[4];
        j = 0;
        // Get each digit of the octet
        while (ipAddress[k] != '.' && ipAddress[k] != '\0') {
            octet[j++] = ipAddress[k++];
        }
        octet[j] = '\0';
        k++;

        // Convert the octet to binary
        num = atoi(octet);
        for (j = 7; j >= 0; j--) {
            address[(i*8) + j] = num % 2;
            num /= 2;
        }

    }
}

// Function to convert binary format to IP address
void binaryToIp(int *binaryAddress, char ipAddress[]) {

    int i, j, num, k = 0;

    // Iterate over each octet of the IP address
    for (i = 0; i < 4; i++) {
        num = 0;
        // Convert each bit of the octet to decimal
        for (j = 7; j >= 0; j--) {
            if (binaryAddress[(i*8) + j] == 1) {
                num += 1 << (7-j);
            }
        }
        // Print the decimal value of the octet
        sprintf(&ipAddress[k], "%d", num);
        k += strlen(&ipAddress[k]);
        ipAddress[k] = '.';
        k++;
    }
    // Remove trailing '.' at the end of the IP address
    ipAddress[k-1] = '\0';

}

int main() {
    char ipAddress[20];
    int maskBits, i = 0, j = 0;
    printf("Enter IP Address: ");
    scanf("%s", ipAddress);
    int binaryAddress[32];
    ipToBinary(ipAddress, binaryAddress);
    printf("Enter Mask Bits: ");
    scanf("%d", &maskBits);
    printf("IP Address in Binary: ");
    for (i = 0; i < 32; i++) {
        printf("%d", binaryAddress[i]);
    }
    printf("\n");
    // Create the subnet mask based on the number of mask bits
    int subnetMask[32];
    for (i = 0; i < 32; i++) {
        if (i < maskBits) {
            subnetMask[i] = 1;
        } else {
            subnetMask[i] = 0;
        }
    }
    printf("Subnet Mask in Binary: ");
    for (i = 0; i < 32; i++) {
        printf("%d", subnetMask[i]);
    }
    printf("\n");
    // Calculate the network address by performing a bitwise AND operation between the IP address and the subnet mask
    int networkAddress[32];
    for (i = 0; i < 32; i++) {
        networkAddress[i] = binaryAddress[i] & subnetMask[i];
    }
    char networkAddressIp[20];
    binaryToIp(networkAddress, networkAddressIp);
    printf("Network Address: %s\n", networkAddressIp);
    // Calculate the broadcast address by performing a bitwise OR operation between the network address and the inverse of the subnet mask
    int broadcastAddress[32];
    for (i = 0; i < 32; i++) {
        broadcastAddress[i] = networkAddress[i] | (subnetMask[i] ^ 1);
    }
    char broadcastAddressIp[20];
    binaryToIp(broadcastAddress, broadcastAddressIp);
    printf("Broadcast Address: %s\n", broadcastAddressIp);
    return 0;
}