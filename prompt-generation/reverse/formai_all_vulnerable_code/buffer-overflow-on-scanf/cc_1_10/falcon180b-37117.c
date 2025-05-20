//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 256
#define MAX_SUBNET_SIZE 32
#define MAX_SUBNET_MASK 32

typedef struct {
    char name[32];
    int num_subnets;
    int subnet_size;
    int subnet_mask;
    int *subnets;
} Subnet;

int get_int_input(char *prompt) {
    int value;
    printf("%s: ", prompt);
    scanf("%d", &value);
    return value;
}

void generate_subnets(Subnet *subnet) {
    int i, j, k;
    int num_hosts = (int)pow(2, subnet->subnet_size) - 2; // subtract 2 for network and broadcast addresses
    int num_subnets = subnet->num_subnets;
    int subnet_mask = subnet->subnet_mask;

    subnet->subnets = malloc(num_subnets * sizeof(int));

    for (i = 0; i < num_subnets; i++) {
        for (j = 0; j < num_hosts; j++) {
            for (k = 0; k < subnet_mask; k++) {
                if ((i << k) & 0xff) {
                    subnet->subnets[i] |= (1 << j);
                    break;
                }
            }
        }
    }
}

int main() {
    int num_subnets, subnet_size, subnet_mask;
    char subnet_name[32];
    Subnet *subnets = malloc(MAX_SUBNETS * sizeof(Subnet));
    int num_subnets_used = 0;

    printf("Enter the number of subnets: ");
    num_subnets = get_int_input("");

    printf("Enter the subnet size (1-32): ");
    subnet_size = get_int_input("");

    printf("Enter the subnet mask (1-32): ");
    subnet_mask = get_int_input("");

    while (num_subnets_used < num_subnets) {
        printf("Enter a subnet name (leave blank to finish): ");
        scanf("%s", subnet_name);

        if (strlen(subnet_name) == 0) {
            break;
        }

        Subnet *subnet = &subnets[num_subnets_used];
        strcpy(subnet->name, subnet_name);
        subnet->num_subnets = num_subnets - num_subnets_used;
        subnet->subnet_size = subnet_size;
        subnet->subnet_mask = subnet_mask;
        num_subnets_used++;
    }

    for (int i = 0; i < num_subnets_used; i++) {
        generate_subnets(&subnets[i]);
        printf("Subnet %s:\n", subnets[i].name);
        for (int j = 0; j < subnets[i].num_subnets; j++) {
            printf("%d.%d.%d.%d\n", j >> 24, (j >> 16) & 0xff, (j >> 8) & 0xff, j & 0xff);
        }
    }

    return 0;
}