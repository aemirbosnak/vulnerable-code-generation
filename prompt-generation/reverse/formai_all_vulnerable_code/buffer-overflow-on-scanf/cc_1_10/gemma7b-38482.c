//Gemma-7B DATASET v1.0 Category: Subnet Calculator ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SUBNETS 256

typedef struct subnet
{
    int address;
    int mask;
    int broadcast;
    int usable_hosts;
} subnet;

subnet subnet_calc(int address, int mask)
{
    subnet subnet;

    subnet.address = address;
    subnet.mask = mask;

    subnet.broadcast = address | ~mask;
    subnet.usable_hosts = (subnet.mask & ~address) / 2 + 1;

    return subnet;
}

int main()
{
    int address, mask, i, subnet_num = 0;
    subnet subnet_list[MAX_SUBNETS];

    printf("Enter the number of subnets: ");
    scanf("%d", &subnet_num);

    for (i = 0; i < subnet_num; i++)
    {
        printf("Enter the subnet address: ");
        scanf("%d", &address);

        printf("Enter the subnet mask: ");
        scanf("%d", &mask);

        subnet subnet = subnet_calc(address, mask);

        subnet_list[i] = subnet;
    }

    printf("\nSubnet information:\n");

    for (i = 0; i < subnet_num; i++)
    {
        printf("Subnet Address: %d\n", subnet_list[i].address);
        printf("Subnet Mask: %d\n", subnet_list[i].mask);
        printf("Broadcast Address: %d\n", subnet_list[i].broadcast);
        printf("Usable Hosts: %d\n", subnet_list[i].usable_hosts);
        printf("\n");
    }

    return 0;
}