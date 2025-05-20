//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    char ipAddress[20], subnetMask[20];
    int subnetBits, hostBits, subnetOctets[4], subnetMaskOctets[4], networkOctets[4], broadcastOctets[4], maxNumOfSubnets, maxNumOfHosts;
    
    // User input
    printf("Enter IP address: ");
    scanf("%s", ipAddress);
    printf("Enter subnet mask: ");
    scanf("%s", subnetMask);
    printf("\n");

    // Converting subnet mask to binary
    char *ptr;
    int i = 0;
    ptr = strtok(subnetMask, ".");
    while (ptr != NULL) {
        subnetMaskOctets[i++] = atoi(ptr);
        ptr = strtok(NULL, ".");
    }
    int subnetMaskInBinary[32], count = 0;
    for (int i = 0; i < 4; i++) {
        int temp = subnetMaskOctets[i];
        for (int j = 7; j >= 0; j--) {
            if (temp >= pow(2, j)) {
                subnetMaskInBinary[count++] = 1;
                temp -= pow(2, j);
            }
            else {
                subnetMaskInBinary[count++] = 0;
            }
        }
    }

    // Calculating subnet bits and host bits
    subnetBits = 0;
    for (int i = 0; i < 32; i++) {
        if (subnetMaskInBinary[i] == 1) {
            subnetBits++;
        }
        else {
            hostBits++;
        }
    }

    // Converting IP address to binary
    ptr = strtok(ipAddress, ".");
    i = 0;
    while (ptr != NULL) {
        networkOctets[i++] = atoi(ptr) & subnetMaskOctets[i-1];
        ptr = strtok(NULL, ".");
    }
    int networkInBinary[32], broadcastInBinary[32];
    count = 0;
    for (int i = 0; i < 4; i++) {
        int temp = networkOctets[i];
        for (int j = 7; j >= 0; j--) {
            if (temp >= pow(2, j)) {
                networkInBinary[count++] = 1;
                temp -= pow(2, j);
            }
            else {
                networkInBinary[count++] = 0;
            }
        }
    }

    // Calculating broadcast address in binary
    for (int i = 0; i < 32; i++) {
        if (i >= subnetBits) {
            broadcastInBinary[i] = 1;
        }
        else {
            broadcastInBinary[i] = networkInBinary[i];
        }
    }

    // Converting network and broadcast address back to decimal
    for (int i = 0; i < 4; i++) {
        int temp = 0;
        for (int j = 0; j < 8; j++) {
            if (networkInBinary[i*8+j] == 1) {
                temp += pow(2, 7-j);
            }
        }
        networkOctets[i] = temp;
    }
    for (int i = 0; i < 4; i++) {
        int temp = 0;
        for (int j = 0; j < 8; j++) {
            if (broadcastInBinary[i*8+j] == 1) {
                temp += pow(2, 7-j);
            }
        }
        broadcastOctets[i] = temp;
    }

    // Calculating maximum number of subnets and hosts
    maxNumOfSubnets = pow(2, subnetBits);
    maxNumOfHosts = pow(2, hostBits) - 2;

    // Printing results
    printf("Network address: %d.%d.%d.%d\n", networkOctets[0], networkOctets[1], networkOctets[2], networkOctets[3]);
    printf("First valid host address: %d.%d.%d.%d\n", networkOctets[0], networkOctets[1], networkOctets[2], networkOctets[3]+1);
    printf("Last valid host address: %d.%d.%d.%d\n", broadcastOctets[0], broadcastOctets[1], broadcastOctets[2], broadcastOctets[3]-1);
    printf("Broadcast address: %d.%d.%d.%d\n", broadcastOctets[0], broadcastOctets[1], broadcastOctets[2], broadcastOctets[3]);
    printf("Maximum number of subnets: %d\n", maxNumOfSubnets);
    printf("Maximum number of hosts: %d\n", maxNumOfHosts);

    return 0;
}