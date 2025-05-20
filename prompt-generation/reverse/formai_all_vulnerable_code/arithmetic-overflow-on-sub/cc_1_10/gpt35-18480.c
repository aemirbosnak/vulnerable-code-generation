//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: immersive
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define IP_SIZE 5 
//maximum size of IP Address is 15 + '\0'
//maximum size of subnet is 3 + '\0'
int main()
{
    char ip_address[IP_SIZE],subnet_mask[IP_SIZE];
    int oct[IP_SIZE],binary_oct[IP_SIZE],subnet_dec[IP_SIZE],subnet_binary[IP_SIZE];
    printf("Welcome to the immersive Subnet Calculator!\n\n");
    printf("Please enter the IP address in dotted decimal format(xxx.xxx.xxx.xxx):");
    fgets(ip_address,IP_SIZE,stdin);//reading input
    printf("\nPlease enter the subnet mask in dotted decimal format(xxx.xxx.xxx.xxx):");
    fgets(subnet_mask,IP_SIZE,stdin);//reading input
    printf("\nCalculating...\n");
    char *ptr;
    ptr = strtok(ip_address,".");//parsing ip address
    int i=0;
    while(ptr!=NULL)
    {
        oct[i] = atoi(ptr);
        ptr = strtok(NULL,".");
        i++;
    }
    ptr = strtok(subnet_mask,".");//parsing subnet mask
    i=0;
    while(ptr!=NULL)
    {
        subnet_dec[i] = atoi(ptr);
        ptr = strtok(NULL,".");
        i++;
    }
    printf("\nIP Address: %s",ip_address);//displaying ip address
    printf("Subnet Mask: %s",subnet_mask);//displaying subnet mask
    printf("\nNetwork Address: ");
    for(i=0;i<IP_SIZE;i++)//converting subnet mask to binary
    {
        int c=subnet_dec[i],j=0,k=128;
        while(j<8)
        {
            if(c-k>=0)
            {
                subnet_binary[i] += 1<<(7-j);
                c -= k;
            }
            k /= 2;
            j++;
        }
    }
    for(i=0;i<IP_SIZE;i++)//calculating network address
    {
        binary_oct[i] = oct[i]&subnet_binary[i];
        printf("%d.",binary_oct[i]);
    }
    printf("\n");
    return 0;//End Program
}