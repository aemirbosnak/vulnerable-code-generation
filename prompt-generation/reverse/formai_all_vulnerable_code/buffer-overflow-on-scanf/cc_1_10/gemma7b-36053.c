//Gemma-7B DATASET v1.0 Category: Subnet Calculator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBNET_MASK_BITS 32

int main()
{
    char subnet_mask[MAX_SUBNET_MASK_BITS / 8 + 1];
    int subnet_mask_bits, address, address_bits, prefix_length, i, subnet_mask_prefix_length;

    // Get the subnet mask
    printf("Enter the subnet mask (e.g. 255.255.255.0): ");
    scanf("%s", subnet_mask);

    // Calculate the subnet mask bits
    subnet_mask_bits = count_set_bits(subnet_mask);

    // Calculate the prefix length
    prefix_length = subnet_mask_bits - 32 + 1;

    // Calculate the address bits
    address_bits = 32 - prefix_length;

    // Print the results
    printf("\nSubnet Mask:** %s\n", subnet_mask);
    printf("Subnet Mask Bits:** %d\n", subnet_mask_bits);
    printf("Prefix Length:** %d\n", prefix_length);
    printf("Address Bits:** %d\n", address_bits);

    // Calculate the subnet mask prefix length
    subnet_mask_prefix_length = prefix_length - 1;

    // Print the subnet mask prefix length
    printf("Subnet Mask Prefix Length:** %d\n", subnet_mask_prefix_length);

    return 0;
}

int count_set_bits(char *mask)
{
    int i, count = 0;

    for (i = 0; mask[i] != '\0'; i++)
    {
        int bit = mask[i] & 0x80;

        if (bit)
        {
            count++;
        }
    }

    return count;
}