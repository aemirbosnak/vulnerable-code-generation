//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 32
#define MAX_SUBNET_SIZE 32

typedef struct {
    char name[32];
    int num_subnets;
    int subnet_size;
} Subnet;

int main() {
    int num_subnets;
    char input_string[1024];
    Subnet subnets[MAX_SUBNETS];
    int i, j, k, start, end, subnet_size;

    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    for (i = 0; i < num_subnets; i++) {
        printf("Enter subnet %d name: ", i + 1);
        scanf("%s", subnets[i].name);

        printf("Enter the number of hosts per subnet: ");
        scanf("%d", &subnets[i].num_subnets);

        printf("Enter the subnet size in CIDR notation (e.g. /24): ");
        scanf("%s", input_string);

        start = strcspn(input_string, "/");
        end = strcspn(input_string + start, "/");
        subnet_size = atoi(input_string + start + 1);

        if (subnet_size > 32 || subnet_size < 1) {
            printf("Invalid subnet size.\n");
            exit(1);
        }

        subnets[i].subnet_size = subnet_size;
    }

    printf("\nSubnet information:\n");
    printf("--------------------\n");
    printf("Subnet\t\tIP Address Range\n");

    for (i = 0; i < num_subnets; i++) {
        start = 0;
        end = subnets[i].num_subnets - 1;

        for (j = start; j <= end; j++) {
            k = (j / subnets[i].subnet_size) * subnets[i].subnet_size;

            printf("%s\t\t", subnets[i].name);
            printf("%d.%d.%d.%d - ", (k >> 24) & 0xFF, (k >> 16) & 0xFF, (k >> 8) & 0xFF, k & 0xFF);
        }
    }

    return 0;
}