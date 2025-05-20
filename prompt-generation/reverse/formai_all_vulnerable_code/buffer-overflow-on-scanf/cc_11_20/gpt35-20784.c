//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: surprised
#include<stdio.h>

void main()
{
    int ip[4], submask[4], subnet_id[4], hosts, max_hosts, bits, remaining_bits;

    printf("WOW! Let's calculate some Subnets!\n");

    printf("\nEnter IP address in format x.x.x.x : ");
    scanf("%d.%d.%d.%d",&ip[0],&ip[1],&ip[2],&ip[3]);

    printf("\nEnter Subnet Mask in format x.x.x.x : ");
    scanf("%d.%d.%d.%d",&submask[0],&submask[1],&submask[2],&submask[3]);

    printf("\nEnter number of subnets you want to create: ");
    int subnets;
    scanf("%d",&subnets);

    bits = 0;
    int temp = subnets;
    while(temp > 0)
    {
        temp = temp/2;
        bits++;
    }
    remaining_bits = 32 - bits;

    // Calculate Subnet Mask
    int i=0;
    while(i<4)
    {
        subnet_id[i] = (ip[i] & submask[i]);
        i++;
    }
    printf("\nSubnet Mask is %d.%d.%d.%d\n",submask[0],submask[1],submask[2],submask[3]);

    // Display Subnet ID & Broadcast Address
    printf("\nSubnet ID\t: %d.%d.%d.%d",subnet_id[0],subnet_id[1],subnet_id[2],subnet_id[3]);

    int broadcast_id[4];
    printf("\nBroadcast Address : ");
    for(i=0; i<4; i++)
    {
        broadcast_id[i] = subnet_id[i] | (~submask[i] & 0xFF);
        printf("%d.", broadcast_id[i]);
    }

    // Calculate Total Hosts
    max_hosts = 1;
    for (i=0; i<remaining_bits; i++)
    {
        max_hosts *= 2;
    }
    max_hosts -= 2;

    // Display Available Hosts of Each Subnet
    printf("\n\nAvailable Hosts for each Subnet: %d", max_hosts);

    // Calculate Subnet Range
    int subnet_range = max_hosts + 2;
    int subnet_information[subnets][subnet_range][4];

    int count = 1;
    int j,k,l;
    for(i=0; i<4; i++)
    {
        for(j=0; j<subnet_range; j++)
        {
            if(i==0 && j%subnet_range!=0)
            {
                subnet_information[count][j][i] = subnet_information[count][j-1][i] + 1;
            }
            else if(i==0 && j%subnet_range==0)
            {
                subnet_information[count][j][i] = subnet_id[0];
            }
            else
            {
                subnet_information[count][j][i] = subnet_information[count][j-1][i];
            }
        }
    }

    printf("\n\nIP Address Ranges for each Subnet:\n");
    printf("\nSubnetNo.\tStart\t\tEnd\n");
    for(count=1; count<=subnets; count++)
    {
        printf("%d\t\t",count);

        for(i=0; i<subnet_range; i++)
        {
            if(i % 10 == 0)
            {
                printf("\n\t\t");
            }

            for(j=0; j<4; j++)
            {
                printf("%d.",subnet_information[count][i][j]);
            }
            printf("\t");

            if((i+1) % subnet_range == 0)
            {
                printf("\n\n");
            }
        }
    }
}