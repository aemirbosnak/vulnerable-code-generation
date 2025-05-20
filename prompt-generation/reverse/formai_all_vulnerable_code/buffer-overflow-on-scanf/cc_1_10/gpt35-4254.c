//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char ip[20], subnetMask[20];
    int i, j, k, num, octets[4];
    int subnetMaskBits, subnetMaskOctets[4];
    char subnetIP[20];

    printf("Enter the IP address: ");
    scanf("%s", ip);
    
    printf("Enter the Subnet Mask: ");
    scanf("%s", subnetMask);
    
    // Splitting the IP into octets
    char* token = strtok(ip, ".");
    for (i = 0; i < 4; i++) {
        octets[i] = atoi(token);
        token = strtok(NULL, ".");
    }

    // Splitting the Subnet Mask into octets
    token = strtok(subnetMask, ".");
    for (i = 0; i < 4; i++) {
        subnetMaskOctets[i] = atoi(token);
        token = strtok(NULL, ".");
    }

    // Calculate subnet mask bits
    for (i = 0; i < 4; i++) {
        num = subnetMaskOctets[i];
        if (num == 255) {
            subnetMaskBits += 8;
        } else {
            for (j = 7; j >= 0; j--) {
                if (num & (1 << j)) {
                    subnetMaskBits++;
                    subnetMaskOctets[i] &= ~(1 << j);
                } else {
                    break;
                }
            }
        }
    }

    // Calculating Subnet IP
    for (i = 0; i < 4; i++) {
        subnetIP[i] = octets[i] & subnetMaskOctets[i];
    }

    printf("The IP address %s with subnet mask %s is\n", ip, subnetMask);
    printf("Subnet IP: %s\n", subnetIP);
    printf("Number of subnet mask bits: %d\n", subnetMaskBits);

    return 0;
}