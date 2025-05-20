//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: multivariable
#include<stdio.h>
#include<math.h>

int main()
{
    //declaration of variables
    int ip[4], mask, subnet[4], i, j, k, l;
    int host_bits, hosts, subnets, addr_bits, total_hosts;
    //taking input from user
    printf("Enter IP address in the format xxx.xxx.xxx.xxx : ");
    scanf("%d.%d.%d.%d", &ip[0], &ip[1], &ip[2], &ip[3]);

    printf("Enter subnet mask in the format xx : ");
    scanf("%d", &mask);

    //calculating subnet mask
    for(i=0; i<4; i++)
        subnet[i] = 0;

    for(i=0; i<mask/8; i++)
        subnet[i] = 255;

    if(mask%8 != 0)
        subnet[i] = (int)pow(2, mask%8) - 1;

    //printing subnet mask
    printf("\nSubnet Mask : %d.%d.%d.%d", subnet[0], subnet[1], subnet[2], subnet[3]);

    //calculating host bits
    host_bits = 32 - mask;

    //calculating number of subnets and hosts in each subnet
    subnets = (int)pow(2, mask/8)*((int)pow(2, mask%8) + 1);
    hosts = (int)pow(2, host_bits) - 2;

    //printing number of subnets and hosts
    printf("\n\nTotal Number of Subnets : %d", subnets);
    printf("\nNumber of Hosts per Subnet : %d", hosts);

    //calculating total address bits and total hosts
    addr_bits = 32 - host_bits;
    total_hosts = (int)pow(2, addr_bits) - 2;

    //printing total address bits and total hosts
    printf("\n\nTotal Address Bits : %d", addr_bits);
    printf("\nTotal Number of Hosts : %d\n", total_hosts);

    //printing all subnets
    printf("\n\nAll Subnets : \n");
    l = 0;

    for(i=0; i<(int)pow(2, mask/8); i++)
    {
        if(i == subnet[l])
        {
            l++;
            continue;
        }
        printf("%d.%d.%d.%d", ip[0], ip[1], ip[2], i);

        if(mask%8 != 0)
        {
            printf("/%d", mask);
        }
        printf("\n");

        for(j=0; j<(int)pow(2, mask%8); j++)
        {
            if(j == 0 && mask%8 != 0)
            {
                continue;
            }
            printf("%d.%d.%d.%d", ip[0], ip[1], i, j);
            printf("/%d\n", mask);
        }
    }
    return 0;
}