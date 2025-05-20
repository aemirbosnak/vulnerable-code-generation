//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Function to check if a given string is a valid IP address
int isValidIP(char *ip) {
    int i, j;
    char *token;

    // Split the IP address into 4 parts
    token = strtok(ip, ".");
    if (token == NULL) {
        return 0; // Invalid IP address
    }

    for (i = 0; i < 4; i++) {
        if ((token = strtok(NULL, ".")) == NULL) {
            return 0; // Invalid IP address
        }

        // Check if each part is a number
        for (j = 0; j < strlen(token); j++) {
            if (!isdigit(token[j])) {
                return 0; // Invalid IP address
            }
        }
    }

    return 1; // Valid IP address
}

// Function to calculate the subnet mask
void calculateSubnetMask(int subnetBits, char *ip, char *mask) {
    int i, j;

    // Copy the IP address to the mask
    strcpy(mask, ip);

    // Set the subnet bits to 1 and the rest to 0
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 8 - subnetBits; j++) {
            mask[i * 8 + j] = '0';
        }
        mask[i * 8 + 7 - subnetBits] = '1';
    }
}

int main() {
    char ip[MAX_SIZE];
    char mask[MAX_SIZE];
    int subnetBits;

    // Get the IP address from the user
    printf("Enter the IP address: ");
    scanf("%s", ip);

    // Check if the IP address is valid
    if (!isValidIP(ip)) {
        printf("Invalid IP address\n");
        return 1;
    }

    // Get the number of subnet bits
    printf("Enter the number of subnet bits: ");
    scanf("%d", &subnetBits);

    // Calculate the subnet mask
    calculateSubnetMask(subnetBits, ip, mask);

    // Print the IP address and subnet mask
    printf("IP address: %s\n", ip);
    printf("Subnet mask: %s\n", mask);

    return 0;
}