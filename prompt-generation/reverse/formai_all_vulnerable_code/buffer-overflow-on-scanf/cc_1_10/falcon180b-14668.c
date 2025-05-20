//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: lively
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SUBNETS 20

typedef struct {
    char *name;
    char *ip;
    char *mask;
} subnet;

void add_subnet(subnet *subnets, int count, char *name, char *ip, char *mask) {
    if (count >= MAX_SUBNETS) {
        printf("Error: Maximum number of subnets reached.\n");
        return;
    }

    subnets[count].name = strdup(name);
    subnets[count].ip = strdup(ip);
    subnets[count].mask = strdup(mask);

    printf("Subnet added successfully.\n");
}

void list_subnets(subnet *subnets, int count) {
    printf("Subnets:\n");
    for (int i = 0; i < count; i++) {
        printf("Name: %s\n", subnets[i].name);
        printf("IP: %s\n", subnets[i].ip);
        printf("Mask: %s\n\n", subnets[i].mask);
    }
}

int main() {
    subnet subnets[MAX_SUBNETS];
    int count = 0;

    while (count < MAX_SUBNETS) {
        printf("Enter subnet name: ");
        char name[50];
        scanf("%s", name);

        printf("Enter subnet IP: ");
        char ip[20];
        scanf("%s", ip);

        printf("Enter subnet mask: ");
        char mask[20];
        scanf("%s", mask);

        add_subnet(subnets, count, name, ip, mask);
        count++;
    }

    list_subnets(subnets, count);

    return 0;
}