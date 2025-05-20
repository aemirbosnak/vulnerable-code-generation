//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 50

typedef struct {
    char ip[15];
    char mask[15];
    char broadcast[15];
    char subnet[15];
} subnet_t;

void generate_subnets(subnet_t *subnets, int num_subnets, char *ip, char *mask) {
    for (int i = 0; i < num_subnets; i++) {
        sprintf(subnets[i].ip, "%s.%d", ip, i+1);
        sprintf(subnets[i].subnet, "%s.%d.0.0", ip, i+1);
        sprintf(subnets[i].mask, "%s.%d.255.255", ip, i+1);
        sprintf(subnets[i].broadcast, "%s.%d.255.255", ip, i+1);
    }
}

int main() {
    char ip[15];
    char mask[15];

    printf("Enter the IP address: ");
    scanf("%s", ip);

    printf("Enter the subnet mask: ");
    scanf("%s", mask);

    subnet_t subnets[MAX_SUBNETS];
    int num_subnets;

    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    if (num_subnets > MAX_SUBNETS) {
        printf("Error: Maximum number of subnets is %d\n", MAX_SUBNETS);
        exit(1);
    }

    generate_subnets(subnets, num_subnets, ip, mask);

    printf("\nSubnet IP\tSubnet Mask\tBroadcast IP\n");
    for (int i = 0; i < num_subnets; i++) {
        printf("%s\t%s\t%s\n", subnets[i].ip, subnets[i].mask, subnets[i].broadcast);
    }

    return 0;
}