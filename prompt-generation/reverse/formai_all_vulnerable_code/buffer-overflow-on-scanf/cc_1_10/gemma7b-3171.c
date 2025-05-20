//Gemma-7B DATASET v1.0 Category: Subnet Calculator ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>

void subnet_calculator()
{
    int mask, host, network, subnet;
    char mask_bits[32];

    printf("Enter the subnet mask in binary (e.g. 255.255.255.0 for /8): ");
    scanf("%d", &mask);

    mask_bits[0] = (mask & 0xFF000000) >> 24;
    mask_bits[1] = (mask & 0x0F000000) >> 16;
    mask_bits[2] = (mask & 0x00F00000) >> 8;
    mask_bits[3] = (mask & 0x000F0000) >> 0;

    printf("The subnet mask in decimal is: ");
    for (int i = 0; i < 4; i++)
    {
        printf("%d.", mask_bits[i]);
    }

    printf("\nEnter the host number: ");
    scanf("%d", &host);

    network = (host & ~mask) >> subnet_bits(mask);

    printf("The network address is: ");
    printf("%d.%d.%d.%d", network, mask_bits[0], mask_bits[1], mask_bits[2]);

    printf("\nThe broadcast address is: ");
    printf("%d.%d.%d.%d", network + 2^(mask_bits[0] - 1), mask_bits[0], mask_bits[1], mask_bits[2]);
}

int subnet_bits(int mask)
{
    int bits = 0;

    while (mask & 1)
    {
        mask >>= 1;
        bits++;
    }

    return bits;
}

int main()
{
    subnet_calculator();

    return 0;
}