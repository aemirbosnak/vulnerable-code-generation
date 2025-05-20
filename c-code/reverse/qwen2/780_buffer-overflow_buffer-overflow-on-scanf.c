#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>

int main() {
    int ip[4], subnet_id[4], broadcast[4];
    printf("Enter IP address: ");
    scanf("%d.%d.%d.%d", &ip[0], &ip[1], &ip[2], &ip[3]);
    
    // Calculate subnet ID
    subnet_id[0] = ip[0];
    subnet_id[1] = ip[1];
    subnet_id[2] = ip[2];
    subnet_id[3] = 0;
    
    // Calculate broadcast address
    broadcast[0] = ip[0];
    broadcast[1] = ip[1];
    broadcast[2] = ip[2];
    broadcast[3] = 255;
    
    // Number of hosts
    int num_hosts = 256 * 256 - 2; // Subtracting network and broadcast addresses
    
    printf("Subnet ID: %d.%d.%d.%d\n", subnet_id[0], subnet_id[1], subnet_id[2], subnet_id[3]);
    printf("Broadcast Address: %d.%d.%d.%d\n", broadcast[0], broadcast[1], broadcast[2], broadcast[3]);
    printf("Number of Hosts: %d\n", num_hosts);
    
    return 0;
}
