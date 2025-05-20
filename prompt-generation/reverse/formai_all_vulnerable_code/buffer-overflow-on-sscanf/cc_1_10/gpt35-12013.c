//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

void calculate_subnet(char *ip_address, char *subnet_mask);

int main() {

    char ip_address[20], subnet_mask[20];

    printf("Enter ip address: ");
    scanf("%s", ip_address);

    printf("Enter subnet mask: ");
    scanf("%s", subnet_mask);

    calculate_subnet(ip_address, subnet_mask);

    return 0;
}

void calculate_subnet(char *ip_address, char *subnet_mask) {

    // Convert ip_address and subnet_mask to integer values
    int ip_int[4], subnet_int[4], i;

    sscanf(ip_address, "%d.%d.%d.%d", &ip_int[0], &ip_int[1], &ip_int[2], &ip_int[3]);
    sscanf(subnet_mask, "%d.%d.%d.%d", &subnet_int[0], &subnet_int[1], &subnet_int[2], &subnet_int[3]);

    // Calculate the network address
    int network_int[4];
    for(i = 0; i < 4; i++) {
        network_int[i] = ip_int[i] & subnet_int[i];
    }

    // Calculate the broadcast address
    int broadcast_int[4];
    for(i = 0; i < 4; i++) {
        broadcast_int[i] = network_int[i] | (~subnet_int[i] & 0xFF);
    }

    // Print the network and broadcast address
    printf("Network address: %d.%d.%d.%d\n", network_int[0], network_int[1], network_int[2], network_int[3]);
    printf("Broadcast address: %d.%d.%d.%d\n", broadcast_int[0], broadcast_int[1], broadcast_int[2], broadcast_int[3]);

    // Calculate the number of available hosts
    int num_hosts = 1;
    for(i = 0; i < 4; i++) {
        num_hosts *= (subnet_int[i] == 255) ? 1 : 256 - subnet_int[i];
    }
    num_hosts -= 2;

    printf("Number of available hosts: %d\n", num_hosts);

    return;
}