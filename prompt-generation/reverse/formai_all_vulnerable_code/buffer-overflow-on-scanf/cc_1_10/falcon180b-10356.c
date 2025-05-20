//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 10
#define MAX_SUBNET_SIZE 100
#define MAX_SUBNET_MASK_LENGTH 32
#define MAX_SUBNET_MASK_VALUE 0xFFFFFFFF

typedef struct {
    char name[50];
    int size;
    char mask_value[16];
    int mask_length;
} subnet;

int main() {
    int num_subnets;
    subnet subnets[MAX_SUBNETS];

    printf("Welcome to the Medieval Subnet Calculator!\n");
    printf("How many subnets would you like to calculate? ");
    scanf("%d", &num_subnets);

    for (int i = 0; i < num_subnets; i++) {
        printf("Enter the name of subnet %d: ", i+1);
        scanf("%s", subnets[i].name);

        printf("Enter the size of subnet %s: ", subnets[i].name);
        scanf("%d", &subnets[i].size);

        printf("Enter the subnet mask value for subnet %s (in hexadecimal): ", subnets[i].name);
        scanf("%s", subnets[i].mask_value);

        printf("Enter the subnet mask length for subnet %s: ", subnets[i].name);
        scanf("%d", &subnets[i].mask_length);
    }

    printf("\nSubnet calculations:\n");
    for (int i = 0; i < num_subnets; i++) {
        printf("Subnet %s:\n", subnets[i].name);
        printf("Size: %d\n", subnets[i].size);
        printf("Subnet mask value: %s\n", subnets[i].mask_value);
        printf("Subnet mask length: %d\n", subnets[i].mask_length);
        printf("Subnet mask in binary: ");
        for (int j = 0; j < subnets[i].mask_length; j++) {
            printf("%d", (subnets[i].mask_value[j] - '0'));
        }
        printf("\n");
    }

    return 0;
}