//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 100
#define MAX_SUBNET_SIZE 32
#define MAX_SUBNET_MASK 32
#define MAX_IPS_PER_SUBNET 254

typedef struct {
    char subnet[MAX_SUBNET_SIZE];
    char mask[MAX_SUBNET_MASK];
    int num_ips;
} subnet_t;

void generate_subnet(char* ip, char* mask, int num_ips, subnet_t* subnet) {
    int i;
    for (i = 0; i < strlen(ip); i++) {
        if (ip[i] == '.') {
            subnet->subnet[i] = '.';
            subnet->mask[i] = '.';
        } else {
            subnet->subnet[i] = ip[i];
            subnet->mask[i] = mask[i];
        }
    }
    subnet->subnet[strlen(ip)] = '\0';
    subnet->mask[strlen(mask)] = '\0';
    subnet->num_ips = num_ips;
}

void print_subnet(subnet_t* subnet) {
    printf("Subnet: %s\n", subnet->subnet);
    printf("Mask: %s\n", subnet->mask);
    printf("Number of IPs: %d\n", subnet->num_ips);
}

int main() {
    int num_subnets, num_ips_per_subnet;
    char ip[MAX_SUBNET_SIZE];
    char mask[MAX_SUBNET_MASK];
    subnet_t subnets[MAX_SUBNETS];

    printf("Enter the IP address: ");
    scanf("%s", ip);

    printf("Enter the subnet mask: ");
    scanf("%s", mask);

    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    printf("Enter the number of IPs per subnet: ");
    scanf("%d", &num_ips_per_subnet);

    int i, j, k;
    for (i = 0; i < num_subnets; i++) {
        generate_subnet(ip, mask, num_ips_per_subnet, &subnets[i]);
        printf("Subnet %d:\n", i+1);
        print_subnet(&subnets[i]);
    }

    return 0;
}