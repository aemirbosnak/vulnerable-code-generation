//Gemma-7B DATASET v1.0 Category: Subnet Calculator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 128

int main()
{
    char subnet_mask[MAX_BUFFER_SIZE];
    char subnet_address[MAX_BUFFER_SIZE];
    int subnet_mask_bits, subnet_address_bits, host_bits, remaining_bits;

    // Get the subnet mask and address from the user
    printf("Enter the subnet mask (e.g. 255.255.255.0): ");
    scanf("%s", subnet_mask);

    printf("Enter the subnet address (e.g. 192.168.1.1): ");
    scanf("%s", subnet_address);

    // Calculate the subnet mask bits
    subnet_mask_bits = count_set_bits(subnet_mask);

    // Calculate the subnet address bits
    subnet_address_bits = count_set_bits(subnet_mask) - 1;

    // Calculate the host bits
    host_bits = 32 - subnet_mask_bits - subnet_address_bits;

    // Calculate the remaining bits
    remaining_bits = 32 - subnet_mask_bits;

    // Print the results
    printf("Subnet mask bits: %d\n", subnet_mask_bits);
    printf("Subnet address bits: %d\n", subnet_address_bits);
    printf("Host bits: %d\n", host_bits);
    printf("Remaining bits: %d\n", remaining_bits);

    return 0;
}

int count_set_bits(char *mask)
{
    int bits = 0;
    while (*mask)
    {
        if ((*mask & 0x1) == 0x1)
        {
            bits++;
        }
        mask++;
    }
    return bits;
}