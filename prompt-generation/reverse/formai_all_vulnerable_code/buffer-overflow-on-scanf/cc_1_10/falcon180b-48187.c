//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SUBNET_SIZE 32

struct subnet {
    char name[MAX_SUBNET_SIZE];
    int size;
};

int main() {
    int num_subnets, i;
    struct subnet subnets[MAX_SUBNET_SIZE];
    char input[MAX_SUBNET_SIZE];
    char *token;
    int subnet_size;

    // Get number of subnets
    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    // Get subnet names and sizes
    for (i = 0; i < num_subnets; i++) {
        printf("Enter subnet %d name: ", i+1);
        scanf("%s", subnets[i].name);
        printf("Enter subnet %d size: ", i+1);
        scanf("%s", input);

        // Convert input to integer
        subnet_size = 0;
        token = strtok(input, " ");
        while (token!= NULL) {
            subnet_size = subnet_size * 10 + atoi(token);
            token = strtok(NULL, " ");
        }

        // Check for invalid input
        if (subnet_size <= 0 || subnet_size > 32) {
            printf("Invalid subnet size.\n");
            return 1;
        }

        subnets[i].size = subnet_size;
    }

    // Calculate subnet masks
    for (i = 0; i < num_subnets; i++) {
        printf("Subnet %s mask: ", subnets[i].name);
        printf("%d.%d.%d.%d\n", (256 >> subnets[i].size) & 0xff, (256 >> (subnets[i].size - 8)) & 0xff, (256 >> (subnets[i].size - 16)) & 0xff, (256 >> (subnets[i].size - 24)) & 0xff);
    }

    return 0;
}