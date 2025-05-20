//Gemma-7B DATASET v1.0 Category: Subnet Calculator ; Style: careful
#include <stdio.h>
#include <stdlib.h>

// Function to calculate subnet mask
int subnet_mask(int prefix_length)
{
    int mask = 0;

    // Calculate the number of bits in the subnet mask
    switch (prefix_length)
    {
        case 0:
            mask = 0;
            break;
        case 1:
            mask = 0x00000001;
            break;
        case 2:
            mask = 0x0000001f;
            break;
        case 3:
            mask = 0x000000ff;
            break;
        case 4:
            mask = 0x00000fff;
            break;
        case 5:
            mask = 0x0000ffff;
            break;
        case 6:
            mask = 0x000ffffff;
            break;
        case 7:
            mask = 0x00fffffffd;
            break;
        case 8:
            mask = 0xffffffffffff;
            break;
        default:
            mask = -1;
            break;
    }

    return mask;
}

int main()
{
    int prefix_length;

    // Get the prefix length from the user
    printf("Enter the prefix length: ");
    scanf("%d", &prefix_length);

    // Calculate the subnet mask
    int mask = subnet_mask(prefix_length);

    // Print the subnet mask
    printf("The subnet mask is: ");
    printf("%x", mask);

    return 0;
}