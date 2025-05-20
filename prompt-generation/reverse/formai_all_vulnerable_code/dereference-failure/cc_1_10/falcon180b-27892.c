//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 10

typedef struct {
    int num_subnets;
    int subnet_size;
    char *subnet_mask;
} SubnetInfo;

void generate_subnets(int num_subnets, int subnet_size, char *subnet_mask) {
    SubnetInfo subnets[MAX_SUBNETS];
    int i = 0;

    while (i < num_subnets) {
        int j;
        for (j = 0; j < subnet_size; j++) {
            if (subnet_mask[j] == '1') {
                break;
            }
        }
        subnets[i].subnet_size = j + 1;
        subnets[i].subnet_mask = (char *) malloc(subnets[i].subnet_size * sizeof(char));
        strncpy(subnets[i].subnet_mask, subnet_mask, subnets[i].subnet_size);
        subnets[i].subnet_mask[subnets[i].subnet_size - 1] = '\0';
        i++;
    }

    printf("Number of subnets: %d\n", num_subnets);
    printf("Subnet size: %d\n", subnet_size);
    printf("Subnet mask: %s\n", subnet_mask);

    for (i = 0; i < num_subnets; i++) {
        printf("Subnet %d:\n", i + 1);
        printf("Subnet mask: %s\n", subnets[i].subnet_mask);
        printf("Number of hosts: %d\n\n", (int) pow(2, subnets[i].subnet_size - 1) - 1);
    }
}

int main() {
    int num_subnets, subnet_size;
    char subnet_mask[16];

    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    printf("Enter the subnet size: ");
    scanf("%d", &subnet_size);

    printf("Enter the subnet mask (in binary): ");
    scanf("%s", subnet_mask);

    generate_subnets(num_subnets, subnet_size, subnet_mask);

    return 0;
}