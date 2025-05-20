//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 32
#define MAX_SUBNET_SIZE 32

typedef struct {
    char name[MAX_SUBNET_SIZE];
    int size;
} Subnet;

void print_subnets(Subnet subnets[], int num_subnets) {
    for (int i = 0; i < num_subnets; i++) {
        printf("%s (%d)\n", subnets[i].name, subnets[i].size);
    }
}

int main() {
    char input[MAX_SUBNET_SIZE];
    int num_subnets = 0;
    Subnet subnets[MAX_SUBNETS];

    printf("Enter the IP address: ");
    scanf("%s", input);

    int num_octets = 0;
    char *token = strtok(input, ".");
    while (token!= NULL) {
        num_octets++;
        token = strtok(NULL, ".");
    }

    if (num_octets < 2) {
        printf("Invalid IP address.\n");
        return 1;
    }

    int subnet_size = 32 - num_octets;
    int mask = 0xFFFFFFFF << subnet_size;

    printf("Enter the subnet name: ");
    scanf("%s", input);
    strcpy(subnets[num_subnets].name, input);
    subnets[num_subnets].size = subnet_size;
    num_subnets++;

    while (num_subnets < MAX_SUBNETS && num_octets >= subnet_size) {
        printf("Enter the subnet name: ");
        scanf("%s", input);
        strcpy(subnets[num_subnets].name, input);
        subnets[num_subnets].size = subnet_size;
        num_subnets++;

        subnet_size -= 8;
        mask = (mask >> 8) | 0xFF000000;
    }

    print_subnets(subnets, num_subnets);

    return 0;
}