//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SUBNETS 32
#define MAX_IP_LEN 15
#define MAX_MASK_LEN 15

typedef struct {
    char ip[MAX_IP_LEN];
    char mask[MAX_MASK_LEN];
    char subnet[MAX_IP_LEN];
} Subnet;

void add_subnet(Subnet *subnets, int num_subnets, char *ip, char *mask) {
    if (num_subnets >= MAX_SUBNETS) {
        printf("Error: Too many subnets.\n");
        return;
    }

    Subnet *new_subnet = &subnets[num_subnets];
    strcpy(new_subnet->ip, ip);
    strcpy(new_subnet->mask, mask);
    sprintf(new_subnet->subnet, "%s/%d", ip, atoi(mask) + 8);
    num_subnets++;
}

void print_subnets(Subnet *subnets, int num_subnets) {
    for (int i = 0; i < num_subnets; i++) {
        printf("Subnet %d:\n", i+1);
        printf("IP: %s\n", subnets[i].ip);
        printf("Mask: %s\n", subnets[i].mask);
        printf("Subnet: %s\n\n", subnets[i].subnet);
    }
}

int main() {
    char ip[MAX_IP_LEN];
    char mask[MAX_MASK_LEN];
    Subnet subnets[MAX_SUBNETS];
    int num_subnets = 0;

    printf("Enter the IP address: ");
    scanf("%s", ip);

    printf("Enter the subnet mask: ");
    scanf("%s", mask);

    add_subnet(subnets, num_subnets, ip, mask);

    int choice;
    do {
        printf("\n");
        printf("1. Add another subnet\n");
        printf("2. Print subnets\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            add_subnet(subnets, num_subnets, ip, mask);
            break;
        case 2:
            print_subnets(subnets, num_subnets);
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