//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char IP[16];
    int bits;
    unsigned int subnetmask, wildcard, network, broadcast;
    char class;

    printf("Enter an IP address (xxx.xxx.xxx.xxx): ");
    scanf("%s", IP);

    char *token;
    int arr[4];
    int i = 0;

    token = strtok(IP, ".");
    while (token != NULL)
    {
        arr[i++] = atoi(token);
        token = strtok(NULL, ".");
    }

    if (arr[0] >= 1 && arr[0] <= 127)
    {
        subnetmask = 255 << 24;
        class = 'A';
    }
    else if (arr[0] >= 128 && arr[0] <= 191)
    {
        subnetmask = 255 << 24 | 255 << 16;
        class = 'B';
    }
    else if (arr[0] >= 192 && arr[0] <= 223)
    {
        subnetmask = 255 << 24 | 255 << 16 | 255 << 8;
        class = 'C';
    }
    else if (arr[0] >= 224 && arr[0] <= 239)
    {
        printf("Multicast address\n");
        exit(0);
    }
    else if (arr[0] >= 240 && arr[0] <= 255)
    {
        printf("Reserved address\n");
        exit(0);
    }

    printf("Enter number of bits in subnet mask: ");
    scanf("%d", &bits);

    for (int i = 0; i < bits; i++)
    {
        subnetmask |= 1 << (31 - i);
    }

    wildcard = ~subnetmask;

    network = (arr[0] << 24) | (arr[1] << 16) | (arr[2] << 8) | arr[3];
    network &= subnetmask;

    broadcast = network | wildcard;

    printf("Class: %c\n", class);
    printf("IP address: %s\n", IP);
    printf("Subnet mask: %d.%d.%d.%d\n", (subnetmask >> 24) & 0xFF, (subnetmask >> 16) & 0xFF, (subnetmask >> 8) & 0xFF, subnetmask & 0xFF);
    printf("Wildcard mask: %d.%d.%d.%d\n", (wildcard >> 24) & 0xFF, (wildcard >> 16) & 0xFF, (wildcard >> 8) & 0xFF, wildcard & 0xFF);
    printf("Network address: %d.%d.%d.%d\n", (network >> 24) & 0xFF, (network >> 16) & 0xFF, (network >> 8) & 0xFF, network & 0xFF);
    printf("Broadcast address: %d.%d.%d.%d\n", (broadcast >> 24) & 0xFF, (broadcast >> 16) & 0xFF, (broadcast >> 8) & 0xFF, broadcast & 0xFF);

    return 0;
}