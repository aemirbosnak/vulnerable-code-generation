//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 10
#define MAX_SUBNET_SIZE 1000

typedef struct {
    char name[20];
    int size;
    int num_subnets;
    int subnets[MAX_SUBNETS];
} subnet_t;

void add_subnet(subnet_t *subnet, int size) {
    int i;
    for (i = 0; i < subnet->num_subnets; i++) {
        if (subnet->subnets[i] == size) {
            return;
        }
    }
    if (subnet->num_subnets >= MAX_SUBNETS) {
        printf("Error: Maximum number of subnets reached.\n");
        exit(1);
    }
    subnet->subnets[subnet->num_subnets++] = size;
}

int main() {
    subnet_t subnet;
    int i, j, num_subnets = 0;

    printf("Enter the name of the subnet (max 20 characters): ");
    scanf("%s", subnet.name);

    printf("Enter the size of the subnet (1-254): ");
    scanf("%d", &subnet.size);

    printf("Enter the number of subnets (1-%d): ", MAX_SUBNETS-1);
    scanf("%d", &num_subnets);

    printf("Enter the sizes of the subnets (1-%d): ", MAX_SUBNET_SIZE);
    for (i = 0; i < num_subnets; i++) {
        scanf("%d", &j);
        add_subnet(&subnet, j);
    }

    printf("\nSubnet: %s\n", subnet.name);
    printf("Size: %d\n", subnet.size);
    printf("Number of subnets: %d\n", num_subnets);
    printf("Subnet sizes:\n");
    for (i = 0; i < subnet.num_subnets; i++) {
        printf("%d\n", subnet.subnets[i]);
    }

    return 0;
}