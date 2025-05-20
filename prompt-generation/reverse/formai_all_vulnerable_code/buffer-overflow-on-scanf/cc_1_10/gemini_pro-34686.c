//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

// Structure to store subnet information
typedef struct {
    char *ip_address;
    int subnet_mask;
    int num_hosts;
    char *network_address;
    char *broadcast_address;
} subnet_info;

// Function to calculate subnet information
void *calculate_subnet_info(void *arg) {
    subnet_info *info = (subnet_info *)arg;

    // Calculate network address
    char network_address[16];
    int i;
    for (i = 0; i < 4; i++) {
        network_address[i] = info->ip_address[i] & info->subnet_mask;
    }

    // Calculate broadcast address
    char broadcast_address[16];
    for (i = 0; i < 4; i++) {
        broadcast_address[i] = network_address[i] | ~info->subnet_mask;
    }

    // Calculate number of hosts
    int num_hosts = (1 << (32 - info->subnet_mask)) - 2;

    // Store calculated information in the structure
    info->network_address = malloc(16);
    strcpy(info->network_address, network_address);
    info->broadcast_address = malloc(16);
    strcpy(info->broadcast_address, broadcast_address);
    info->num_hosts = num_hosts;

    return NULL;
}

// Main function
int main() {
    // Get input from the user
    char ip_address[16];
    int subnet_mask;
    printf("Enter the IP address: ");
    scanf("%s", ip_address);
    printf("Enter the subnet mask: ");
    scanf("%d", &subnet_mask);

    // Create a subnet information structure
    subnet_info info;
    info.ip_address = ip_address;
    info.subnet_mask = subnet_mask;

    // Create a thread to calculate subnet information
    pthread_t tid;
    pthread_create(&tid, NULL, calculate_subnet_info, &info);

    // Wait for the thread to finish
    pthread_join(tid, NULL);

    // Print the subnet information
    printf("Network address: %s\n", info.network_address);
    printf("Broadcast address: %s\n", info.broadcast_address);
    printf("Number of hosts: %d\n", info.num_hosts);

    return 0;
}