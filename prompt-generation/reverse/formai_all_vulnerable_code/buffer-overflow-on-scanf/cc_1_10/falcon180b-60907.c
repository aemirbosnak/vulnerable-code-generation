//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 256
#define MAX_SUBNET_SIZE 32
#define MAX_SUBNET_MASK_LEN 32

typedef struct {
    char name[64];
    int subnet_size;
    int subnet_mask_len;
    unsigned long subnet_mask;
    unsigned long subnet_broadcast;
} subnet_t;

subnet_t subnets[MAX_SUBNETS];
int num_subnets = 0;

void add_subnet(char *name, int subnet_size, int subnet_mask_len, unsigned long subnet_mask, unsigned long subnet_broadcast) {
    if (num_subnets >= MAX_SUBNETS) {
        printf("Error: Maximum number of subnets reached.\n");
        return;
    }

    strcpy(subnets[num_subnets].name, name);
    subnets[num_subnets].subnet_size = subnet_size;
    subnets[num_subnets].subnet_mask_len = subnet_mask_len;
    subnets[num_subnets].subnet_mask = subnet_mask;
    subnets[num_subnets].subnet_broadcast = subnet_broadcast;

    num_subnets++;
}

void print_subnets() {
    printf("Subnets:\n");
    for (int i = 0; i < num_subnets; i++) {
        printf("%s (%d hosts)\n", subnets[i].name, (int)pow(2, subnets[i].subnet_size) - 2);
    }
}

int main() {
    char input[MAX_SUBNET_SIZE];
    int subnet_size, subnet_mask_len;
    unsigned long subnet_mask, subnet_broadcast;

    printf("Enter subnet IP address: ");
    scanf("%s", input);

    subnet_mask_len = atoi(input);

    subnet_mask = 0xffffffff << (32 - subnet_mask_len);
    subnet_broadcast = (unsigned long)htonl((unsigned int)0xffffffff | ~subnet_mask);

    add_subnet(input, subnet_mask_len, subnet_mask_len, subnet_mask, subnet_broadcast);

    print_subnets();

    return 0;
}