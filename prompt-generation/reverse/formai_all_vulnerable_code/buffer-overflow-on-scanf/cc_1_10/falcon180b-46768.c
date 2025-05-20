//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 10

struct subnet {
    char name[50];
    char ip[16];
    char mask[16];
    int num_hosts;
};

int num_subnets = 0;
struct subnet subnets[MAX_SUBNETS];

void add_subnet() {
    if (num_subnets >= MAX_SUBNETS) {
        printf("Error: Maximum number of subnets reached.\n");
        return;
    }

    printf("Enter subnet name (max 50 characters): ");
    scanf("%s", subnets[num_subnets].name);

    printf("Enter subnet IP address: ");
    scanf("%s", subnets[num_subnets].ip);

    printf("Enter subnet mask: ");
    scanf("%s", subnets[num_subnets].mask);

    subnets[num_subnets].num_hosts = 0;
    num_subnets++;
}

void remove_subnet() {
    int i, found = 0;

    printf("Enter subnet name to remove: ");
    scanf("%s", subnets[0].name);

    for (i = 0; i < num_subnets; i++) {
        if (strcmp(subnets[i].name, subnets[0].name) == 0) {
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Subnet not found.\n");
        return;
    }

    subnets[i].num_hosts = 0;
    num_subnets--;
}

void list_subnets() {
    int i;

    printf("Subnets:\n");
    for (i = 0; i < num_subnets; i++) {
        printf("%s (%s/%s) - %d hosts\n", subnets[i].name, subnets[i].ip, subnets[i].mask, subnets[i].num_hosts);
    }
}

void calculate_hosts() {
    int i;

    for (i = 0; i < num_subnets; i++) {
        int num_bits = 0;
        char mask_str[16];
        strcpy(mask_str, subnets[i].mask);

        while (mask_str[num_bits] == '1') {
            num_bits++;
        }

        subnets[i].num_hosts = (int)pow(2, num_bits - 1) - 2;
    }
}

int main() {
    int choice;

    do {
        printf("1. Add subnet\n");
        printf("2. Remove subnet\n");
        printf("3. List subnets\n");
        printf("4. Calculate hosts\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_subnet();
                break;
            case 2:
                remove_subnet();
                break;
            case 3:
                list_subnets();
                break;
            case 4:
                calculate_hosts();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice!= 5);

    return 0;
}