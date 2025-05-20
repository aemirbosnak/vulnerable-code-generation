//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 10
#define MAX_SUBNET_SIZE 16

typedef struct {
    char name[32];
    int size;
} Subnet;

Subnet subnets[MAX_SUBNETS];
int num_subnets;

void add_subnet(char *name, int size) {
    if (num_subnets >= MAX_SUBNETS) {
        printf("Error: Too many subnets!\n");
        exit(1);
    }
    strncpy(subnets[num_subnets].name, name, 31);
    subnets[num_subnets].name[31] = '\0';
    subnets[num_subnets].size = size;
    num_subnets++;
}

void print_subnets() {
    printf("Subnets:\n");
    for (int i = 0; i < num_subnets; i++) {
        printf("%s (%d IPs)\n", subnets[i].name, (int)pow(2, subnets[i].size) - 2);
    }
}

int main() {
    char ip[16];
    int size;

    printf("Welcome to the Subnet Calculator!\n");

    while (1) {
        printf("\nEnter an IP address or type 'list' to see the current subnets:\n");
        scanf("%s", ip);

        if (strcmp(ip, "list") == 0) {
            print_subnets();
        } else {
            size = atoi(ip);
            if (size < 1 || size > MAX_SUBNET_SIZE) {
                printf("Error: Invalid subnet size.\n");
            } else {
                add_subnet(ip, size);
            }
        }
    }

    return 0;
}