//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#define MAX_SUBNETS 256

void printBinaryIP(unsigned char ip[4]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 7; j >= 0; j--) {
            printf("%d", (ip[i] >> j) & 1);
        }
        if (i < 3) {
            printf(".");
        }
    }
    printf("\n");
}

void calculateSubnet(unsigned char ip[4], int subnetMask) {
    unsigned char subnet[4] = {0};
    unsigned char broadcast[4] = {0};
    
    // Calculate the subnet address
    for (int i = 0; i < 4; i++) {
        if (subnetMask < 8) {
            subnet[i] = ip[i] & (255 << (8 - subnetMask));
            subnetMask = 0; // All remaining bits are part of the host address
        } else {
            subnet[i] = ip[i];
            subnetMask -= 8;
        }
    }
    
    // Calculate the broadcast address
    for (int i = 0; i < 4; i++) {
        if (i < (subnetMask / 8)) {
            broadcast[i] = subnet[i];
        } else if (i == (subnetMask / 8)) {
            broadcast[i] = subnet[i] | (255 >> (subnetMask % 8));
        } else {
            broadcast[i] = 255;
        }
    }
    
    printf("Subnet Address: ");
    printBinaryIP(subnet);
    printf("Broadcast Address: ");
    printBinaryIP(broadcast);
}

int main() {
    char input[20];
    unsigned char ip[4];
    int subnetMask;

    printf("Welcome to the C Subnet Calculator.\n");
    printf("Please enter an IP address (e.g., 192.168.1.1): ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0; // Remove the trailing newline
    sscanf(input, "%hhu.%hhu.%hhu.%hhu", &ip[0], &ip[1], &ip[2], &ip[3]);

    printf("Now, enter the subnet mask in CIDR notation (e.g., 24): ");
    fscanf(stdin, "%d", &subnetMask);
    
    if (subnetMask < 0 || subnetMask > 32) {
        printf("Invalid subnet mask! Please enter a value between 0 and 32.\n");
        return 1;
    }

    printf("\nCalculating subnet information...\n");
    calculateSubnet(ip, subnetMask);
    
    printf("\nThank you for using the C Subnet Calculator. Goodbye!\n");
    return 0;
}