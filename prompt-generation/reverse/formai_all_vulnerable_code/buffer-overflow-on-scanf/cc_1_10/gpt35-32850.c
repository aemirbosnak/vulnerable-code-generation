//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to convert decimal to binary
void decToBin(int n, char bin[])
{
    // Array to store binary number
    int binaryNum[32];
 
    // Counter for binary array
    int i = 0;
    while (n > 0) {
 
        // Storing remainder in binary array
        binaryNum[i] = n % 2;
        n = n / 2;
        i++;
    }

    // Converting binary array to string
    int j;
    for (j = i - 1; j >= 0; j--) {
        sprintf(bin + strlen(bin), "%d", binaryNum[j]);
    }
}

// Function to calculate the subnet mask
void subnetMask(int cidr, char subnet[])
{
    int i, j;
    char bin[33];
    for (i = 0; i < 32; i++) {
        if (i < cidr) {
            bin[i] = '1';
        } else {
            bin[i] = '0';
        }
    }

    bin[32] = '\0';

    // Converting binary string to decimal and storing it in subnet array
    j = 0;
    for (i = 0; i < 32; i += 8) {
        int k, n = 0;
        for (k = i; k < i + 8; k++) {
            if (bin[k] == '1') {
                n += 1 << (7 - (k - i));
            }
        }
        sprintf(subnet + j, "%d", n);
        j = strlen(subnet);
        subnet[j++] = '.';
    }
    subnet[j - 1] = '\0';
}

// Function to calculate the network ID
void networkID(char ip[], char subnet[], char network[])
{
    char *tok = strtok(ip, ".");
    int i = 0;
    while (tok != NULL) {
        int n = atoi(tok) & atoi(strtok(subnet + (i * 4), "."));
        sprintf(network + strlen(network), "%d", n);
        tok = strtok(NULL, ".");
        if (tok != NULL) {
            sprintf(network + strlen(network), ".");
        }
        i++;
    }
}

int main()
{
    char ip[16], subnet[16], network[16];
    int cidr;
    printf("Enter an IP address and a CIDR notation (e.g. 192.168.0.1/24):\n");
    scanf("%15s/%d", ip, &cidr);

    subnetMask(cidr, subnet);
    networkID(ip, subnet, network);

    printf("IP Address:\t%s\n", ip);
    printf("Subnet Mask:\t%s\n", subnet);
    printf("Network ID:\t%s\n", network);

    return 0;
}