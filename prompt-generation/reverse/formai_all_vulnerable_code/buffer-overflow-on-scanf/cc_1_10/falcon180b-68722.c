//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 10
#define IP_LENGTH 15
#define SUBNET_MASK_LENGTH 2

// Function to validate IP address
int is_valid_ip(char *ip) {
    int i, j;
    char *ptr;
    int parts = 0;

    ptr = strtok(ip, ".");
    while (ptr!= NULL) {
        if (atoi(ptr) < 0 || atoi(ptr) > 255)
            return 0;
        parts++;
        ptr = strtok(NULL, ".");
    }

    if (parts!= 4)
        return 0;

    return 1;
}

// Function to calculate number of hosts and subnets in a given network
void calculate_subnets(char *ip, int mask, int *num_hosts, int *num_subnets) {
    int i;
    char subnet_ip[IP_LENGTH];
    int subnet_mask;

    // Calculate number of subnets
    for (i = 0; i <= mask; i++) {
        strcpy(subnet_ip, ip);
        subnet_mask = mask - i;
        snprintf(subnet_ip + strlen(subnet_ip), IP_LENGTH - strlen(subnet_ip), ".%d", subnet_mask);
        *num_subnets += 1;
    }

    // Calculate number of hosts per subnet
    *num_hosts = (int)pow(2, (32 - mask)) - 2;
}

int main() {
    char ip[IP_LENGTH];
    int mask, num_hosts, num_subnets;

    printf("Enter IP address: ");
    scanf("%s", ip);

    if (!is_valid_ip(ip)) {
        printf("Invalid IP address.\n");
        return 1;
    }

    printf("Enter subnet mask (in bits): ");
    scanf("%d", &mask);

    calculate_subnets(ip, mask, &num_hosts, &num_subnets);

    printf("Number of hosts per subnet: %d\n", num_hosts);
    printf("Number of subnets: %d\n", num_subnets);

    return 0;
}