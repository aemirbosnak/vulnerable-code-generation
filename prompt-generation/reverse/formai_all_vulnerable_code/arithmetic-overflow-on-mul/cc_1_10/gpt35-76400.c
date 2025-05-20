//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: curious
#include<stdio.h>

int main()
{
    int IP[4], subnet_mask, subnet_bits, subnet = 0, i, j, pow = 1;

    printf("Greetings! I am your curious Subnet Calculator! Let's dive into some networking details!\n\n");

    printf("Please input your IP address in dotted decimal format (example: 192.168.1.1): ");
    scanf("%d.%d.%d.%d",&IP[0],&IP[1],&IP[2],&IP[3]);

    printf("Enter the subnet mask in decimal format (example: 255.255.255.0): ");
    scanf("%d.%d.%d.%d",&i,&j,&j,&j);
    subnet_mask = i * 256 * 256 * 256 + j * 256 * 256 + j * 256 + j; //convert subnet mask into 32-bit integer

    for(i = 0; i < 32; i++) //counting the number of bits in the subnet mask
    {
        if(subnet_mask & (1 << i))
            subnet_bits++;
    }

    printf("\nYour IP address in binary is: \n");

    for(i = 3; i >= 0; i--) //converting IP address into binary and displaying it
    {
        for(j = 7; j >= 0; j--)
        {
            if(IP[i] & (1 << j))
                printf("1");
            else
                printf("0");
        }
        printf(" ");
    }

    printf("\n\nThe subnet mask in binary is: \n");

    for(i = 31; i >= 0; i--) //converting subnet mask into binary and displaying it
    {
        if(subnet_mask & (1 << i))
            printf("1");
        else
            printf("0");
    }

    for(i = 0; i < subnet_bits; i++) //calculating the number of subnets
    {
        subnet += pow;
        pow *= 2;
    }

    printf("\n\nThe number of subnets possible with this subnet mask is: %d", subnet);

    pow = 1;

    for(i = subnet_bits; i < 32; i++) //calculating the number of hosts per subnet
    {
        subnet += pow;
        pow *= 2;
    }

    printf("\n\nThe number of hosts possible per subnet with this subnet mask is: %d\n", subnet);

    printf("\nCurious fact - did you know that, in theory, the largest possible subnet mask would give you only one subnet and one host? Cool, huh?\n");

    return 0;
}