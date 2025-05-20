//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to validate IP address
int isValidIP(char *ip) {
    int i, j;
    char *ptr;
    int parts = 0;

    ptr = strtok(ip, ".");
    while (ptr!= NULL) {
        parts++;
        for (i = 0; i < strlen(ptr); i++) {
            if (!isdigit(ptr[i])) {
                return 0;
            }
        }
        ptr = strtok(NULL, ".");
    }

    if (parts!= 4) {
        return 0;
    }

    return 1;
}

// Function to calculate subnet mask
void calculateSubnetMask(int subnetBits, char *ip, char *mask) {
    int i, j;
    char *ptr;

    ptr = strtok(ip, ".");
    for (i = 0; i < 4; i++) {
        strcat(mask, ptr);
        if (i!= 3) {
            strcat(mask, ".");
        }
        ptr = strtok(NULL, ".");
    }

    for (i = strlen(mask) - 1, j = 0; i >= 0; i--, j++) {
        if (j == subnetBits) {
            mask[i] = '1';
        } else {
            mask[i] = '0';
        }
    }
}

// Function to print usage instructions
void printUsage() {
    printf("Usage:./sherlock <IP Address> <Subnet Bits>\n");
    printf("Example:./sherlock 192.168.0.1 24\n");
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        printUsage();
        exit(1);
    }

    char *ip = argv[1];
    char *subnetBitsStr = argv[3];
    int subnetBits;

    // Validate IP address
    if (!isValidIP(ip)) {
        printf("Invalid IP address.\n");
        exit(1);
    }

    // Convert subnet bits string to integer
    subnetBits = atoi(subnetBitsStr);

    // Calculate subnet mask
    char subnetMask[16];
    calculateSubnetMask(subnetBits, ip, subnetMask);

    // Print results
    printf("IP Address: %s\n", ip);
    printf("Subnet Mask: %s\n", subnetMask);

    return 0;
}