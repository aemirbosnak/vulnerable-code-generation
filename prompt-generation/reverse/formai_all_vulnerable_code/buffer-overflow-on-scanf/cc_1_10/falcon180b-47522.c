//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 1000

typedef struct {
    char name[50];
    char ip[16];
    char mask[16];
    char gateway[16];
} subnet;

int num_subnets = 0;
subnet subnets[MAX_SUBNETS];

void add_subnet() {
    char input[100];
    printf("Enter subnet name: ");
    scanf("%s", input);
    strcpy(subnets[num_subnets].name, input);
    printf("Enter subnet IP address: ");
    scanf("%s", subnets[num_subnets].ip);
    printf("Enter subnet mask: ");
    scanf("%s", subnets[num_subnets].mask);
    printf("Enter subnet gateway: ");
    scanf("%s", subnets[num_subnets].gateway);
    num_subnets++;
}

void display_subnets() {
    printf("\nSubnet Name\tIP Address\tSubnet Mask\tGateway\n");
    for (int i = 0; i < num_subnets; i++) {
        printf("%s\t%s\t%s\t%s\n", subnets[i].name, subnets[i].ip, subnets[i].mask, subnets[i].gateway);
    }
}

int main() {
    printf("Welcome to the Subnet Calculator!\n");
    while (1) {
        printf("\n1. Add subnet\n2. Display subnets\n3. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            add_subnet();
            break;
        case 2:
            display_subnets();
            break;
        case 3:
            printf("Exiting program...\n");
            exit(0);
        default:
            printf("Invalid choice.\n");
        }
    }
    return 0;
}