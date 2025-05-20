//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 10
#define MAX_SUBNET_SIZE 32
#define MAX_SUBNET_MASK 32
#define MAX_SUBNET_NAME 64

typedef struct {
    char name[MAX_SUBNET_NAME];
    char mask[MAX_SUBNET_MASK];
    int size;
} Subnet;

void initializeSubnet(Subnet* subnet) {
    strcpy(subnet->name, "");
    strcpy(subnet->mask, "");
    subnet->size = 0;
}

void printSubnet(Subnet subnet) {
    printf("Name: %s\n", subnet.name);
    printf("Mask: %s\n", subnet.mask);
    printf("Size: %d\n", subnet.size);
}

int getSubnetSize(char* mask) {
    int size = 0;
    int count = 0;

    for (int i = 0; i < strlen(mask); i++) {
        if (mask[i] == '1') {
            size++;
        } else if (mask[i] == '0') {
            count++;
        }
    }

    if (count == 0) {
        return 0;
    }

    return size * 8 - count;
}

int main() {
    int numSubnets = 0;
    Subnet subnets[MAX_SUBNETS];

    while (numSubnets < MAX_SUBNETS) {
        printf("Enter subnet name (or 'q' to quit): ");
        char name[MAX_SUBNET_NAME];
        scanf("%s", name);

        if (strcmp(name, "q") == 0) {
            break;
        }

        initializeSubnet(&subnets[numSubnets]);
        strcpy(subnets[numSubnets].name, name);

        printf("Enter subnet mask: ");
        char mask[MAX_SUBNET_MASK];
        scanf("%s", mask);

        strcpy(subnets[numSubnets].mask, mask);
        subnets[numSubnets].size = getSubnetSize(mask);

        numSubnets++;
    }

    printf("Subnet list:\n");
    for (int i = 0; i < numSubnets; i++) {
        printSubnet(subnets[i]);
    }

    return 0;
}