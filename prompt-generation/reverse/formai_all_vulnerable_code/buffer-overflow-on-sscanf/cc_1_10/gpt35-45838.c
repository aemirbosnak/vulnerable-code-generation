//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: medieval
#include <stdio.h>

int main() {
    
    // Welcome message
    printf("Greetings, traveler! Welcome to the Subnet Calculator of Ye Olde Kingdom.\n");
    printf("Please enter thy IPv4 address (e.g. 192.168.1.1): ");
    
    // Read in user input
    char ip[16];
    scanf("%s", ip);
    
    printf("\nExcellent! Now, enter thy subnet mask in decimal notation (e.g. 255.255.255.0): ");
    
    // Read in subnet mask
    char subnet_mask[16];
    scanf("%s", subnet_mask);
    
    // Parse input into octets
    int ip_octets[4];
    int subnet_octets[4];
    sscanf(ip, "%d.%d.%d.%d", &ip_octets[0], &ip_octets[1], &ip_octets[2], &ip_octets[3]);
    sscanf(subnet_mask, "%d.%d.%d.%d", &subnet_octets[0], &subnet_octets[1], &subnet_octets[2], &subnet_octets[3]);
    
    // Compute network address
    int network_octets[4];
    for (int i = 0; i < 4; i++) {
        network_octets[i] = ip_octets[i] & subnet_octets[i];
    }
    
    // Compute broadcast address
    int broadcast_octets[4];
    for (int i = 0; i < 4; i++) {
        broadcast_octets[i] = network_octets[i] | (255 - subnet_octets[i]);
    }
    
    // Compute number of hosts
    int num_hosts = 1;
    for (int i = 0; i < 4; i++) {
        num_hosts *= (255 - subnet_octets[i]) + 1;
    }
    num_hosts -= 2; // Subtract network and broadcast addresses
    
    // Display results
    printf("\nVerily! Thou hast requested:\n");
    printf("IPv4 Address: %s\n", ip);
    printf("Subnet Mask: %s\n", subnet_mask);
    printf("Network Address: %d.%d.%d.%d\n", network_octets[0], network_octets[1], network_octets[2], network_octets[3]);
    printf("Broadcast Address: %d.%d.%d.%d\n", broadcast_octets[0], broadcast_octets[1], broadcast_octets[2], broadcast_octets[3]);
    printf("Number of Hosts: %d\n", num_hosts);
    
    // Farewell message
    printf("\nSafe travels, friend. May thy networks be ever secure!\n");
    
    return 0;
}