//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: distributed
#include <stdio.h>
#include <stdlib.h>

int main() {
    int ip[4],mask[4];
    int network[4],broadcast[4];
    int subnetBits,hosts,subnets;
    int i,temp;

    //Get IP address and subnet mask from user
    printf("Enter IP Address (format: x.x.x.x): ");
    scanf("%d.%d.%d.%d",&ip[0],&ip[1],&ip[2],&ip[3]);
    printf("Enter Subnet Mask (format: x.x.x.x): ");
    scanf("%d.%d.%d.%d",&mask[0],&mask[1],&mask[2],&mask[3]);

    //Determine subnet bits, number of subnets, and number of hosts per subnet
    subnetBits = 0;
    for(i=0;i<4;i++) {
        temp = mask[i];
        while(temp) {
            if(temp%2) {
                subnetBits++;
            }
            temp = temp/2;
        }
    }
    subnets = 1;
    for(i=1;i<=subnetBits;i++) {
        subnets *= 2;
    }
    hosts = 0;
    for(i=subnetBits+1;i<=32;i++) {
        hosts += (1 << (32-i));
    }

    //Calculate network address and broadcast address
    for(i=0;i<4;i++) {
        network[i] = ip[i] & mask[i];
        broadcast[i] = network[i] | (255-mask[i]);
    }

    //Display results
    printf("\n");
    printf("IP Address: %d.%d.%d.%d\n",ip[0],ip[1],ip[2],ip[3]);
    printf("Subnet Mask: %d.%d.%d.%d\n",mask[0],mask[1],mask[2],mask[3]);
    printf("Number of Subnet Bits: %d\n",subnetBits);
    printf("Number of Subnets: %d\n",subnets);
    printf("Number of Hosts per Subnet: %d\n",hosts);
    printf("Network Address: %d.%d.%d.%d\n",network[0],network[1],network[2],network[3]);
    printf("Broadcast Address: %d.%d.%d.%d\n",broadcast[0],broadcast[1],broadcast[2],broadcast[3]);

    return 0;
}