//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SUBNETS 10

typedef struct {
    char *name;
    int mask;
    int count;
    int max_hosts;
} subnet;

void create_subnet(subnet *s, char *name, int mask) {
    s->name = name;
    s->mask = mask;
    s->count = 0;
    s->max_hosts = (int)pow(2, 32 - mask);
}

int add_host(subnet *s) {
    if (s->count >= s->max_hosts) {
        return -1;
    }
    s->count++;
    return 0;
}

int main() {
    int n;
    char name[20];
    int mask;
    subnet subnets[MAX_SUBNETS];

    printf("Enter the number of subnets: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter the name of subnet %d: ", i+1);
        scanf("%s", name);
        printf("Enter the subnet mask for %s: ", name);
        scanf("%d", &mask);
        create_subnet(&subnets[i], name, mask);
    }

    int choice;
    do {
        printf("\nChoose an option:\n");
        printf("1. Add host\n");
        printf("2. Display subnets\n");
        printf("3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the subnet name: ");
                scanf("%s", name);
                for (int i = 0; i < n; i++) {
                    if (strcmp(name, subnets[i].name) == 0) {
                        if (add_host(&subnets[i]) == -1) {
                            printf("The subnet is full.\n");
                        } else {
                            printf("Host added successfully.\n");
                        }
                        break;
                    }
                }
                break;
            case 2:
                for (int i = 0; i < n; i++) {
                    printf("Subnet name: %s\nSubnet mask: %d\nCurrent hosts: %d\nMax hosts: %d\n", subnets[i].name, subnets[i].mask, subnets[i].count, subnets[i].max_hosts);
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