//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// function that converts IP address into binary format
void convertIPtoBinary(char *ip_address, int *binary_ip)
{
    int i, a, b, c, d;
    
    sscanf(ip_address, "%d.%d.%d.%d", &a, &b, &c, &d);
    binary_ip[0] = a; binary_ip[1] = b; binary_ip[2] = c; binary_ip[3] = d;
    
    for(i=0; i<4; i++)
    {
        int j=7, num=binary_ip[i];
        while(num>0)
        {
            binary_ip[(i*8)+j] = num%2;
            num /= 2; j--;
        }
    }
}

int main()
{
    char ip_address[16];
    int prefix_length=0, binary_ip[32]={0}, subnet_mask[32]={0}, i, j, decimal_mask[4];

    // take input from user
    printf("Enter IP address (in dotted format): ");
    scanf("%s", ip_address);
    printf("Enter prefix length: ");
    scanf("%d", &prefix_length);
    
    // validate the prefix length
    if(prefix_length<0 || prefix_length>32)
    {
        printf("Invalid prefix length! Please try again.");
        exit(0);
    }
    
    // convert IP address to binary format
    convertIPtoBinary(ip_address, binary_ip);
    
    // calculate subnet mask
    for(i=0; i<prefix_length; i++)
    {
        subnet_mask[i] = 1;
    }
    
    // calculate decimal subnet mask
    for(i=0; i<32; i+=8)
    {
        int sum=0;
        for(j=0; j<8; j++)
        {
            sum += (subnet_mask[i+j] * pow(2, (7-j)));
        }
        decimal_mask[i/8] = sum;
    }
    
    // output the result
    printf("\nIP address: %s\n", ip_address);
    printf("Prefix length: /%d\n", prefix_length);
    printf("Subnet mask: %d.%d.%d.%d\n\n", decimal_mask[0], decimal_mask[1], decimal_mask[2], decimal_mask[3]);
    
    return 0;
}