//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 100
#define MAX_SUBNET_SIZE 32
#define MAX_SUBNET_MASK_SIZE 16

typedef struct {
    char name[MAX_SUBNET_SIZE];
    char mask[MAX_SUBNET_MASK_SIZE];
    int num_hosts;
} Subnet;

void generate_subnet_mask(char* mask, int size) {
    int i;
    for (i = 0; i < size; i++) {
        mask[i] = '1';
    }
    mask[size] = '\0';
}

int count_bits(char* mask) {
    int count = 0;
    while (*mask!= '\0') {
        if (*mask == '1') {
            count++;
        }
        mask++;
    }
    return count;
}

int main() {
    int num_subnets, i;
    char input[MAX_SUBNET_SIZE];
    Subnet subnets[MAX_SUBNETS];

    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    printf("Enter the subnet names and masks (format: name mask):\n");
    for (i = 0; i < num_subnets; i++) {
        scanf("%s %s", input, input + MAX_SUBNET_SIZE);
        strcpy(subnets[i].name, input);
        generate_subnet_mask(subnets[i].mask, MAX_SUBNET_MASK_SIZE);
        subnets[i].num_hosts = count_bits(subnets[i].mask);
    }

    printf("Subnet\tMask\t\tNumber of Hosts\n");
    for (i = 0; i < num_subnets; i++) {
        printf("%s\t%s\t\t%d\n", subnets[i].name, subnets[i].mask, subnets[i].num_hosts);
    }

    return 0;
}