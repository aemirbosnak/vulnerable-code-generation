//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

#define NUM_THREADS 4

typedef struct {
    unsigned int ip_address;
    unsigned int subnet_mask;
    unsigned int network_address;
    unsigned int broadcast_address;
    unsigned int num_hosts;
} subnet_info;

void *calculate_subnet(void *arg) {
    subnet_info *info = (subnet_info *)arg;

    // Calculate the network address
    info->network_address = info->ip_address & info->subnet_mask;

    // Calculate the broadcast address
    info->broadcast_address = info->network_address | ~info->subnet_mask;

    // Calculate the number of hosts
    info->num_hosts = pow(2, 32 - log2(info->subnet_mask));

    return NULL;
}

int main() {
    // Get the input from the user
    unsigned int ip_address;
    unsigned int subnet_mask;
    printf("Enter the IP address: ");
    scanf("%u", &ip_address);
    printf("Enter the subnet mask: ");
    scanf("%u", &subnet_mask);

    // Create the thread pool
    pthread_t threads[NUM_THREADS];

    // Create the subnet info structure
    subnet_info info;
    info.ip_address = ip_address;
    info.subnet_mask = subnet_mask;

    // Create the threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_create(&threads[i], NULL, calculate_subnet, &info);
    }

    // Join the threads
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print the subnet information
    printf("Network address: %u\n", info.network_address);
    printf("Broadcast address: %u\n", info.broadcast_address);
    printf("Number of hosts: %u\n", info.num_hosts);

    return 0;
}