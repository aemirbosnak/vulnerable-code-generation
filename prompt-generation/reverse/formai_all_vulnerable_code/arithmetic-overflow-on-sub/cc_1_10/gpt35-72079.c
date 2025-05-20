//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_SUBNETS 4
#define MAX_BITS 32

struct Subnet
{
    char subnet_address[MAX_BITS+1];
    int num_hosts;
};

void calculate_subnet_masks(int prefix_length, char *subnet_mask, char *wildcard_mask)
{
    memset(subnet_mask, 0, MAX_BITS+1);
    memset(wildcard_mask, 0, MAX_BITS+1);

    int i, j = 0;

    for(i = 0; i < prefix_length; i++)
    {
        subnet_mask[i] = '1';
    }
    for(; i < MAX_BITS; i++)
    {
        wildcard_mask[i] = '1';
    }

    for(i = 0; i < MAX_BITS; i++)
    {
        if(i % 8 == 0 && i != 0)
        {
            subnet_mask[j] = '.';
            wildcard_mask[j] = '.';
            j++;
        }

        if(subnet_mask[i] == '\0')
        {
            subnet_mask[i] = '0';
        }

        if(wildcard_mask[i] == '\0')
        {
            wildcard_mask[i] = '0';
        }
    }
}

void parse_address_string(char *address_string, int *address_array)
{
    char *octet = strtok(address_string, ".");

    int i = 0;
    while(octet != NULL)
    {
        address_array[i] = atoi(octet);

        octet = strtok(NULL, ".");
        i++;
    }
}

int calculate_num_hosts(int bits_left)
{
    if(bits_left == 0)
    {
        return 1;
    }
    else
    {
        return 2 * calculate_num_hosts(bits_left - 1);
    }
}

void calculate_subnets(int num_subnets, int prefix_length, char *address_string, struct Subnet *subnets)
{
    int address_array[4];
    parse_address_string(address_string, address_array);

    int num_bits_borrowed = MAX_BITS - prefix_length;

    int host_bits = num_bits_borrowed / num_subnets;
    int remaining_bits = num_bits_borrowed % num_subnets;

    int i;
    for(i = 0; i < num_subnets; i++)
    {
        int subnet_mask_length = prefix_length + host_bits + remaining_bits;

        char subnet_mask[MAX_BITS+1];
        char wildcard_mask[MAX_BITS+1];

        calculate_subnet_masks(subnet_mask_length, subnet_mask, wildcard_mask);

        sprintf(subnets[i].subnet_address, "%d.%d.%d.%d/%d", address_array[0], address_array[1], address_array[2], address_array[3], subnet_mask_length);
        subnets[i].num_hosts = calculate_num_hosts(host_bits);

        prefix_length += host_bits + remaining_bits;
        remaining_bits = 0;
    }
}

void display_subnets(int num_subnets, struct Subnet *subnets)
{
    int i;
    printf("\nSubnet\t\t\t\t# of Hosts\n");
    printf("-------------------------------------------------\n");
    for(i = 0; i < num_subnets; i++)
    {
        printf("%-20s\t\t%d\n", subnets[i].subnet_address, subnets[i].num_hosts);
    }
}

int main()
{
    char address_string[MAX_BITS+1];

    printf("Enter the IP address: ");
    scanf("%s", address_string);

    int prefix_length;
    printf("Enter the prefix length: ");
    scanf("%d", &prefix_length);

    int num_subnets;
    printf("Enter the number of subnets: ");
    scanf("%d", &num_subnets);

    struct Subnet subnets[MAX_SUBNETS];

    calculate_subnets(num_subnets, prefix_length, address_string, subnets);

    display_subnets(num_subnets, subnets);

    return 0;
}