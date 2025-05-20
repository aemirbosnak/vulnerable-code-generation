//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LINE_LEN 100

typedef struct Subnet {
    int id;
    char address[16];
    int mask;
} Subnet;

Subnet* subnets;
int num_subnets = 0;

void add_subnet() {
    char address[16];
    int mask;
    printf("Enter subnet address (e.g. 192.168.1.0): ");
    scanf("%s", address);
    printf("Enter subnet mask (e.g. 24): ");
    scanf("%d", &mask);
    printf("Subnet has been added!\n\n");

    Subnet subnet;
    subnet.id = num_subnets++;
    strcpy(subnet.address, address);
    subnet.mask = mask;

    subnets = (Subnet*)realloc(subnets, num_subnets * sizeof(Subnet));
    subnets[num_subnets - 1] = subnet;
}

void print_subnets() {
    printf("\nSubnets:\n");
    printf("ID\tAddress\t\t\tMask\n");
    printf("------------------------------------------\n");
    for (int i = 0; i < num_subnets; i++) {
        printf("%d\t%s\t%d\n", subnets[i].id, subnets[i].address, subnets[i].mask);
    }
    printf("\n");
}

void delete_subnet() {
    int id;
    printf("Enter subnet ID to delete: ");
    scanf("%d", &id);

    if (id >= num_subnets || id < 0) {
        printf("Invalid subnet ID!\n\n");
        return;
    }

    for (int i = id; i < num_subnets - 1; i++) {
        subnets[i] = subnets[i+1];
        subnets[i].id--;
    }
    num_subnets--;

    subnets = (Subnet*)realloc(subnets, num_subnets * sizeof(Subnet));
    printf("Subnet has been deleted!\n\n");
}

void calculate_subnets() {
    int total_hosts = 0;
    int subnet_id = -1;
    while (total_hosts <= 0) {
        print_subnets();
        printf("Enter subnet ID to calculate hosts (or -1 to exit): ");
        scanf("%d", &subnet_id);

        if (subnet_id == -1) {
            printf("Exiting subnet calculator...\n\n");
            return;
        }

        if (subnet_id < 0 || subnet_id >= num_subnets) {
            printf("Invalid subnet ID!\n\n");
            continue;
        }

        int mask = subnets[subnet_id].mask;
        total_hosts = (1 << (32 - mask)) - 2;
        printf("Total hosts for subnet %s/%d: %d\n\n", subnets[subnet_id].address, mask, total_hosts);
    }
}

int main() {
    subnets = (Subnet*)malloc(num_subnets * sizeof(Subnet));

    printf("Welcome to Subnet Calculator Multiplayer!\n");
    printf("=========================================\n\n");

    while (true) {
        printf("Choose an option (1-4):\n");
        printf("1. Add subnet\n");
        printf("2. Delete subnet\n");
        printf("3. Calculate hosts for subnet\n");
        printf("4. Exit program\n");

        char line[MAX_LINE_LEN];
        fgets(line, MAX_LINE_LEN, stdin);
        int choice = atoi(line);

        switch (choice) {
            case 1:
                add_subnet();
                break;
            case 2:
                delete_subnet();
                break;
            case 3:
                calculate_subnets();
                break;
            case 4:
                printf("Exiting subnet calculator...\n\n");
                exit(0);
            default:
                printf("Invalid option!\n\n");
                break;
        }
    }
    return 0;
}