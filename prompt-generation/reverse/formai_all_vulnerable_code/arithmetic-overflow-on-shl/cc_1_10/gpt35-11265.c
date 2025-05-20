//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char input[20];
    int address[4];
    int bits;
    int mask;

    printf("*** Welcome to the C Subnet Calculator! ***\n\n");
    printf("Enter IP Address with subnet mask (e.g. 192.168.1.1/24): ");
    scanf("%s", input);

    char *token = strtok(input, "."); // Split the IP address into four octets
    int i = 0;
    while (token != NULL) {
        address[i++] = atoi(token);
        token = strtok(NULL, ".");
    }

    bits = atoi(strchr(input, '/') + 1); // Get the subnet mask bits

    if (bits < 0 || bits > 32) {
        printf("Error: Invalid subnet mask bits!\n");
        exit(1);
    }

    // Calculate subnet mask value
    mask = 0xffffffff << (32 - bits);

    printf("\nIP Address: %d.%d.%d.%d\n", address[0], address[1], address[2], address[3]);
    printf("Subnet Mask: %d.%d.%d.%d\n", (mask >> 24) & 0xff, (mask >> 16) & 0xff, (mask >> 8) & 0xff, mask & 0xff);
    printf("CIDR Prefix: %d\n", bits);

    // Calculate network address
    int network_addr = ((address[0] << 24) | (address[1] << 16) | (address[2] << 8) | address[3]) & mask;

    printf("Network Address: %d.%d.%d.%d\n", (network_addr >> 24) & 0xff, (network_addr >> 16) & 0xff, (network_addr >> 8) & 0xff, network_addr & 0xff);

    // Calculate broadcast address
    int broadcast_addr = network_addr + (~mask & 0xffffffff);

    printf("Broadcast Address: %d.%d.%d.%d\n", (broadcast_addr >> 24) & 0xff, (broadcast_addr >> 16) & 0xff, (broadcast_addr >> 8) & 0xff, broadcast_addr & 0xff);

    // Calculate number of usable hosts
    int usable_hosts = (~mask & 0xffffffff) - 1;

    printf("Number of Usable Hosts: %d\n", usable_hosts);

    return 0;
}