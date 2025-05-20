//Gemma-7B DATASET v1.0 Category: Subnet Calculator ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNET_SIZE 256

typedef struct Subnet
{
    int network_address;
    int subnet_mask;
    int host_mask;
    int broadcast_address;
    int num_hosts;
} Subnet;

Subnet calculate_subnet(int network_address, int subnet_mask)
{
    Subnet subnet;

    subnet.network_address = network_address & subnet_mask;
    subnet.subnet_mask = subnet_mask;
    subnet.host_mask = ~subnet_mask & MAX_SUBNET_SIZE;
    subnet.broadcast_address = subnet.network_address | subnet.host_mask;
    subnet.num_hosts = (subnet.host_mask & MAX_SUBNET_SIZE) - 1;

    return subnet;
}

int main()
{
    int network_address;
    int subnet_mask;
    Subnet subnet;

    printf("Enter network address:");
    scanf("%d", &network_address);

    printf("Enter subnet mask:");
    scanf("%d", &subnet_mask);

    subnet = calculate_subnet(network_address, subnet_mask);

    printf("Subnet Information:");
    printf("\nNetwork Address: %d", subnet.network_address);
    printf("\nSubnet Mask: %d", subnet.subnet_mask);
    printf("\nBroadcast Address: %d", subnet.broadcast_address);
    printf("\nNumber of Hosts: %d", subnet.num_hosts);

    return 0;
}