//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 256
#define MAX_SUBNET_SIZE 32
#define MAX_SUBNET_MASK_SIZE 4

typedef struct {
    char name[64];
    int num_subnets;
    char subnet_mask[MAX_SUBNET_MASK_SIZE + 1];
    char subnets[MAX_SUBNETS][MAX_SUBNET_SIZE + 1];
} SubnetCalculator;

void init_subnet_calculator(SubnetCalculator* sc) {
    memset(sc, 0, sizeof(SubnetCalculator));
}

void add_subnet(SubnetCalculator* sc, const char* subnet_str) {
    if (sc->num_subnets >= MAX_SUBNETS) {
        printf("Error: Too many subnets!\n");
        return;
    }

    strncpy(sc->subnets[sc->num_subnets], subnet_str, MAX_SUBNET_SIZE);
    sc->num_subnets++;
}

void calculate_subnets(SubnetCalculator* sc) {
    int i, j, k, subnet_size = strlen(sc->subnets[0]);

    if (subnet_size < 1 || subnet_size > MAX_SUBNET_SIZE) {
        printf("Error: Invalid subnet size!\n");
        return;
    }

    for (i = 0; i < sc->num_subnets; i++) {
        if (strlen(sc->subnets[i])!= subnet_size) {
            printf("Error: Subnets must be of equal size!\n");
            return;
        }
    }

    for (i = 0; i < sc->num_subnets; i++) {
        for (j = 0; j < subnet_size; j++) {
            if (sc->subnets[i][j] == '*') {
                for (k = 0; k < MAX_SUBNET_MASK_SIZE; k++) {
                    if (sc->subnet_mask[k] == '*') {
                        sc->subnet_mask[k] = '0' + (j % 10);
                        break;
                    }
                }
            } else {
                if (sc->subnet_mask[j] == '*') {
                    sc->subnet_mask[j] = sc->subnets[i][j];
                } else if (sc->subnet_mask[j]!= sc->subnets[i][j]) {
                    printf("Error: Subnet mask must match subnet!\n");
                    return;
                }
            }
        }
    }

    printf("Subnet mask: %s\n", sc->subnet_mask);

    for (i = 0; i < sc->num_subnets; i++) {
        printf("Subnet %d: %s\n", i + 1, sc->subnets[i]);
    }
}

int main() {
    SubnetCalculator sc;
    init_subnet_calculator(&sc);

    while (1) {
        printf("Enter a subnet (or type 'done' to calculate):\n");
        char subnet_str[MAX_SUBNET_SIZE + 1];
        scanf("%s", subnet_str);

        if (strcmp(subnet_str, "done") == 0) {
            break;
        }

        add_subnet(&sc, subnet_str);
    }

    calculate_subnets(&sc);

    return 0;
}