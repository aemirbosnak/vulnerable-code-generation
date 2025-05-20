//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 1000
#define MAX_SUBNET_SIZE 1000
#define MAX_SUBNET_MASK_LENGTH 32

typedef struct {
    char ip[16];
    char mask[16];
    int size;
} subnet_t;

subnet_t subnets[MAX_SUBNETS];
int num_subnets = 0;

void add_subnet(char *ip, int size) {
    char mask[16];
    sprintf(mask, "255.255.255.%d", (32 - size));
    subnet_t new_subnet;
    strcpy(new_subnet.ip, ip);
    strcpy(new_subnet.mask, mask);
    new_subnet.size = size;
    subnets[num_subnets] = new_subnet;
    num_subnets++;
}

int main() {
    char input[1000];
    char *ip, *mask;
    int size;

    printf("Enter IP address: ");
    scanf("%s", input);

    ip = strtok(input, ".");
    mask = strtok(NULL, ".");

    if (mask == NULL) {
        printf("Invalid IP address\n");
        return 1;
    }

    size = atoi(mask);

    if (size < 1 || size > 32) {
        printf("Invalid subnet mask\n");
        return 1;
    }

    add_subnet(ip, size);

    printf("Subnet IP: %s\n", subnets[0].ip);
    printf("Subnet mask: %s\n", subnets[0].mask);
    printf("Subnet size: %d\n", subnets[0].size);

    return 0;
}