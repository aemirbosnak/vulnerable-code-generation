//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int netmask(int prefix)
{
    unsigned int net_mask = 0xffffffff;
    net_mask <<= (32 - prefix);

    return net_mask;
}

void print_binary(unsigned int n)
{
    if (n >= 2)
        print_binary(n/2);
    printf("%c", n%2 ? '1' : '0');
}

int main()
{
    char ip_input[16];

    printf("Enter IP address in the format xxx.xxx.xxx.xxx: ");
    fgets(ip_input, 16, stdin);

    unsigned int ip_address = 0;
    char *token = strtok(ip_input, ".");

    for (int i = 0; token != NULL; i++)
    {
        ip_address += atoi(token) << ((3 - i) * 8);
        token = strtok(NULL, ".");
    }

    int prefix;

    printf("Enter subnet prefix: ");
    scanf("%d", &prefix);

    unsigned int subnet_mask = netmask(prefix);
    unsigned int network_address = ip_address & subnet_mask;
    unsigned int broadcast_address = network_address | ~subnet_mask;

    printf("IP Address: %u.%u.%u.%u\n", (ip_address >> 24) & 0xff, (ip_address >> 16) & 0xff, (ip_address >> 8) & 0xff, ip_address & 0xff);
    printf("Subnet Mask: %u.%u.%u.%u\n", (subnet_mask >> 24) & 0xff, (subnet_mask >> 16) & 0xff, (subnet_mask >> 8) & 0xff, subnet_mask & 0xff);
    printf("Network Address: %u.%u.%u.%u\n", (network_address >> 24) & 0xff, (network_address >> 16) & 0xff, (network_address >> 8) & 0xff, network_address & 0xff);
    printf("Broadcast Address: %u.%u.%u.%u\n", (broadcast_address >> 24) & 0xff, (broadcast_address >> 16) & 0xff, (broadcast_address >> 8) & 0xff, broadcast_address & 0xff);

    printf("Subnet Mask in binary form: ");
    print_binary(subnet_mask);
    printf("\n");

    return 0;
}