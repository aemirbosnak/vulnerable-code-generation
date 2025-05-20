//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 10

struct subnet {
    int ip;
    int mask;
    int count;
};

void add_subnet(struct subnet *subnets, int num_subnets, int ip, int mask) {
    int i;

    for (i = 0; i < num_subnets; i++) {
        if (subnets[i].ip == ip && subnets[i].mask == mask) {
            subnets[i].count++;
            return;
        }
    }

    if (num_subnets >= MAX_SUBNETS) {
        printf("Error: Maximum number of subnets reached.\n");
        exit(1);
    }

    subnets[num_subnets].ip = ip;
    subnets[num_subnets].mask = mask;
    subnets[num_subnets].count = 1;
    num_subnets++;
}

void print_subnets(struct subnet *subnets, int num_subnets) {
    int i;

    for (i = 0; i < num_subnets; i++) {
        printf("%d.%d.%d.%d/%d (%d hosts)\n",
            (subnets[i].ip >> 24) & 0xFF,
            (subnets[i].ip >> 16) & 0xFF,
            (subnets[i].ip >> 8) & 0xFF,
            subnets[i].ip & 0xFF,
            subnets[i].mask,
            subnets[i].count);
    }
}

int main(int argc, char *argv[]) {
    int num_subnets = 0;
    struct subnet subnets[MAX_SUBNETS];

    if (argc < 2) {
        printf("Usage: %s <IP address> <netmask>\n", argv[0]);
        return 1;
    }

    if (sscanf(argv[1], "%d.%d.%d.%d", &subnets[num_subnets].ip, &subnets[num_subnets].ip, &subnets[num_subnets].ip, &subnets[num_subnets].ip)!= 4) {
        printf("Error: Invalid IP address format.\n");
        return 1;
    }

    if (sscanf(argv[2], "%d.%d.%d.%d", &subnets[num_subnets].mask, &subnets[num_subnets].mask, &subnets[num_subnets].mask, &subnets[num_subnets].mask)!= 4) {
        printf("Error: Invalid netmask format.\n");
        return 1;
    }

    add_subnet(subnets, num_subnets, subnets[num_subnets].ip, subnets[num_subnets].mask);

    print_subnets(subnets, num_subnets);

    return 0;
}