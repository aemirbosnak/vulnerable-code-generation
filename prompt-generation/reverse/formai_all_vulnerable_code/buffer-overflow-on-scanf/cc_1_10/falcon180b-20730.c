//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 100

typedef struct {
    char name[20];
    int ip_address;
    int subnet_mask;
    int gateway;
} Subnet;

void add_subnet(Subnet subnets[], int num_subnets) {
    char input[100];
    printf("Enter the name of the subnet: ");
    scanf("%s", input);
    strcpy(subnets[num_subnets].name, input);

    printf("Enter the IP address of the subnet: ");
    scanf("%d", &subnets[num_subnets].ip_address);

    printf("Enter the subnet mask of the subnet: ");
    scanf("%d", &subnets[num_subnets].subnet_mask);

    printf("Enter the gateway of the subnet: ");
    scanf("%d", &subnets[num_subnets].gateway);

    num_subnets++;
}

void print_subnets(Subnet subnets[], int num_subnets) {
    printf("Subnet Name\tIP Address\tSubnet Mask\tGateway\n");
    for (int i = 0; i < num_subnets; i++) {
        printf("%s\t%d\t%d\t%d\n", subnets[i].name, subnets[i].ip_address, subnets[i].subnet_mask, subnets[i].gateway);
    }
}

int main() {
    Subnet subnets[MAX_SUBNETS];
    int num_subnets = 0;

    while (num_subnets < MAX_SUBNETS) {
        printf("Enter 1 to add a subnet or 0 to quit: ");
        int choice;
        scanf("%d", &choice);

        if (choice == 1) {
            add_subnet(subnets, num_subnets);
        } else if (choice!= 0) {
            printf("Invalid input. Please try again.\n");
        }
    }

    printf("Subnets:\n");
    print_subnets(subnets, num_subnets);

    return 0;
}