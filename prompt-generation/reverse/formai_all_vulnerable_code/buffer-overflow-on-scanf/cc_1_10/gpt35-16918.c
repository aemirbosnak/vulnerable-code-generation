//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: statistical
#include<stdio.h>
#include<math.h>

int main()
{
    int ip[4],prefix,binary[32],i,j,num_hosts;
    int subnet_octet,subnet_mask,s1,s2,s3,s4,s5,s6,s7,s8;
    int network_id[4],broadcast_id[4];

    printf("Enter the IP Address in decimal format [x.x.x.x]: ");
    scanf("%d.%d.%d.%d",&ip[0],&ip[1],&ip[2],&ip[3]);

    printf("Enter the Prefix (CIDR Notation): ");
    scanf("%d",&prefix);

    for(i=0;i<32;i++)
        binary[i]=0;

    for(i=0;i<prefix;i++)
        binary[i]=1;

    j=0;
    for(i=0;i<32;i+=8)
    {
        subnet_octet=0;
        s1=binary[i]*128;
        s2=binary[i+1]*64;
        s3=binary[i+2]*32;
        s4=binary[i+3]*16;
        s5=binary[i+4]*8;
        s6=binary[i+5]*4;
        s7=binary[i+6]*2;
        s8=binary[i+7]*1;

        subnet_octet=s1+s2+s3+s4+s5+s6+s7+s8;

        if(j==0)
            network_id[j]=subnet_octet;
        else
            broadcast_id[j-1]=subnet_octet;

        j++;
    }

    subnet_mask=256-pow(2,8-(prefix%8));

    num_hosts=pow(2,32-prefix)-2;

    printf("\n\n\nNetwork ID: %d.%d.%d.%d",network_id[0],network_id[1],network_id[2],network_id[3]);
    printf("\nBroadcast ID: %d.%d.%d.%d",broadcast_id[0],broadcast_id[1],broadcast_id[2],broadcast_id[3]);
    printf("\nSubnet Mask: 255.255.255.%d",subnet_mask);
    printf("\nNumber of Hosts: %d\n\n",num_hosts);

    return 0;
}