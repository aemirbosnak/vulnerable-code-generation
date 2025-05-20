//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 32

typedef struct {
    char ip[16];
    char mask[16];
    char subnet[16];
} Subnet;

void generate_subnet(Subnet* subnet, char* ip, char* mask) {
    strcpy(subnet->ip, ip);
    strcpy(subnet->mask, mask);
    sprintf(subnet->subnet, "%s/%d", ip, atoi(mask) & 0xff);
}

int main() {
    Subnet subnets[MAX_SUBNETS];
    int num_subnets = 0;

    char ip[16];
    char mask[16];

    printf("Enter the IP address: ");
    scanf("%s", ip);

    printf("Enter the subnet mask: ");
    scanf("%s", mask);

    generate_subnet(&subnets[num_subnets], ip, mask);
    num_subnets++;

    int choice;
    while (1) {
        printf("\nChoose an option:\n");
        printf("1. Generate a new subnet\n");
        printf("2. Display all subnets\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (num_subnets >= MAX_SUBNETS) {
                    printf("Maximum number of subnets reached.\n");
                    break;
                }

                printf("Enter the IP address: ");
                scanf("%s", ip);

                printf("Enter the subnet mask: ");
                scanf("%s", mask);

                generate_subnet(&subnets[num_subnets], ip, mask);
                num_subnets++;
                break;

            case 2:
                for (int i = 0; i < num_subnets; i++) {
                    printf("%s %s %s\n", subnets[i].ip, subnets[i].mask, subnets[i].subnet);
                }
                break;

            case 3:
                exit(0);

            default:
                printf("Invalid option.\n");
        }
    }

    return 0;
}