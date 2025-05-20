//Gemma-7B DATASET v1.0 Category: Subnet Calculator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate subnet mask
int subnet_mask(int cidr)
{
    int mask = 0;
    switch (cidr)
    {
        case 0:
            mask = 0;
            break;
        case 1:
            mask = 254;
            break;
        case 2:
            mask = 252;
            break;
        case 3:
            mask = 250;
            break;
        case 4:
            mask = 248;
            break;
        case 5:
            mask = 246;
            break;
        case 6:
            mask = 244;
            break;
        case 7:
            mask = 242;
            break;
        case 8:
            mask = 240;
            break;
        case 9:
            mask = 238;
            break;
        case 10:
            mask = 236;
            break;
        default:
            mask = -1;
    }
    return mask;
}

int main()
{
    int cidr;
    printf("Enter CIDR subnet mask: ");
    scanf("%d", &cidr);

    int mask = subnet_mask(cidr);

    if (mask == -1)
    {
        printf("Error: invalid CIDR subnet mask.\n");
    }
    else
    {
        printf("Subnet mask: %d.\n", mask);
    }

    return 0;
}