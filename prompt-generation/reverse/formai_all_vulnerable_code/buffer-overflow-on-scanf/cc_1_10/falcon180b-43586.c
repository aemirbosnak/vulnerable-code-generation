//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 10
#define MAX_SUBNET_SIZE 32
#define MAX_SUBNET_MASKS 32

typedef struct {
    char name[64];
    char ip[16];
    char mask[16];
    char broadcast[16];
    char first_host[16];
    char last_host[16];
} Subnet;

void print_subnet(Subnet *subnet) {
    printf("Subnet Name: %s\n", subnet->name);
    printf("IP Address: %s\n", subnet->ip);
    printf("Subnet Mask: %s\n", subnet->mask);
    printf("Broadcast Address: %s\n", subnet->broadcast);
    printf("First Host: %s\n", subnet->first_host);
    printf("Last Host: %s\n", subnet->last_host);
}

int main() {
    int num_subnets;
    Subnet subnets[MAX_SUBNETS];
    char input[1024];

    printf("Enter the number of subnets to calculate (up to %d): ", MAX_SUBNETS);
    scanf("%d", &num_subnets);

    for (int i = 0; i < num_subnets; i++) {
        printf("Enter the subnet name for subnet %d: ", i+1);
        scanf("%s", subnets[i].name);

        printf("Enter the IP address for subnet %d: ", i+1);
        scanf("%s", subnets[i].ip);

        printf("Enter the subnet mask for subnet %d: ", i+1);
        scanf("%s", subnets[i].mask);

        int mask_bits = atoi(subnets[i].mask);
        int host_bits = 32 - mask_bits;

        strcpy(subnets[i].broadcast, subnets[i].ip);
        strcat(subnets[i].broadcast, "255");

        for (int j = 0; j < host_bits; j++) {
            strcat(subnets[i].broadcast, "0");
        }

        strcpy(subnets[i].first_host, subnets[i].ip);
        strcat(subnets[i].first_host, "1");

        strcpy(subnets[i].last_host, subnets[i].ip);
        strcat(subnets[i].last_host, "254");
    }

    printf("Subnet Calculations:\n");
    for (int i = 0; i < num_subnets; i++) {
        print_subnet(&subnets[i]);
    }

    return 0;
}