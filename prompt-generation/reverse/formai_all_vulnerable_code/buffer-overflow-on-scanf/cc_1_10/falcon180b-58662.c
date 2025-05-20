//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SUBNETS 1000
#define IP_ADDRESS_SIZE 16
#define SUBNET_MASK_SIZE 16
#define SUBNET_SIZE_MIN 8
#define SUBNET_SIZE_MAX 30
#define SUBNET_MASK_MIN "255.0.0.0"
#define SUBNET_MASK_MAX "255.255.255.254"

typedef struct {
    char ip_address[IP_ADDRESS_SIZE];
    char subnet_mask[SUBNET_MASK_SIZE];
    int subnet_size;
} Subnet;

void print_subnet(Subnet *subnet) {
    printf("IP Address: %s\n", subnet->ip_address);
    printf("Subnet Mask: %s\n", subnet->subnet_mask);
    printf("Subnet Size: %d\n", subnet->subnet_size);
}

void generate_subnets(int num_subnets, int subnet_size, char *ip_address, char *subnet_mask) {
    Subnet subnets[MAX_SUBNETS];
    int i, j;

    for (i = 0; i < num_subnets; i++) {
        for (j = 0; j < subnet_size; j++) {
            subnets[i].subnet_mask[j] = subnet_mask[j];
        }
        subnets[i].subnet_mask[subnet_size] = '\0';

        sprintf(subnets[i].ip_address, "%s.%d", ip_address, i + 1);
        subnets[i].subnet_size = subnet_size;
    }

    for (i = 0; i < num_subnets; i++) {
        print_subnet(&subnets[i]);
    }
}

int main() {
    char ip_address[IP_ADDRESS_SIZE], subnet_mask[SUBNET_MASK_SIZE];
    int num_subnets, subnet_size;

    printf("Enter IP Address: ");
    scanf("%s", ip_address);

    printf("Enter Subnet Mask: ");
    scanf("%s", subnet_mask);

    printf("Enter Number of Subnets: ");
    scanf("%d", &num_subnets);

    printf("Enter Subnet Size (between %d and %d): ", SUBNET_SIZE_MIN, SUBNET_SIZE_MAX);
    scanf("%d", &subnet_size);

    if (subnet_size < SUBNET_SIZE_MIN || subnet_size > SUBNET_SIZE_MAX) {
        printf("Invalid subnet size.\n");
        return 1;
    }

    generate_subnets(num_subnets, subnet_size, ip_address, subnet_mask);

    return 0;
}