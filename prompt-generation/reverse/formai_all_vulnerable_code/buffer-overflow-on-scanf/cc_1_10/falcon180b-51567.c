//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 10
#define MAX_SUBNET_SIZE 32

typedef struct {
    char ip[MAX_SUBNET_SIZE];
    int mask;
    int num_hosts;
} subnet;

int main() {
    int num_subnets, i, j, k, hosts_per_subnet, first_octet, last_octet, current_octet;
    char ip[MAX_SUBNET_SIZE];
    subnet subnets[MAX_SUBNETS];

    // Get user input for IP address and subnet mask
    printf("Enter IP address: ");
    scanf("%s", ip);
    printf("Enter subnet mask: ");
    scanf("%d", &subnets[0].mask);

    // Calculate number of subnets and hosts per subnet
    first_octet = ip[0] - '0';
    last_octet = ip[strlen(ip) - 1] - '0';
    hosts_per_subnet = (int)pow(2, 8 - subnets[0].mask);
    num_subnets = (last_octet - first_octet + 1) * hosts_per_subnet;

    // Initialize subnet array with default values
    for (i = 0; i < num_subnets; i++) {
        strcpy(subnets[i].ip, ip);
        subnets[i].mask = subnets[0].mask;
        subnets[i].num_hosts = hosts_per_subnet;
    }

    // Calculate subnet addresses and update subnet array
    for (i = 0; i < num_subnets; i++) {
        for (j = 0; j < 4; j++) {
            current_octet = (int)ip[j] - '0';
            if (j == 3 && current_octet < 0) {
                current_octet += 256;
            }
            if (j == 3 && subnets[i].mask < 8) {
                current_octet += (int)pow(2, 8 - subnets[i].mask);
            }
            subnets[i].ip[j] = (char)current_octet + '0';
        }
    }

    // Print subnet addresses
    printf("\nSubnet addresses:\n");
    for (i = 0; i < num_subnets; i++) {
        printf("%s\n", subnets[i].ip);
    }

    return 0;
}