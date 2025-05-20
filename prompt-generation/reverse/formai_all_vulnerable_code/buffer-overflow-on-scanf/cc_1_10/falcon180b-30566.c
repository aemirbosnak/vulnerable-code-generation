//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 10

struct subnet {
    char ip[16];
    char mask[16];
    char gateway[16];
};

int main() {
    int num_subnets;
    struct subnet subnets[MAX_SUBNETS];

    printf("Welcome to the Excited C Subnet Calculator!\n");
    printf("How many subnets do you want to calculate? ");
    scanf("%d", &num_subnets);

    if (num_subnets > MAX_SUBNETS) {
        printf("Sorry, you can only calculate up to %d subnets at a time.\n", MAX_SUBNETS);
        return 1;
    }

    printf("Enter the IP address and mask for each subnet:\n");

    for (int i = 0; i < num_subnets; i++) {
        printf("Subnet %d:\n", i+1);
        printf("IP address: ");
        scanf("%s", subnets[i].ip);
        printf("Mask: ");
        scanf("%s", subnets[i].mask);

        printf("Calculating subnet...\n");

        char gateway_ip[16];
        strcpy(gateway_ip, subnets[i].ip);
        strcat(gateway_ip, ".1");

        strcpy(subnets[i].gateway, gateway_ip);

        printf("Subnet %d:\n", i+1);
        printf("IP address: %s\n", subnets[i].ip);
        printf("Mask: %s\n", subnets[i].mask);
        printf("Gateway: %s\n", subnets[i].gateway);
        printf("\n");
    }

    return 0;
}