//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_SUBNETS 100

typedef struct {
    char ip[16];       // IPv4 address
    char subnet_mask[16]; // Subnet mask
    int prefix_length; // CIDR prefix length
} SubnetInfo;

SubnetInfo subnets[MAX_SUBNETS];
int subnet_count = 0;

void* calculate_subnet(void* arg) {
    SubnetInfo* subnet_info = (SubnetInfo*)arg;

    struct in_addr ip_addr, subnet_addr, broadcast_addr;
    if (inet_pton(AF_INET, subnet_info->ip, &ip_addr) != 1) {
        printf("Error: Invalid IP address %s\n", subnet_info->ip);
        pthread_exit(NULL);
    }
    
    if (inet_pton(AF_INET, subnet_info->subnet_mask, &subnet_addr) != 1) {
        printf("Error: Invalid subnet mask %s\n", subnet_info->subnet_mask);
        pthread_exit(NULL);
    }

    // Calculate the network address
    struct in_addr network_addr;
    network_addr.s_addr = ip_addr.s_addr & subnet_addr.s_addr;

    // Calculate the broadcast address
    broadcast_addr.s_addr = network_addr.s_addr | ~subnet_addr.s_addr;

    // Print results
    char network[INET_ADDRSTRLEN], broadcast[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &network_addr, network, INET_ADDRSTRLEN);
    inet_ntop(AF_INET, &broadcast_addr, broadcast, INET_ADDRSTRLEN);

    printf("IP Address: %s\n", subnet_info->ip);
    printf("Subnet Mask: %s\n", subnet_info->subnet_mask);
    printf("Network Address: %s\n", network);
    printf("Broadcast Address: %s\n", broadcast);
    printf("CIDR Prefix Length: %d\n", subnet_info->prefix_length);
    printf("----------------------------------------\n");

    pthread_exit(NULL);
}

int main() {
    printf("Asynchronous C Subnet Calculator\n");
    printf("Enter Subnets (IP Address and Subnet Mask), type 'done' to finish:\n");

    char input[256];
    pthread_t threads[MAX_SUBNETS];

    while (1) {
        printf("Enter IP/Subnet (e.g., 192.168.1.1 255.255.255.0): ");
        if (fgets(input, sizeof(input), stdin) == NULL) {
            break;
        }

        // Check for exit condition
        if (strcmp(input, "done\n") == 0) {
            break;
        }

        SubnetInfo subnet_info;
        if (sscanf(input, "%s %s", subnet_info.ip, subnet_info.subnet_mask) != 2) {
            printf("Invalid input. Please enter an IP address and a subnet mask.\n");
            continue;
        }

        subnet_info.prefix_length = 0; // For simplicity, assume a default value

        // Create a thread to calculate the subnet
        pthread_create(&threads[subnet_count], NULL, calculate_subnet, (void*)&subnet_info);
        subnet_count++;

        if (subnet_count >= MAX_SUBNETS) {
            printf("Maximum subnet limit reached.\n");
            break;
        }
    }

    // Wait for all threads to finish
    for (int i = 0; i < subnet_count; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("All subnet calculations are complete!\n");
    return 0;
}