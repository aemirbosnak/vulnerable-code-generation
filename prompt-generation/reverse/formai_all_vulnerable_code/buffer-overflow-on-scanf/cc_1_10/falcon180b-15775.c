//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNETS 10

struct subnet {
    char name[20];
    int ip;
    int mask;
};

int main() {
    int num_subnets;
    struct subnet subnets[MAX_SUBNETS];
    char input_buffer[100];

    printf("Enter the number of subnets to calculate: ");
    scanf("%d", &num_subnets);

    printf("\nEnter the subnet information:\n");
    for (int i = 0; i < num_subnets; i++) {
        printf("Subnet %d:\n", i+1);
        printf("Name: ");
        scanf("%s", subnets[i].name);
        printf("IP address: ");
        scanf("%d", &subnets[i].ip);
        printf("Subnet mask: ");
        scanf("%d", &subnets[i].mask);
    }

    printf("\nSubnet calculations:\n");
    for (int i = 0; i < num_subnets; i++) {
        printf("Subnet %d:\n", i+1);
        printf("Name: %s\n", subnets[i].name);
        printf("IP address: %d\n", subnets[i].ip);
        printf("Subnet mask: %d\n", subnets[i].mask);
        printf("Network address: ");
        sprintf(input_buffer, "%d.%d.%d.%d",
            (subnets[i].ip >> 24) & 0xFF,
            (subnets[i].ip >> 16) & 0xFF,
            (subnets[i].ip >> 8) & 0xFF,
            subnets[i].ip & 0xFF);
        printf("%s\n", input_buffer);
        printf("Broadcast address: ");
        sprintf(input_buffer, "%d.%d.%d.%d",
            (subnets[i].ip >> 24) & 0xFF,
            (subnets[i].ip >> 16) & 0xFF,
            (subnets[i].ip >> 8) & 0xFF,
            (subnets[i].ip | ~subnets[i].mask) & 0xFF);
        printf("%s\n", input_buffer);
        printf("Number of hosts: %d\n\n", (int)pow(2, 32 - subnets[i].mask));
    }

    return 0;
}