//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SUBNETS 1000

struct subnet {
    char name[32];
    int num_hosts;
    int first_ip;
    int last_ip;
};

int num_subnets = 0;
struct subnet subnets[MAX_SUBNETS];

void add_subnet(char* name, int num_hosts, int first_ip, int last_ip) {
    if (num_subnets >= MAX_SUBNETS) {
        printf("Error: Maximum number of subnets reached.\n");
        return;
    }

    strcpy(subnets[num_subnets].name, name);
    subnets[num_subnets].num_hosts = num_hosts;
    subnets[num_subnets].first_ip = first_ip;
    subnets[num_subnets].last_ip = last_ip;

    num_subnets++;
}

void print_subnet(int index) {
    printf("Subnet %d:\n", index + 1);
    printf("Name: %s\n", subnets[index].name);
    printf("Number of hosts: %d\n", subnets[index].num_hosts);
    printf("First IP: %d.%d.%d.%d\n", (subnets[index].first_ip >> 24) & 0xFF, (subnets[index].first_ip >> 16) & 0xFF, (subnets[index].first_ip >> 8) & 0xFF, subnets[index].first_ip & 0xFF);
    printf("Last IP: %d.%d.%d.%d\n", (subnets[index].last_ip >> 24) & 0xFF, (subnets[index].last_ip >> 16) & 0xFF, (subnets[index].last_ip >> 8) & 0xFF, subnets[index].last_ip & 0xFF);
}

void print_all_subnets() {
    if (num_subnets == 0) {
        printf("No subnets added.\n");
        return;
    }

    printf("All subnets:\n");
    for (int i = 0; i < num_subnets; i++) {
        print_subnet(i);
    }
}

int main() {
    char name[32];
    int num_hosts, first_ip, last_ip;

    printf("Welcome to the Subnet Calculator!\n");

    while (1) {
        printf("\nWhat would you like to do?\n");
        printf("1. Add a subnet\n");
        printf("2. Print all subnets\n");
        printf("3. Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the name of the subnet (up to 32 characters): ");
                scanf("%s", name);

                printf("Enter the number of hosts in the subnet: ");
                scanf("%d", &num_hosts);

                printf("Enter the first IP address in the subnet: ");
                scanf("%d.%d.%d.%d", &first_ip, &first_ip, &first_ip, &first_ip);

                printf("Enter the last IP address in the subnet: ");
                scanf("%d.%d.%d.%d", &last_ip, &last_ip, &last_ip, &last_ip);

                add_subnet(name, num_hosts, first_ip, last_ip);
                break;

            case 2:
                print_all_subnets();
                break;

            case 3:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice.\n");
        }
    }

    return 0;
}