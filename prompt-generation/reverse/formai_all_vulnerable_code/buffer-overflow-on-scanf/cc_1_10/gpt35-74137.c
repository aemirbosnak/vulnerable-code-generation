//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: enthusiastic
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define IPADDRESS 4    //No. of octets in IP Address 
#define MAXOCTET 255   //Maximum Value of an Octet
#define MASKBITS 32    //Bits in a Netmask
#define MAXSUBNET 30   //Maximum number of subnets
#define MAXHOSTS 126   //Maximum number of host addresses per subnet

int main() 
{
    char ip_addr[15], mask[15];
    int IP[IPADDRESS], subnet, hosts, i, j, netmask, subnet_mask[MAXOCTET+1], first_ip[IPADDRESS], last_ip[IPADDRESS];
    printf("--- Welcome to the Subnet Calculator ---\n\n");
    
    printf("Enter an IP Address: ");
    scanf("%s", ip_addr);
    printf("Enter the Mask: ");
    scanf("%s", mask);
    printf("Enter the number of subnets: ");
    scanf("%d", &subnet);
    printf("Enter the number of hosts per subnet: ");
    scanf("%d", &hosts);
    
    //Converting IP address to its octets
    for(i=0, j=0; i<=IPADDRESS; i++, j+=4)
      IP[i]=atoi(ip_addr+j);

    //Extracting the Netmask and Converting it to its octets
    netmask = atoi(mask);
    for(i=0; i<=MAXOCTET; i++)
      subnet_mask[i]=netmask>i?1:0;
    
    //Extracting the First IP address of each Subnet
    int n = (int)(pow(2,(double)MASKBITS-netmask)+0.1);
    for(i=0; i<subnet; i++) 
    {
        for(j=0; j<IPADDRESS; j++)
            first_ip[j] = ((i*n) >> ((3-j)*8)) & 0xFF;
        
        //Printing the IP Address of First Subnet Address
        printf("\nSubnet %d: %d.%d.%d.%d\n", i+1, first_ip[0], first_ip[1], first_ip[2], first_ip[3]);
          
        //Extracting the Last IP address of each Subnet
        for(j=0; j<IPADDRESS; j++)
            last_ip[j] = j==IPADDRESS-1 ? first_ip[j] + hosts - 2 : first_ip[j];

        //Printing the IP Address of Last Subnet Address along with Host Range
        printf("Host Range: %d.%d.%d.%d - %d.%d.%d.%d\n", first_ip[0], first_ip[1], first_ip[2], first_ip[3], last_ip[0], last_ip[1], last_ip[2], last_ip[3]);
    }
    return 0;
}