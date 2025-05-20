//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    unsigned int address;
    unsigned int mask;
    unsigned int network;
    unsigned int broadcast;
    unsigned int hostmin;
    unsigned int hostmax;
    unsigned int hosts;
} subnet_info;

void print_subnet_info(subnet_info *info)
{
    printf("---------------------------------------------------------------------\n");
    printf("Subnet Calculator\n");
    printf("---------------------------------------------------------------------\n");
    printf("IP Address: %s\n", inet_ntoa(info->address));
    printf("Subnet Mask: %s\n", inet_ntoa(info->mask));
    printf("Network Address: %s\n", inet_ntoa(info->network));
    printf("Broadcast Address: %s\n", inet_ntoa(info->broadcast));
    printf("Host Minimum: %s\n", inet_ntoa(info->hostmin));
    printf("Host Maximum: %s\n", inet_ntoa(info->hostmax));
    printf("Number of Hosts: %u\n", info->hosts);
    printf("---------------------------------------------------------------------\n");
}

int main()
{
    char ip_address[16];
    char subnet_mask[16];
    unsigned int address, mask, network, broadcast, hostmin, hostmax, hosts;

    printf("Enter the IP address: ");
    scanf("%s", ip_address);

    printf("Enter the subnet mask: ");
    scanf("%s", subnet_mask);

    address = inet_addr(ip_address);
    mask = inet_addr(subnet_mask);

    network = address & mask;
    broadcast = network | ~mask;
    hostmin = network + 1;
    hostmax = broadcast - 1;
    hosts = (1 << (32 - bitcount(mask))) - 2;

    subnet_info info = {address, mask, network, broadcast, hostmin, hostmax, hosts};

    print_subnet_info(&info);

    return 0;
}

int bitcount(unsigned int n)
{
    int count = 0;
    while (n)
    {
        count += n & 1;
        n >>= 1;
    }
    return count;
}