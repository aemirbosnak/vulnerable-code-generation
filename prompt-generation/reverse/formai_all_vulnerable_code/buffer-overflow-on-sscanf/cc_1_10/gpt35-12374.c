//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: complex
#include<stdio.h>
#include<string.h>
#include<math.h>
 
int main()
{
    char ip[16], mask[16];
    int a,b,c,d,n,i,j,bits,h=0;
    int subnet[4],binary_mask[32];
     
    printf("Enter IP address:\n");
    scanf("%s",ip);
     
    printf("Enter subnet mask:\n");
    scanf("%s",mask);
     
    sscanf(ip,"%d.%d.%d.%d",&a,&b,&c,&d);   
    sscanf(mask,"%d.%d.%d.%d",&subnet[0],&subnet[1],&subnet[2],&subnet[3]);
     
    printf("\nIP Address: %d.%d.%d.%d\n",a,b,c,d);
    printf("Subnet Mask: %d.%d.%d.%d\n",subnet[0],subnet[1],subnet[2],subnet[3]);
     
    for(i=0;i<4;i++)
    {
        bits=0;
        n=subnet[i];
        while(n)
        {
            bits++;
            n &= n-1;
        }
        h+=bits;
    }
     
    printf("Subnets possible: %d\n",pow(2.0,h)-2);
    printf("Hosts per subnet: %d\n",pow(2.0,32-h)-2);
     
    for(i=0;i<4;i++)
    {
        n=subnet[i];
        for(j=7;j>=0;j--)
        {
            if(n%2==1) binary_mask[i*8+j]=1;
            else binary_mask[i*8+j]=0;
            n/=2;
        }
    }
     
    printf("Binary Subnet Mask: ");
    for(i=0;i<32;i++)
    {
        printf("%d",binary_mask[i]);
        if(i==7 || i==15 || i==23) printf(".");
    }
    printf("\n");
     
    return 0;
}