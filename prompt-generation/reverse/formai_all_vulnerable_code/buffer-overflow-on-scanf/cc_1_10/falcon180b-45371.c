//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: energetic
#include <stdio.h>
#include <string.h>

#define MAX_SUBNETS 100
#define MAX_SUBNET_SIZE 32
#define MAX_SUBNET_NAME 64

typedef struct {
    char name[MAX_SUBNET_NAME];
    char subnet[MAX_SUBNET_SIZE];
    int size;
} subnet_t;

int num_subnets = 0;
subnet_t subnets[MAX_SUBNETS];

void add_subnet(char* name, char* subnet, int size) {
    if (num_subnets >= MAX_SUBNETS) {
        printf("Error: Maximum number of subnets reached.\n");
        return;
    }

    strncpy(subnets[num_subnets].name, name, MAX_SUBNET_NAME);
    strncpy(subnets[num_subnets].subnet, subnet, MAX_SUBNET_SIZE);
    subnets[num_subnets].size = size;

    num_subnets++;
}

void print_subnets() {
    int i;

    for (i = 0; i < num_subnets; i++) {
        printf("Subnet %d:\n", i+1);
        printf("  Name: %s\n", subnets[i].name);
        printf("  Subnet: %s\n", subnets[i].subnet);
        printf("  Size: %d\n\n", subnets[i].size);
    }
}

int main() {
    char input[MAX_SUBNET_SIZE];
    char name[MAX_SUBNET_NAME];
    int size;

    printf("Enter subnet IP address: ");
    scanf("%s", input);

    printf("Enter subnet name: ");
    scanf("%s", name);

    printf("Enter subnet size: ");
    scanf("%d", &size);

    add_subnet(name, input, size);

    print_subnets();

    return 0;
}