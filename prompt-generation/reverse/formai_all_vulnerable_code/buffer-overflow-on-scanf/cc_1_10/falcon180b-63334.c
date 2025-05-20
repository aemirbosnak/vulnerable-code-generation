//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>

#define MAX_SUBNETS 100
#define MAX_SUBNET_SIZE 32
#define MAX_SUBNET_MASK 32

typedef struct {
    char name[32];
    int size;
    char mask[MAX_SUBNET_MASK];
    int num_hosts;
} subnet;

void subnet_calculation(subnet *subnets, int num_subnets, int num_hosts, int mask_size) {
    for (int i = 0; i < num_subnets; i++) {
        subnets[i].size = pow(2, mask_size);
        subnets[i].num_hosts = subnets[i].size - 2;
        strcpy(subnets[i].mask, "255.255.255.0");
    }
}

int main() {
    subnet subnets[MAX_SUBNETS];
    int num_subnets = 0;
    int num_hosts = 0;
    char input_string[100];
    char *token;

    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    printf("Enter the number of hosts per subnet: ");
    scanf("%d", &num_hosts);

    for (int i = 0; i < num_subnets; i++) {
        printf("Enter the name of subnet %d: ", i+1);
        scanf("%s", subnets[i].name);

        printf("Enter the size of subnet %d (in bits): ", i+1);
        scanf("%d", &subnets[i].size);

        printf("Enter the mask of subnet %d: ", i+1);
        scanf("%s", subnets[i].mask);

        if (strlen(subnets[i].mask) > MAX_SUBNET_MASK) {
            printf("Error: Mask is too long.\n");
            exit(1);
        }
    }

    subnet_calculation(subnets, num_subnets, num_hosts, 0);

    for (int i = 0; i < num_subnets; i++) {
        printf("Subnet %d: %s\n", i+1, subnets[i].name);
        printf("Subnet size: %d\n", subnets[i].size);
        printf("Subnet mask: %s\n", subnets[i].mask);
        printf("Number of hosts: %d\n\n", subnets[i].num_hosts);
    }

    return 0;
}