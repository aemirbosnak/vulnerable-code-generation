//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_IP_ADDR_LEN 15

void subnet_calculator(char *ip_addr, int subnet_mask){

    int i, mask;
    unsigned long ip_addr_int, broadcast_addr_int, network_addr_int;
    char broadcast_addr[MAX_IP_ADDR_LEN + 1], network_addr[MAX_IP_ADDR_LEN + 1], *ptr;

    // Convert IP address string to long integer
    ip_addr_int = inet_addr(ip_addr);

    // Calculate subnet mask
    mask = ~((1 << (32 - subnet_mask)) - 1);

    // Calculate network address
    network_addr_int = ip_addr_int & mask;

    // Convert network address to string
    ptr = (char *)&network_addr_int;
    sprintf(network_addr, "%d.%d.%d.%d", ptr[0], ptr[1], ptr[2], ptr[3]);

    // Calculate broadcast address
    broadcast_addr_int = network_addr_int + ((1 << (32 - subnet_mask)) - 1);

    // Convert broadcast address to string
    ptr = (char *)&broadcast_addr_int;
    sprintf(broadcast_addr, "%d.%d.%d.%d", ptr[0], ptr[1], ptr[2], ptr[3]);

    // Print results
    printf("IP Address\t\t: %s\n", ip_addr);
    printf("Subnet Mask\t\t: %d\n", subnet_mask);
    printf("Network Address\t\t: %s\n", network_addr);
    printf("Broadcast Address\t: %s\n", broadcast_addr);
    printf("Number of hosts\t\t: %d\n", (1 << (32 - subnet_mask)) - 2);

}

int main(){

    char ip_addr[MAX_IP_ADDR_LEN + 1];
    int subnet_mask;

    // Read IP address and subnet mask
    printf("Enter IP address (e.g., 192.168.0.1):\n");
    scanf("%s", ip_addr);
    printf("Enter subnet mask (e.g., 24):\n");
    scanf("%d", &subnet_mask);

    // Call subnet calculator function
    subnet_calculator(ip_addr, subnet_mask);

    return 0;
}