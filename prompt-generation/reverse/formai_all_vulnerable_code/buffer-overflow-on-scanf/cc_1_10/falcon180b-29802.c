//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 10
#define IP_LEN 15
#define MASK_LEN 4

typedef struct {
    char ip[IP_LEN];
    char mask[MASK_LEN];
    char subnet[IP_LEN];
} Subnet;

void calculate_subnet(Subnet *subnet) {
    int i;
    char *ptr;

    for (i = 0; i < strlen(subnet->ip); i++) {
        if (subnet->ip[i] == '.') {
            strncat(subnet->subnet, subnet->ip, i);
            strncat(subnet->subnet, ".", 1);
        }
    }

    strcat(subnet->subnet, "0");
    strcat(subnet->subnet, "0");
    strcat(subnet->subnet, "0");
    strcat(subnet->subnet, "0");

    ptr = strrchr(subnet->subnet, '.');
    ptr[0] = '\0';

    strcat(subnet->subnet, "1");
}

int main() {
    int num_subnets;
    Subnet subnets[MAX_SUBNETS];

    printf("Enter the IP address: ");
    scanf("%s", subnets[0].ip);

    printf("Enter the subnet mask: ");
    scanf("%s", subnets[0].mask);

    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    if (num_subnets > MAX_SUBNETS) {
        printf("Maximum number of subnets is %d.\n", MAX_SUBNETS);
        exit(1);
    }

    for (int i = 0; i < num_subnets; i++) {
        strcpy(subnets[i].ip, subnets[0].ip);
        strcpy(subnets[i].mask, subnets[0].mask);

        calculate_subnet(&subnets[i]);

        printf("Subnet %d: %s\n", i+1, subnets[i].subnet);
    }

    return 0;
}