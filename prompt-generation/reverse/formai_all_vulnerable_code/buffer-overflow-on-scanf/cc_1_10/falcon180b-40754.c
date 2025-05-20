//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SUBNETS 100
#define MAX_SUBNET_SIZE 32
#define MAX_SUBNET_MASK 32

typedef struct {
    char ip[16];
    char subnet[16];
    char mask[16];
} Subnet;

void generate_subnets(char *ip, int prefix_len, Subnet *subnets, int max_subnets) {
    int i, j, k, subnet_count = 0;
    char subnet_ip[16];
    int subnet_mask = 0;

    // Initialize subnet mask
    for (i = 0; i < prefix_len; i++) {
        subnet_mask |= (1 << (31 - i));
    }

    // Calculate number of subnets
    int num_subnets = (32 - prefix_len) + 1;

    // Calculate number of hosts per subnet
    int num_hosts = (32 - prefix_len) * 8 - 2;

    // Calculate first and last IP addresses of subnet
    char first_ip[16];
    char last_ip[16];
    strcpy(first_ip, ip);
    strcpy(last_ip, ip);
    for (i = 0; i < prefix_len; i++) {
        first_ip[i] = '0';
        last_ip[i] = '255';
    }

    // Generate subnets
    for (i = 0; i < num_subnets; i++) {
        if (subnet_count >= max_subnets) {
            break;
        }
        sprintf(subnet_ip, "%s.%d", first_ip, i);
        sprintf(subnets[subnet_count].ip, "%s", ip);
        sprintf(subnets[subnet_count].subnet, "%s", subnet_ip);
        sprintf(subnets[subnet_count].mask, "%d.%d.%d.%d", (subnet_mask >> 24) & 0xFF, (subnet_mask >> 16) & 0xFF, (subnet_mask >> 8) & 0xFF, subnet_mask & 0xFF);
        subnet_count++;
    }
}

void print_subnets(Subnet *subnets, int subnet_count) {
    int i;
    for (i = 0; i < subnet_count; i++) {
        printf("IP: %s\nSubnet: %s\nMask: %s\n\n", subnets[i].ip, subnets[i].subnet, subnets[i].mask);
    }
}

int main() {
    char ip[16];
    int prefix_len;
    Subnet subnets[MAX_SUBNETS];
    int subnet_count = 0;

    // Get IP address from user
    printf("Enter IP address: ");
    scanf("%s", ip);

    // Get prefix length from user
    printf("Enter prefix length: ");
    scanf("%d", &prefix_len);

    // Validate prefix length
    if (prefix_len < 0 || prefix_len > 32) {
        printf("Invalid prefix length.\n");
        return 1;
    }

    // Generate subnets
    generate_subnets(ip, prefix_len, subnets, MAX_SUBNETS);

    // Print subnets
    print_subnets(subnets, subnet_count);

    return 0;
}