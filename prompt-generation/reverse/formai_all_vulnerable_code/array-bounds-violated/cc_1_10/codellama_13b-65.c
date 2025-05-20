//Code Llama-13B DATASET v1.0 Category: Subnet Calculator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#define MAX_SUBNETS 4

struct Subnet {
    char subnet[16];
    char mask[16];
    char broadcast[16];
    char first_host[16];
    char last_host[16];
};

int main() {
    struct Subnet subnets[MAX_SUBNETS];
    char ip_address[16];
    char netmask[16];
    char broadcast[16];
    char first_host[16];
    char last_host[16];

    printf("Enter IP address: ");
    scanf("%s", ip_address);
    printf("Enter netmask: ");
    scanf("%s", netmask);

    // Calculate broadcast address
    strcpy(broadcast, ip_address);
    broadcast[strlen(broadcast) - 1] = broadcast[strlen(broadcast) - 1] + ~(netmask[strlen(netmask) - 1]);

    // Calculate first and last host addresses
    strcpy(first_host, ip_address);
    first_host[strlen(first_host) - 1] = first_host[strlen(first_host) - 1] + 1;
    strcpy(last_host, broadcast);
    last_host[strlen(last_host) - 1] = last_host[strlen(last_host) - 1] - 1;

    // Calculate number of subnets
    int subnet_count = 0;
    for (int i = 0; i < strlen(netmask); i++) {
        if (netmask[i] == '0') {
            subnet_count++;
        }
    }

    // Calculate subnets
    int subnet_size = 2 << (subnet_count - 1);
    for (int i = 0; i < MAX_SUBNETS; i++) {
        strcpy(subnets[i].subnet, ip_address);
        strcpy(subnets[i].mask, netmask);
        strcpy(subnets[i].broadcast, broadcast);
        strcpy(subnets[i].first_host, first_host);
        strcpy(subnets[i].last_host, last_host);
        first_host[strlen(first_host) - 1] = first_host[strlen(first_host) - 1] + subnet_size;
        last_host[strlen(last_host) - 1] = last_host[strlen(last_host) - 1] - subnet_size;
    }

    // Print subnets
    for (int i = 0; i < MAX_SUBNETS; i++) {
        printf("Subnet %d:\n", i + 1);
        printf("  IP address: %s\n", subnets[i].subnet);
        printf("  Netmask: %s\n", subnets[i].mask);
        printf("  Broadcast address: %s\n", subnets[i].broadcast);
        printf("  First host address: %s\n", subnets[i].first_host);
        printf("  Last host address: %s\n", subnets[i].last_host);
        printf("\n");
    }

    return 0;
}