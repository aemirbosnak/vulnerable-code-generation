//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: safe
#include<stdio.h>

//function to calculate the subnet mask
void subnet_mask(int prefix_len, int subnet_octets[])
{
    int i, j;
    int bit_pos = 7;
    int temp = 0;
    int val = 128;
    for(i=0; i<prefix_len; i++)
    {
        if(bit_pos == -1)
        {
            bit_pos = 7;
            subnet_octets[i/8] = temp;
            temp = 0;
            val = 128;
        }
        temp += val;
        val /= 2;
        --bit_pos;
    }
    subnet_octets[i/8] = temp;
}

//function to print the binary representation of an octet
void print_binary(int num)
{
    int i;
    int mask = 128;
    for(i=0; i<8; i++)
    {
        if(num & mask)
            printf("1");
        else
            printf("0");
        mask /= 2;
    }
}

int main()
{
    int prefix_len; //prefix length
    int subnet_octets[4] = {}; //to hold subnet mask octets
    int i;

    printf("Enter prefix length: ");
    scanf("%d", &prefix_len);
    if(prefix_len > 32)
    {
        printf("Invalid prefix length\n");
        return -1;
    }

    subnet_mask(prefix_len, subnet_octets);

    //print subnet mask
    printf("Subnet mask: ");
    for(i=0; i<4; i++)
    {
        printf("%d", subnet_octets[i]);
        if(i < 3)
            printf(".");
    }
    printf("\n");

    //print binary representation of subnet mask
    printf("Binary subnet mask: ");
    for(i=0; i<4; i++)
    {
        print_binary(subnet_octets[i]);
        if(i < 3)
            printf(".");
    }
    printf("\n");

    return 0;   
}