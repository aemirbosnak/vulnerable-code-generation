//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char ip_address[16];
    char subnet_mask[16];
    char network_address[16];
    char broadcast_address[16];
    unsigned long int subnet_bits = 0, subnet_decimal = 0;
    unsigned long int network_bits = 0, network_decimal = 0;
    unsigned long int host_bits = 0, host_decimal = 0;
    unsigned long int total_hosts = 0;
    unsigned long int max_hosts = 0;
    unsigned long int i;

    // Accept input for IP address and subnet mask
    printf("Enter IP address (format: XXX.XXX.XXX.XXX): ");
    scanf("%s", ip_address);
    printf("Enter subnet mask (format: XXX.XXX.XXX.XXX): ");
    scanf("%s", subnet_mask);

    // Calculate subnet bits
    for (i = 0; i < strlen(subnet_mask); i++) 
    {
        if (subnet_mask[i] == '0') 
        {
            subnet_bits++;
        }
    }

    subnet_decimal = 4294967295 << subnet_bits;

    // Convert IP address and subnet mask to decimal
    sscanf(ip_address, "%lu.%lu.%lu.%lu", &network_decimal, &host_decimal, &host_decimal, &host_decimal);
    sscanf(subnet_mask, "%lu.%lu.%lu.%lu", &subnet_decimal, &subnet_decimal, &subnet_decimal, &subnet_decimal);

    // Calculate network bits
    network_decimal = network_decimal & subnet_decimal;
    for (i = 0; i < strlen(ip_address); i++)
    {
        network_bits = network_bits * 10 + (network_decimal >> i & 1);
    }

    // Calculate broadcast address
    broadcast_address[0] = '\0';
    for (i = 0; i < strlen(subnet_mask); i++)
    {
        if (subnet_mask[i] == '1')
        {
            strncat(broadcast_address, &ip_address[i], 1); 
        }
        else
        {
            strcat(broadcast_address, "1");
        }
    }

    // Calculate total number of hosts
    host_bits = 32 - subnet_bits;
    total_hosts = (1 << host_bits) - 2;

    // Calculate maximum number of hosts
    max_hosts = (host_bits == 0) ? 0 : (1 << host_bits) - 2;

    // Display results
    printf("\nResults for %s/%lu:\n\n", ip_address, subnet_bits);
    printf("Subnet mask     : %s\n", subnet_mask);
    printf("Network address : %lu.%lu.%lu.%lu\n", network_decimal >> 24, (network_decimal >> 16) & 0xFF, (network_decimal >> 8) & 0xFF, network_decimal & 0xFF);
    printf("Broadcast address : %s\n", broadcast_address);
    printf("Total number of hosts : %lu\n", total_hosts);
    printf("Maximum number of hosts : %lu\n", max_hosts);

    return 0;
}