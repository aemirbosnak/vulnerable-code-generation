//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: lively
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

int main()
{
    char subnet_mask[16];
    int subnet_decimal[4], subnet_bits = 0, i, wildcard_decimal[4], network_decimal[4], broadcast_decimal[4];

    printf("Welcome to the lively Subnet Calculator!\n\n");

    // Taking input of subnet mask
    printf("Enter the subnet mask in dotted decimal notation(x.x.x.x): ");
    scanf("%s", subnet_mask);

    // converting subnet mask to an array of decimal values
    char *ptr = strtok(subnet_mask, ".");
    i = 0;

    while(ptr != NULL)
    {
        subnet_decimal[i] = atoi(ptr);
        i++;
        ptr = strtok(NULL, ".");
    }

    // counting number of bits in subnet mask
    for(i = 0; i < 4; i++)
    {
        subnet_bits += bitcount(subnet_decimal[i]);
    }

    // calculating wildcard mask
    for(i = 0; i < 4; i ++)
    {
        wildcard_decimal[i] = 255 - subnet_decimal[i];
    }

    printf("\n\n");

    // printing subnet mask, wildcard mask and number of hosts
    printf("Subnet Mask: %s\n", subnet_mask);
    printf("Wildcard Mask: %d.%d.%d.%d\n", wildcard_decimal[0], wildcard_decimal[1], wildcard_decimal[2], wildcard_decimal[3]);
    printf("Number of Hosts: %d\n", (int)pow(2, 32 - subnet_bits) - 2);

    // Taking input of network address
    printf("\nEnter the network address in dotted decimal notation(x.x.x.x): ");
    char network_address[16];
    scanf("%s", network_address);

    char *ptr2 = strtok(network_address, ".");
    i = 0;

    // converting network address to an array of decimal values
    while(ptr2 != NULL)
    {
        network_decimal[i] = atoi(ptr2);
        i++;
        ptr2 = strtok(NULL, ".");
    }

    // calculating broadcast address
    for(i = 0; i < 4; i++)
    {
        broadcast_decimal[i] = network_decimal[i] | wildcard_decimal[i];
    }

    // printing network address and broadcast address
    printf("\n\n");
    printf("Network Address: %d.%d.%d.%d\n", network_decimal[0], network_decimal[1], network_decimal[2], network_decimal[3]);
    printf("Broadcast Address: %d.%d.%d.%d\n", broadcast_decimal[0], broadcast_decimal[1], broadcast_decimal[2], broadcast_decimal[3]);

    return 0;
}

// function to count number of bits in a decimal value
int bitcount(int num)
{
    int count = 0;

    while(num != 0)
    {
        count ++;
        num = num & (num-1);
    }

    return count;
}