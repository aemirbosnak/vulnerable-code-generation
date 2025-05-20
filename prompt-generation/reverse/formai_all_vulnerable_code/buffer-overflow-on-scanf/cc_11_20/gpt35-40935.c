//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(){

    char ip[20];
    char subnetMask[20];
    int subnet;
    int i;

    printf("Enter IP address: ");
    scanf("%s", ip);

    printf("Enter subnet mask: ");
    scanf("%s", subnetMask);

    // Calculate # of subnet bits
    for (i = 0; i < strlen(subnetMask); i++) {
        if (subnetMask[i] == '.') {
            subnet++;
        }
    }

    // Calculate subnet mask
    int n = atoi(subnetMask);
    int j = 0;
    int p[8] = { 128, 64, 32, 16, 8, 4, 2, 1 };
    int a, b, c, d;

    while (n > 0) {
        if (n >= p[j]) {
            n -= p[j];
            subnetMask[j] = '1';
        } else {
            subnetMask[j] = '0';
        }
        j++;
    }

    // Calculate IP address in binary
    int binaryIP[32];
    j = 0;
    char temp[4];
    int count = 0;

    for (i = 0; i < strlen(ip); i++) {
        if (ip[i] == '.') {
            temp[count] = '\0';
            count = 0;
            int num = atoi(temp);
            int k;
            for (k = 0; k < 8; k++) {
                if (num >= p[k]) {
                    num -= p[k];
                    binaryIP[j] = 1;
                } else {
                    binaryIP[j] = 0;
                }
                j++;
            }
        } else {
            temp[count] = ip[i];
            count++;
        }
    }

    // Determine the network address and broadcast address
    int networkAddress[32];
    int broadcastAddress[32];

    for (i = 0; i < 32; i++) {
        if (i < subnet) {
            networkAddress[i] = binaryIP[i];
            broadcastAddress[i] = binaryIP[i];
        } else {
            networkAddress[i] = 0;
            broadcastAddress[i] = 1;
        }
    }

    // Convert network and broadcast addresses to decimal and print results
    a = networkAddress[0] * 128 + networkAddress[1] * 64 + networkAddress[2] * 32 + networkAddress[3] * 16 + networkAddress[4] * 8 + networkAddress[5] * 4 + networkAddress[6] * 2 + networkAddress[7];
    b = networkAddress[8] * 128 + networkAddress[9] * 64 + networkAddress[10] * 32 + networkAddress[11] * 16 + networkAddress[12] * 8 + networkAddress[13] * 4 + networkAddress[14] * 2 + networkAddress[15];
    c = networkAddress[16] * 128 + networkAddress[17] * 64 + networkAddress[18] * 32 + networkAddress[19] * 16 + networkAddress[20] * 8 + networkAddress[21] * 4 + networkAddress[22] * 2 + networkAddress[23];
    d = networkAddress[24] * 128 + networkAddress[25] * 64 + networkAddress[26] * 32 + networkAddress[27] * 16 + networkAddress[28] * 8 + networkAddress[29] * 4 + networkAddress[30] * 2 + networkAddress[31];
    printf("Network Address: %d.%d.%d.%d\n", a, b, c, d);

    a = broadcastAddress[0] * 128 + broadcastAddress[1] * 64 + broadcastAddress[2] * 32 + broadcastAddress[3] * 16 + broadcastAddress[4] * 8 + broadcastAddress[5] * 4 + broadcastAddress[6] * 2 + broadcastAddress[7];
    b = broadcastAddress[8] * 128 + broadcastAddress[9] * 64 + broadcastAddress[10] * 32 + broadcastAddress[11] * 16 + broadcastAddress[12] * 8 + broadcastAddress[13] * 4 + broadcastAddress[14] * 2 + broadcastAddress[15];
    c = broadcastAddress[16] * 128 + broadcastAddress[17] * 64 + broadcastAddress[18] * 32 + broadcastAddress[19] * 16 + broadcastAddress[20] * 8 + broadcastAddress[21] * 4 + broadcastAddress[22] * 2 + broadcastAddress[23];
    d = broadcastAddress[24] * 128 + broadcastAddress[25] * 64 + broadcastAddress[26] * 32 + broadcastAddress[27] * 16 + broadcastAddress[28] * 8 + broadcastAddress[29] * 4 + broadcastAddress[30] * 2 + broadcastAddress[31];
    printf("Broadcast Address: %d.%d.%d.%d\n", a, b, c, d);

    return 0;
}