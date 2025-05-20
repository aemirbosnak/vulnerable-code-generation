//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert IP address to binary form
void toBinary(char* ip, int* binary) {
    int i, j, k, n;
    // Split the IP address to four parts
    for (i = 0, k = 0; i < 4; i++) {
        n = 0;
        // Convert each part to integer
        for (j = 0; ip[k] != '.' && ip[k] != '\0'; j++, k++) {
            n = n * 10 + (ip[k] - '0');
        }
        // Store each part in binary form
        for (j = 7; j >= 0; j--) {
            binary[(i * 8) + j] = n % 2;
            n /= 2;
        }
        // Skip to next part
        k++;
    }
}

// Function to convert binary form to integer
int toDecimal(int* binary) {
    int i, n = 0;
    for (i = 0; i < 8; i++) {
        n = n * 2 + binary[i];
    }
    return n;
}

// Function to calculate subnet mask from prefix length
void prefixToMask(int prefix, int* mask) {
    int i;
    for (i = 0; i < 32; i++) {
        if (i < prefix) {
            mask[i] = 1;
        } else {
            mask[i] = 0;
        }
    }
}

int main() {
    char ipString[16];
    int prefix, ipBinary[32], maskBinary[32], subnetBinary[32], i;

    // Read IP address and prefix length from user
    printf("Enter IP address: ");
    scanf("%s", ipString);
    printf("Enter prefix length: ");
    scanf("%d", &prefix);

    // Convert IP address to binary form
    toBinary(ipString, ipBinary);

    // Calculate subnet mask from prefix length
    prefixToMask(prefix, maskBinary);

    // Calculate subnet address
    for (i = 0; i < 32; i++) {
        subnetBinary[i] = ipBinary[i] & maskBinary[i];
    }

    // Print result in decimal form
    printf("Subnet address for %s/%d is: ", ipString, prefix);
    for (i = 0; i < 4; i++) {
        printf("%d.", toDecimal(&subnetBinary[i * 8]));
    }
    printf("\n");

    return 0;
}