//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: shape shifting
#include <stdio.h>
#include <string.h>

int main() {
    int ip[4]; // to store user input IP address
    int subnet[4]; // to store user input Subnet mask
    int i, j, k, l;
    int maskbit; // to calculate Mask Bits
    int temp;   // to store shifting bits in Mask Bits calculation
    int power[] = {128, 64, 32, 16, 8, 4, 2, 1}; // to calculate Binary conversion
    int binaryip[4][8]; // to store Binary IP address
    int binarysubnet[4][8]; // to store Binary Subnet mask
    int network[4][8];  // to store Network ID
    int broadcast[4][8]; // to store Broadcast ID
    int minhost[4][8]; // to store Minimum Host ID
    int maxhost[4][8]; // to store Maximum Host ID
    int usablehost[4][8]; // to store Usable Host IDs (excluding Network ID and Broadcast ID)

    printf("Please enter the IP address with dots between each octet: ");
    scanf("%d.%d.%d.%d", &ip[0], &ip[1], &ip[2], &ip[3]);

    printf("Please enter the Subnet Mask with dots between each octet: ");
    scanf("%d.%d.%d.%d", &subnet[0], &subnet[1], &subnet[2], &subnet[3]);

    // Calculate Mask Bits
    maskbit = 0;
    temp = subnet[0];
    while (temp != 0) {
        maskbit++;
        temp = temp << 1;
    }

    temp = subnet[1];
    while (temp != 0) {
        maskbit++;
        temp = temp << 1;
    }

    temp = subnet[2];
    while (temp != 0) {
        maskbit++;
        temp = temp << 1;
    }

    temp = subnet[3];
    while (temp != 0) {
        maskbit++;
        temp = temp << 1;
    }

    // Convert IP Address to Binary
    for (i = 0; i < 4; i++) {
        temp = ip[i];
        for (j = 0; j < 8; j++) {
            binaryip[i][j] = temp / power[j];
            temp = temp % power[j];
        }
    }

    // Convert Subnet Mask to Binary
    for (i = 0; i < 4; i++) {
        temp = subnet[i];
        for (j = 0; j < 8; j++) {
            binarysubnet[i][j] = temp / power[j];
            temp = temp % power[j];
        }
    }

    // Calculate Network ID, Broadcast ID, Minimum Host ID, Maximum Host ID, and Usable Host IDs
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 8; j++) {
            if (j < maskbit) {
                network[i][j] = binaryip[i][j] & binarysubnet[i][j];
                broadcast[i][j] = network[i][j];
            }
            else {
                network[i][j] = 0;
                broadcast[i][j] = 1;
            }
            minhost[i][j] = network[i][j];
            maxhost[i][j] = broadcast[i][j];
            if (j == 7) {
                broadcast[i][j] = 0;
                maxhost[i][j] = 0;
            }
        }
    }

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 8; j++) {
            if (j == 7) {
                usablehost[i][j] = 0;
            }
            else if (j < maskbit) {
                usablehost[i][j] = binaryip[i][j] & binarysubnet[i][j];
            }
            else if (j == maskbit) {
                usablehost[i][j] = 1;
            }
            else {
                usablehost[i][j] = 0;
            }
        }
    }

    // Convert Network ID, Broadcast ID, Minimum Host ID, Maximum Host ID, and Usable Host IDs to Decimal
    int networkid[4], broadcastid[4], minhostid[4], maxhostid[4], usablehostid[4];
    for (i = 0; i < 4; i++) {
        networkid[i] = 0;
        broadcastid[i] = 0;
        minhostid[i] = 0;
        maxhostid[i] = 0;
        usablehostid[i] = 0;
        for (j = 0; j < 8; j++) {
            networkid[i] += network[i][j] * power[7-j];
            broadcastid[i] += broadcast[i][j] * power[7-j];
            minhostid[i] += minhost[i][j] * power[7-j];
            maxhostid[i] += maxhost[i][j] * power[7-j];
            usablehostid[i] += usablehost[i][j] * power[7-j];
        }
    }

    // Print Output
    printf("\n\nIP Address: %d.%d.%d.%d", ip[0], ip[1], ip[2], ip[3]);
    printf("\nSubnet Mask: %d.%d.%d.%d", subnet[0], subnet[1], subnet[2], subnet[3]);
    printf("\n\nNetwork ID: %d.%d.%d.%d", networkid[0], networkid[1], networkid[2], networkid[3]);
    printf("\nBroadcast ID: %d.%d.%d.%d", broadcastid[0], broadcastid[1], broadcastid[2], broadcastid[3]);
    printf("\nMinimum Host ID: %d.%d.%d.%d", minhostid[0], minhostid[1], minhostid[2], minhostid[3]);
    printf("\nMaximum Host ID: %d.%d.%d.%d", maxhostid[0], maxhostid[1], maxhostid[2], maxhostid[3]);
    printf("\nUsable Host IDs: %d.%d.%d.%d - %d.%d.%d.%d", minhostid[0], minhostid[1], minhostid[2], minhostid[3], maxhostid[0], maxhostid[1], maxhostid[2], maxhostid[3]);
    
    return 0;
}