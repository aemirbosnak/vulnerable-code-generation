//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 1000
#define MAX_SUBNET_SIZE 32
#define MAX_SUBNET_MASK 32

struct subnet {
    char name[MAX_SUBNET_SIZE];
    char mask[MAX_SUBNET_MASK];
    int size;
};

int num_subnets = 0;
struct subnet subnets[MAX_SUBNETS];

void add_subnet(char *name, char *mask, int size) {
    if (num_subnets >= MAX_SUBNETS) {
        printf("Error: Maximum number of subnets reached.\n");
        return;
    }
    strncpy(subnets[num_subnets].name, name, MAX_SUBNET_SIZE);
    strncpy(subnets[num_subnets].mask, mask, MAX_SUBNET_MASK);
    subnets[num_subnets].size = size;
    num_subnets++;
}

void print_subnets() {
    printf("Subnets:\n");
    for (int i = 0; i < num_subnets; i++) {
        printf("%s/%d (%d hosts)\n", subnets[i].name, subnets[i].size, subnets[i].size - 2);
    }
}

int main() {
    char input[MAX_SUBNET_SIZE + MAX_SUBNET_MASK + 1];
    int size;
    while (1) {
        printf("Enter subnet (name/mask) or type 'quit' to exit: ");
        scanf("%s", input);
        if (strcmp(input, "quit") == 0) {
            break;
        }
        char *name = strtok(input, "/");
        char *mask_str = strtok(NULL, "/");
        if (name == NULL || mask_str == NULL) {
            printf("Invalid subnet format.\n");
            continue;
        }
        strncpy(subnets[num_subnets - 1].name, name, MAX_SUBNET_SIZE);
        strncpy(subnets[num_subnets - 1].mask, mask_str, MAX_SUBNET_MASK);
        if (sscanf(mask_str, "%d", &size)!= 1 || size < 1 || size > 32) {
            printf("Invalid subnet mask.\n");
            continue;
        }
        subnets[num_subnets - 1].size = size;
    }
    print_subnets();
    return 0;
}