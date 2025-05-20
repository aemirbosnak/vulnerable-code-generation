//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 10
#define MAX_SUBNET_SIZE 32

typedef struct {
    char name[64];
    char ip[16];
    char mask[16];
    int subnet_size;
} subnet_t;

int num_subnets = 0;
subnet_t subnets[MAX_SUBNETS];

void add_subnet(char* name, char* ip, char* mask, int size) {
    if (num_subnets >= MAX_SUBNETS) {
        printf("Error: Maximum number of subnets reached.\n");
        return;
    }

    strcpy(subnets[num_subnets].name, name);
    strcpy(subnets[num_subnets].ip, ip);
    strcpy(subnets[num_subnets].mask, mask);
    subnets[num_subnets].subnet_size = size;

    num_subnets++;
}

void print_subnets() {
    printf("Subnets:\n");
    for (int i = 0; i < num_subnets; i++) {
        printf("Name: %s\n", subnets[i].name);
        printf("IP: %s\n", subnets[i].ip);
        printf("Mask: %s\n", subnets[i].mask);
        printf("Subnet Size: %d\n\n", subnets[i].subnet_size);
    }
}

int main() {
    char input[1024];
    char* token;

    printf("Welcome to the Subnet Calculator!\n");

    while (fgets(input, sizeof(input), stdin)) {
        token = strtok(input, " ");

        if (strcmp(token, "add") == 0) {
            token = strtok(NULL, " ");
            add_subnet(token, "192.168.1.0", "255.255.255.0", 24);
        } else if (strcmp(token, "print") == 0) {
            print_subnets();
        }
    }

    return 0;
}