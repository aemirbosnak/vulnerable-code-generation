//Gemma-7B DATASET v1.0 Category: Subnet Calculator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

// Function to calculate subnet mask
int subnet_mask(int bits)
{
    int mask = 0;
    for (int i = 0; i < bits; i++)
    {
        mask |= 1 << (32 - i - 1);
    }
    return mask;
}

int main()
{
    int num_hosts, bits;
    printf("Enter the number of hosts: ");
    scanf("%d", &num_hosts);
    printf("Enter the number of bits: ");
    scanf("%d", &bits);

    // Calculate the subnet mask
    int subnet_mask_val = subnet_mask(bits);

    // Print the subnet mask
    printf("The subnet mask is: ");
    for (int i = 0; i < 32; i++)
    {
        if (subnet_mask_val & 1 << i)
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
    }

    printf("\n");

    // Calculate the broadcast address
    int broadcast_addr = subnet_mask_val & (~0xff << (32 - bits));

    // Print the broadcast address
    printf("The broadcast address is: ");
    for (int i = 0; i < 32; i++)
    {
        if (broadcast_addr & 1 << i)
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
    }

    printf("\n");

    // Calculate the network address
    int network_addr = (subnet_mask_val & ~0xff) << bits;

    // Print the network address
    printf("The network address is: ");
    for (int i = 0; i < 32; i++)
    {
        if (network_addr & 1 << i)
        {
            printf("1");
        }
        else
        {
            printf("0");
        }
    }

    printf("\n");

    // Calculate the number of usable hosts
    int usable_hosts = (pow(2, bits) - 2) * num_hosts;

    // Print the number of usable hosts
    printf("The number of usable hosts is: %d", usable_hosts);

    return 0;
}