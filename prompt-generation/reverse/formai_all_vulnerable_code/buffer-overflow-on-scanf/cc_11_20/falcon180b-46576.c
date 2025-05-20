//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: curious
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int n,i,j,k,l,count=0;
    char ip[15],subnet[15];

    printf("Enter the IP address: ");
    scanf("%s",ip);

    printf("Enter the subnet mask: ");
    scanf("%s",subnet);

    n=atoi(subnet);

    int mask=0xffffff00;

    for(i=0;i<3;i++)
    {
        for(j=0;j<8;j++)
        {
            if(ip[i]=='.' && j==3)
            {
                break;
            }
            else if(ip[i]=='.' && j<3)
            {
                k=atoi(&ip[i+1]);
                if(k>255)
                {
                    printf("Invalid IP address\n");
                    return 0;
                }
                else
                {
                    count++;
                }
            }
            else if(subnet[i]=='.' && j<3)
            {
                l=atoi(&subnet[i+1]);
                if(l>255)
                {
                    printf("Invalid subnet mask\n");
                    return 0;
                }
                else if(l==0)
                {
                    printf("Invalid subnet mask\n");
                    return 0;
                }
            }
            else
            {
                mask=(mask>>3)<<3;
                mask=mask|(atoi(&subnet[i])<<(8-j*3));
            }
        }
    }

    if(count!=4)
    {
        printf("Invalid IP address\n");
        return 0;
    }

    int network=ip[0]*256*256*256+ip[1]*256*256+ip[2]*256+ip[3];
    int broadcast=network+pow(2,8)-pow(2,n);

    printf("Network address: %d.%d.%d.%d\n",network>>24&0xff,network>>16&0xff,network>>8&0xff,network&0xff);
    printf("Broadcast address: %d.%d.%d.%d\n",broadcast>>24&0xff,broadcast>>16&0xff,broadcast>>8&0xff,broadcast&0xff);

    return 0;
}