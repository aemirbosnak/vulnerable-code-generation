//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 32
#define MAX_SUBNET_SIZE 32

typedef struct {
    char name[32];
    int num_subnets;
    int subnet_size;
    int subnet_count;
    int *subnets;
} SubnetCalculator;

void init_subnet_calculator(SubnetCalculator *sc) {
    memset(sc, 0, sizeof(SubnetCalculator));
}

int add_subnet(SubnetCalculator *sc, int subnet_size) {
    if (sc->subnet_count >= MAX_SUBNETS) {
        return -1;
    }

    sc->subnets = realloc(sc->subnets, sizeof(int) * (sc->subnet_count + 1));
    if (sc->subnets == NULL) {
        return -1;
    }

    sc->subnet_size = subnet_size;
    sc->subnet_count++;

    return 0;
}

int main() {
    SubnetCalculator sc;
    init_subnet_calculator(&sc);

    int choice;
    do {
        printf("=== Subnet Calculator ===\n");
        printf("1. Add subnet\n");
        printf("2. Display subnets\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter subnet name (max 32 characters): ");
            scanf("%s", sc.name);
            printf("Enter subnet size (1-32): ");
            scanf("%d", &sc.subnet_size);

            if (add_subnet(&sc, sc.subnet_size)!= 0) {
                printf("Error: Failed to add subnet.\n");
            } else {
                printf("Subnet added successfully.\n");
            }
            break;

        case 2:
            if (sc.subnet_count == 0) {
                printf("No subnets added.\n");
            } else {
                printf("Subnets:\n");
                for (int i = 0; i < sc.subnet_count; i++) {
                    printf("%s (%d)\n", sc.name, sc.subnet_size);
                }
            }
            break;

        case 3:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice.\n");
        }
    } while (choice!= 3);

    return 0;
}