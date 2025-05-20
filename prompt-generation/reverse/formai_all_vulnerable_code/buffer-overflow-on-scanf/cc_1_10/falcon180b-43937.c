//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main() {
    char ip_address[16];
    char subnet_mask[16];
    char network_address[16];
    char broadcast_address[16];
    char *token;
    int i, j, k, m;

    printf("Enter the IP address: ");
    scanf("%s", ip_address);

    printf("Enter the subnet mask: ");
    scanf("%s", subnet_mask);

    // Convert IP address and subnet mask to integer format
    for (i = 0; i < strlen(ip_address); i++) {
        if (ip_address[i] == '.') {
            ip_address[i] = '\0';
        }
    }
    for (j = 0; j < strlen(subnet_mask); j++) {
        if (subnet_mask[j] == '.') {
            subnet_mask[j] = '\0';
        }
    }
    sscanf(ip_address, "%d.%d.%d.%d", &i, &j, &k, &m);
    sscanf(subnet_mask, "%d.%d.%d.%d", &i, &j, &k, &m);

    // Calculate network address
    network_address[0] = (char) i;
    network_address[1] = (char) j;
    network_address[2] = (char) k;
    network_address[3] = (char) m;

    // Calculate broadcast address
    broadcast_address[0] = (char) (i + 255);
    broadcast_address[1] = (char) (j + 255);
    broadcast_address[2] = (char) (k + 255);
    broadcast_address[3] = (char) (m + 255);

    printf("IP address: %s\n", ip_address);
    printf("Subnet mask: %s\n", subnet_mask);
    printf("Network address: %s\n", network_address);
    printf("Broadcast address: %s\n", broadcast_address);

    return 0;
}