//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SUBNETS 100
#define MAX_SUBNET_SIZE 32
#define MAX_SUBNET_NAME 64

typedef struct {
    char name[MAX_SUBNET_NAME];
    char address[MAX_SUBNET_SIZE];
    int prefix;
} subnet_t;

int num_subnets = 0;
subnet_t subnets[MAX_SUBNETS];

void add_subnet(char *name, char *address, int prefix) {
    if (num_subnets >= MAX_SUBNETS) {
        printf("Error: Maximum number of subnets reached.\n");
        return;
    }

    strncpy(subnets[num_subnets].name, name, MAX_SUBNET_NAME);
    strncpy(subnets[num_subnets].address, address, MAX_SUBNET_SIZE);
    subnets[num_subnets].prefix = prefix;

    num_subnets++;
}

void print_subnets() {
    printf("Subnets:\n");
    for (int i = 0; i < num_subnets; i++) {
        printf("%s (%s) - Prefix: %d\n", subnets[i].name, subnets[i].address, subnets[i].prefix);
    }
}

int main() {
    char input[1024];
    char name[MAX_SUBNET_NAME];
    char address[MAX_SUBNET_SIZE];
    int prefix;

    printf("Enter subnet name (max %d characters): ", MAX_SUBNET_NAME);
    fgets(name, MAX_SUBNET_NAME, stdin);
    name[strcspn(name, "\n")] = '\0';

    printf("Enter subnet address: ");
    fgets(address, MAX_SUBNET_SIZE, stdin);
    address[strcspn(address, "\n")] = '\0';

    printf("Enter subnet prefix (1-32): ");
    scanf("%d", &prefix);

    add_subnet(name, address, prefix);
    print_subnets();

    return 0;
}