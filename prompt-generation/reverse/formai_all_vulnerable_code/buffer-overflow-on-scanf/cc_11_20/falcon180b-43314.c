//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>

#define MAX_SUBNETS 10
#define MAX_SUBNET_SIZE 8

typedef struct {
    char name[20];
    int size;
} Subnet;

Subnet subnets[MAX_SUBNETS];

int main() {
    int i, j, num_subnets, size, total_hosts, host_id;
    char input[100];
    bool valid_input = true;

    printf("Enter the number of subnets (1-%d): ", MAX_SUBNETS);
    scanf("%d", &num_subnets);

    if (num_subnets < 1 || num_subnets > MAX_SUBNETS) {
        printf("Invalid number of subnets.\n");
        valid_input = false;
    }

    if (valid_input) {
        printf("Enter the subnet names (up to 20 characters):\n");
        for (i = 0; i < num_subnets; i++) {
            scanf("%s", subnets[i].name);
        }

        printf("Enter the subnet sizes (1-%d):\n", MAX_SUBNET_SIZE);
        for (i = 0; i < num_subnets; i++) {
            scanf("%d", &subnets[i].size);
        }

        printf("Enter the total number of hosts:\n");
        scanf("%d", &total_hosts);

        for (i = 0; i < num_subnets; i++) {
            size = subnets[i].size;
            if (size > MAX_SUBNET_SIZE || size < 1) {
                printf("Invalid subnet size for %s.\n", subnets[i].name);
                valid_input = false;
                break;
            }

            subnets[i].size = pow(2, size) - 2;

            if (subnets[i].size > total_hosts) {
                printf("Subnet %s is too large for the total number of hosts.\n", subnets[i].name);
                valid_input = false;
                break;
            }

            total_hosts -= subnets[i].size;
        }

        if (valid_input) {
            printf("Subnet calculations:\n");
            for (i = 0; i < num_subnets; i++) {
                printf("%s: %d hosts\n", subnets[i].name, subnets[i].size);
            }
        }
    }

    return 0;
}