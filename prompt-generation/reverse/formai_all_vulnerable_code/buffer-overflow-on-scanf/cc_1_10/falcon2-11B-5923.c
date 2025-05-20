//Falcon2-11B DATASET v1.0 Category: Subnet Calculator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct subnet
{
    unsigned char net_addr[4];
    unsigned char subnet_mask[4];
    unsigned char broadcast_addr[4];
    unsigned int prefix_length;
    unsigned int max_hosts;
    unsigned int usable_hosts;
};

int main()
{
    struct subnet *subnet = (struct subnet*) malloc(sizeof(struct subnet));
    subnet->prefix_length = 24;
    subnet->max_hosts = 0xffffffff;
    subnet->usable_hosts = 0;
    subnet->net_addr[0] = 0;
    subnet->net_addr[1] = 0;
    subnet->net_addr[2] = 0;
    subnet->net_addr[3] = 0;
    subnet->subnet_mask[0] = 0;
    subnet->subnet_mask[1] = 0;
    subnet->subnet_mask[2] = 0;
    subnet->subnet_mask[3] = 0;
    subnet->broadcast_addr[0] = 0;
    subnet->broadcast_addr[1] = 0;
    subnet->broadcast_addr[2] = 0;
    subnet->broadcast_addr[3] = 0;

    printf("Subnet Calculator\n");
    printf("Enter subnet mask (e.g. 255.255.255.0): ");
    scanf("%hhx%hhx%hhx%hhx", &subnet->subnet_mask[0], &subnet->subnet_mask[1], &subnet->subnet_mask[2], &subnet->subnet_mask[3]);
    printf("Subnet mask: ");
    for (int i = 0; i < 4; i++) {
        printf("%hhx ", subnet->subnet_mask[i]);
    }
    printf("\n");

    printf("Enter network address (e.g. 10.0.0.0): ");
    scanf("%hhx%hhx%hhx%hhx", &subnet->net_addr[0], &subnet->net_addr[1], &subnet->net_addr[2], &subnet->net_addr[3]);
    printf("Network address: ");
    for (int i = 0; i < 4; i++) {
        printf("%hhx ", subnet->net_addr[i]);
    }
    printf("\n");

    printf("Enter broadcast address (e.g. 10.255.255.255): ");
    scanf("%hhx%hhx%hhx%hhx", &subnet->broadcast_addr[0], &subnet->broadcast_addr[1], &subnet->broadcast_addr[2], &subnet->broadcast_addr[3]);
    printf("Broadcast address: ");
    for (int i = 0; i < 4; i++) {
        printf("%hhx ", subnet->broadcast_addr[i]);
    }
    printf("\n");

    subnet->prefix_length = 8;
    subnet->max_hosts = 0xffff;
    subnet->usable_hosts = 0;
    subnet->net_addr[0] = 0;
    subnet->net_addr[1] = 0;
    subnet->net_addr[2] = 0;
    subnet->net_addr[3] = 0;
    subnet->subnet_mask[0] = 0;
    subnet->subnet_mask[1] = 0;
    subnet->subnet_mask[2] = 0;
    subnet->subnet_mask[3] = 0;
    subnet->broadcast_addr[0] = 0;
    subnet->broadcast_addr[1] = 0;
    subnet->broadcast_addr[2] = 0;
    subnet->broadcast_addr[3] = 0;

    printf("Subnet Calculator (2)\n");
    printf("Enter subnet mask (e.g. 255.255.255.0): ");
    scanf("%hhx%hhx%hhx%hhx", &subnet->subnet_mask[0], &subnet->subnet_mask[1], &subnet->subnet_mask[2], &subnet->subnet_mask[3]);
    printf("Subnet mask: ");
    for (int i = 0; i < 4; i++) {
        printf("%hhx ", subnet->subnet_mask[i]);
    }
    printf("\n");

    printf("Enter network address (e.g. 10.0.0.0): ");
    scanf("%hhx%hhx%hhx%hhx", &subnet->net_addr[0], &subnet->net_addr[1], &subnet->net_addr[2], &subnet->net_addr[3]);
    printf("Network address: ");
    for (int i = 0; i < 4; i++) {
        printf("%hhx ", subnet->net_addr[i]);
    }
    printf("\n");

    printf("Enter broadcast address (e.g. 10.255.255.255): ");
    scanf("%hhx%hhx%hhx%hhx", &subnet->broadcast_addr[0], &subnet->broadcast_addr[1], &subnet->broadcast_addr[2], &subnet->broadcast_addr[3]);
    printf("Broadcast address: ");
    for (int i = 0; i < 4; i++) {
        printf("%hhx ", subnet->broadcast_addr[i]);
    }
    printf("\n");

    subnet->prefix_length = 16;
    subnet->max_hosts = 0xffff;
    subnet->usable_hosts = 0;
    subnet->net_addr[0] = 0;
    subnet->net_addr[1] = 0;
    subnet->net_addr[2] = 0;
    subnet->net_addr[3] = 0;
    subnet->subnet_mask[0] = 0;
    subnet->subnet_mask[1] = 0;
    subnet->subnet_mask[2] = 0;
    subnet->subnet_mask[3] = 0;
    subnet->broadcast_addr[0] = 0;
    subnet->broadcast_addr[1] = 0;
    subnet->broadcast_addr[2] = 0;
    subnet->broadcast_addr[3] = 0;

    printf("Subnet Calculator (3)\n");
    printf("Enter subnet mask (e.g. 255.255.255.0): ");
    scanf("%hhx%hhx%hhx%hhx", &subnet->subnet_mask[0], &subnet->subnet_mask[1], &subnet->subnet_mask[2], &subnet->subnet_mask[3]);
    printf("Subnet mask: ");
    for (int i = 0; i < 4; i++) {
        printf("%hhx ", subnet->subnet_mask[i]);
    }
    printf("\n");

    printf("Enter network address (e.g. 10.0.0.0): ");
    scanf("%hhx%hhx%hhx%hhx", &subnet->net_addr[0], &subnet->net_addr[1], &subnet->net_addr[2], &subnet->net_addr[3]);
    printf("Network address: ");
    for (int i = 0; i < 4; i++) {
        printf("%hhx ", subnet->net_addr[i]);
    }
    printf("\n");

    printf("Enter broadcast address (e.g. 10.255.255.255): ");
    scanf("%hhx%hhx%hhx%hhx", &subnet->broadcast_addr[0], &subnet->broadcast_addr[1], &subnet->broadcast_addr[2], &subnet->broadcast_addr[3]);
    printf("Broadcast address: ");
    for (int i = 0; i < 4; i++) {
        printf("%hhx ", subnet->broadcast_addr[i]);
    }
    printf("\n");

    return 0;
}