//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: authentic
#include<stdio.h>
#include<string.h>
#include<stdint.h>
#include<stdlib.h>
#include<math.h>

#define MAXSIZE 32

// Function to convert decimal to binary
void dectobin(int n, char* binary) {
    if (n == 0) {
        strcpy(binary, "0");
    }
    int i = 0;
    char temp[MAXSIZE] = "";
    while (n != 0) {
        sprintf(temp, "%d%s", n%2, binary);
        n = n/2;
        i++;
        strcpy(binary, temp);
    }
    while (i < 8) {
        sprintf(temp, "0%s", binary);
        i++;
        strcpy(binary, temp);
    }
}

int main() {

    int ipaddr[4];
    char subnetbinary[MAXSIZE] = "";
    int subnet;

    printf("Enter IP address in dot-decimal format: ");
    scanf("%d.%d.%d.%d", &ipaddr[0], &ipaddr[1], &ipaddr[2], &ipaddr[3]);

    printf("Enter subnet mask in CIDR notation: ");
    scanf("%d", &subnet);

    // Convert subnet from CIDR notation to binary
    for (int i = 0; i < subnet; i++) {
        strcat(subnetbinary, "1");
    }
    while (strlen(subnetbinary) < MAXSIZE) {
        strcat(subnetbinary, "0");
    }

    // Convert subnet from binary to decimal
    int count = 0;
    int k = 0;
    for (int i = 0; i < MAXSIZE; i++) {
        if (count == 8) {
            count = 0;
            k++;
        }
        ipaddr[k] += pow(2, 7-count) * (subnetbinary[i] - '0');
        count++;
    }

    printf("\nNetwork address: %d.%d.%d.%d\n", ipaddr[0], ipaddr[1], ipaddr[2], ipaddr[3]);

    // Convert subnet mask from decimal to binary
    char subnetmask[MAXSIZE] = "";
    for (int i = 0; i < 4; i++) {
        char binary[MAXSIZE] = "";
        dectobin(ipaddr[i], binary);
        strcat(subnetmask, binary);
    }

    // Calculate number of hosts
    int numhosts = pow(2, 32-subnet) - 2;
    printf("Number of hosts: %d\n", numhosts);

    // Calculate subnet ID and broadcast address
    char subnetid[MAXSIZE] = "";
    char broadcast[MAXSIZE] = "";
    for (int i = 0; i < MAXSIZE; i++) {
        if (i < subnet) {
            strcat(subnetid, subnetmask+i);
            strcat(broadcast, subnetmask+i);
        }
        else {
            strcat(subnetid, "0");
            strcat(broadcast, "1");
        }
    }

    int subnetiddecimal[4] = {0};
    int broadcastdecimal[4] = {0};
    k = 0;
    count = 0;
    for (int i = 0; i < MAXSIZE; i++) {
        if (count == 8) {
            count = 0;
            k++;
        }
        if (i < subnet) {
            subnetiddecimal[k] += pow(2, 7-count) * (subnetid[i] - '0');
            broadcastdecimal[k] += pow(2, 7-count) * (broadcast[i] - '0');
        }
        else {
            broadcastdecimal[k] += pow(2, 7-count) * (broadcast[i] - '0');
        }
        count++;
    }

    printf("Subnet ID: %d.%d.%d.%d\n", subnetiddecimal[0], subnetiddecimal[1], subnetiddecimal[2], subnetiddecimal[3]);
    printf("Broadcast address: %d.%d.%d.%d\n", broadcastdecimal[0], broadcastdecimal[1], broadcastdecimal[2], broadcastdecimal[3]);

    return 0;
}