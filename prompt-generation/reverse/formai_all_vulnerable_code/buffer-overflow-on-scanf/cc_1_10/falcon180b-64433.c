//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 100
#define MAX_SUBNET_SIZE 32
#define MAX_SUBNET_MASK_SIZE 16

typedef struct subnet {
    char name[MAX_SUBNET_SIZE];
    char mask[MAX_SUBNET_MASK_SIZE];
    int num_hosts;
} subnet_t;

int main() {
    int num_subnets;
    char input_str[100];
    char *token;
    subnet_t subnets[MAX_SUBNETS];
    int i, j;

    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    for (i = 0; i < num_subnets; i++) {
        printf("Enter the subnet name (up to %d characters): ", MAX_SUBNET_SIZE - 1);
        scanf("%s", subnets[i].name);

        printf("Enter the subnet mask (up to %d characters): ", MAX_SUBNET_MASK_SIZE - 1);
        scanf("%s", subnets[i].mask);

        subnets[i].num_hosts = 0;
    }

    printf("Enter the IP addresses:\n");
    while (fgets(input_str, sizeof(input_str), stdin)!= NULL) {
        token = strtok(input_str, " \t\n");
        while (token!= NULL) {
            for (i = 0; i < num_subnets; i++) {
                if (strcmp(subnets[i].mask, token) == 0) {
                    subnets[i].num_hosts++;
                    break;
                }
            }
            token = strtok(NULL, " \t\n");
        }
    }

    printf("\nSubnet Name\tSubnet Mask\tNumber of Hosts\n");
    for (i = 0; i < num_subnets; i++) {
        printf("%s\t\t%s\t\t%d\n", subnets[i].name, subnets[i].mask, subnets[i].num_hosts);
    }

    return 0;
}