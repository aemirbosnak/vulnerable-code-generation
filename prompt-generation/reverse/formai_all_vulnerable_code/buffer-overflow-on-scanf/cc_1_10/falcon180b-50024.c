//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 100
#define MAX_SUBNET_SIZE 32
#define MAX_SUBNET_MASK 32

typedef struct {
    char name[MAX_SUBNET_SIZE];
    char ip[MAX_SUBNET_SIZE];
    char mask[MAX_SUBNET_MASK];
} Subnet;

int main(int argc, char *argv[]) {
    int num_subnets = 0;
    Subnet *subnets = NULL;

    printf("Welcome to the Subnet Calculator!\n");
    printf("How many subnets do you want to calculate? ");
    scanf("%d", &num_subnets);

    subnets = malloc(num_subnets * sizeof(Subnet));

    for (int i = 0; i < num_subnets; i++) {
        printf("\nSubnet %d:\n", i+1);
        printf("Name: ");
        scanf("%s", subnets[i].name);

        printf("IP address: ");
        scanf("%s", subnets[i].ip);

        printf("Subnet mask: ");
        scanf("%s", subnets[i].mask);
    }

    printf("\nCalculating subnets...\n");

    for (int i = 0; i < num_subnets; i++) {
        char *token = strtok(subnets[i].ip, ".");
        int octet1 = atoi(token);
        int octet2 = atoi(token = strtok(NULL, "."));
        int octet3 = atoi(token = strtok(NULL, "."));
        int octet4 = atoi(token = strtok(NULL, "."));

        int subnet_size = octet1 & subnets[i].mask[0];
        int subnet_ip = octet1 | (subnets[i].mask[0] << 8);

        printf("\nSubnet %d:\n", i+1);
        printf("Name: %s\n", subnets[i].name);
        printf("IP address: %s\n", subnets[i].ip);
        printf("Subnet mask: %s\n", subnets[i].mask);
        printf("Subnet size: %d\n", subnet_size);
        printf("Subnet IP: %d.%d.%d.%d\n\n", octet1, octet2, octet3, octet4);
    }

    return 0;
}