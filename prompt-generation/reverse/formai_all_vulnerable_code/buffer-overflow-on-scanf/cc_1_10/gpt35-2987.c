//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: realistic
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include<unistd.h>
#include<math.h>

uint32_t calculate_host_bits(uint32_t subnet)
{// This function returns the number of bits in the host portion of the subnet mask
    uint32_t host_bits = 0;
    while(subnet & 0x01 != 0x01 && subnet != 0x00000000)
    {
        subnet >>= 1;
        host_bits++;
    }
    return host_bits;
}

void print_binary(uint8_t byte)
{// This function prints the binary representation of a byte
    for(int i = 7; i >= 0; i--)
    {
        if(byte & (1 << i))
            printf("1");
        else
            printf("0");
    }
    printf(" ");
}

void print_subnet_mask(uint32_t subnet)
{// This function prints the subnet mask in dotted decimal and binary form
    printf("Subnet mask: ");
    for(int i = 0; i < 4; i++)
    {
        printf("%d.", ((subnet >> (i*8)) & 0xff));
    }
    printf("\n            ");
    for(int i = 0; i < 4; i++)
    {
        print_binary((subnet >> (i*8)) & 0xff);
    }
    printf("\n");
}

void print_host_bits(uint32_t subnet)
{// This function prints the number of host bits in the subnet mask
    uint32_t host_bits = calculate_host_bits(subnet);
    printf("Number of host bits: %d\n", host_bits);
}

void print_hosts(uint32_t subnet)
{// This function prints the number of hosts in the subnet
    uint32_t host_bits = calculate_host_bits(subnet);
    printf("Number of hosts: %d\n", (1 << host_bits) - 2);
}

void print_network_address(uint32_t ip, uint32_t subnet)
{// This function prints the network address in dotted decimal and binary form
    uint32_t network_address = ip & subnet;
    printf("Network address: ");
    for(int i = 0; i < 4; i++)
    {
        printf("%d.", ((network_address >> (i*8)) & 0xff));
    }
    printf("\n                 ");
    for(int i = 0; i < 4; i++)
    {
        print_binary((network_address >> (i*8)) & 0xff);
    }
    printf("\n");
}

void print_broadcast_address(uint32_t ip, uint32_t subnet)
{// This function prints the broadcast address in dotted decimal and binary form
    uint32_t host_bits = calculate_host_bits(subnet);
    uint32_t broadcast_address = (ip & subnet) | ((1 << host_bits) - 1);
    printf("Broadcast address: ");
    for(int i = 0; i < 4; i++)
    {
        printf("%d.", ((broadcast_address >> (i*8)) & 0xff));
    }
    printf("\n                    ");
    for(int i = 0; i < 4; i++)
    {
        print_binary((broadcast_address >> (i*8)) & 0xff);
    }
    printf("\n");
}

void print_address_range(uint32_t ip, uint32_t subnet)
{// This function prints the usable address range
    uint32_t host_bits = calculate_host_bits(subnet);
    uint32_t network_address = ip & subnet;
    uint32_t broadcast_address = (ip & subnet) | ((1 << host_bits) - 1);
    printf("Usable address range: ");
    for(int i = 0; i < 4; i++)
    {
        if(i == 3)// Skip the last octet in the network address and broadcast address
        {
            printf("%d - %d\n", (network_address >> (i*8)) & 0xff, (broadcast_address >> (i*8)) & 0xff);
        }
        else
        {
            printf("%d.", (network_address >> (i*8)) & 0xff);
        }
    }
}

int main()
{
    uint32_t ip_address, subnet_mask;
    printf("Enter IP address: ");
    scanf("%u", &ip_address);
    printf("Enter subnet mask: ");
    scanf("%u", &subnet_mask);

    print_subnet_mask(subnet_mask);
    print_host_bits(subnet_mask);
    print_hosts(subnet_mask);
    print_network_address(ip_address, subnet_mask);
    print_broadcast_address(ip_address, subnet_mask);
    print_address_range(ip_address, subnet_mask);

    return 0;
}