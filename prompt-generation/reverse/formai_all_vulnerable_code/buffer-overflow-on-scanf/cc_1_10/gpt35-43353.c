//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: Dennis Ritchie
#include<stdio.h>
#include<string.h>

int calculate_subnet(int ip[], int subnet_mask[]);

int main(){
    int ip[4], subnet_mask[4], subnet_bits, total_hosts, network_bits, host_bits;
    int i, subnet_octets[4];
    char subnet[15];
    printf("Enter IP address: ");
    scanf("%d.%d.%d.%d", &ip[0], &ip[1], &ip[2], &ip[3]);
    printf("Enter Subnet mask(in bits): ");
    scanf("%d", &subnet_bits);
    for(i=0; i<4; i++){
        subnet_octets[i] = i<subnet_bits/8 ? 255 : (subnet_bits%8?(1<<(8-subnet_bits%8))-1:0);
    }
    //convert subnet mask to dotted decimal notation
    sprintf(subnet, "%d.%d.%d.%d", subnet_octets[0], subnet_octets[1], subnet_octets[2], subnet_octets[3]);
    //convert subnet mask to array of integers
    sscanf(subnet,"%d.%d.%d.%d", &subnet_mask[0], &subnet_mask[1], &subnet_mask[2], &subnet_mask[3]);

    total_hosts = (1<<(32-subnet_bits))-2;
    network_bits = subnet_bits;
    host_bits = 32-subnet_bits;

    printf("\nIP Address: %d.%d.%d.%d\n", ip[0], ip[1], ip[2], ip[3]);
    printf("Subnet Mask: %s\n", subnet);
    printf("Total number of hosts: %d\n", total_hosts);
    printf("Network bits: %d\n", network_bits);
    printf("Host bits: %d\n", host_bits);
    printf("Network Address: %d.%d.%d.%d\n", ip[0]&subnet_mask[0], ip[1]&subnet_mask[1], ip[2]&subnet_mask[2], ip[3]&subnet_mask[3]);
    printf("Broadcast Address: %d.%d.%d.%d\n", (ip[0]|(~subnet_mask[0]))&255, (ip[1]|(~subnet_mask[1]))&255, 
          (ip[2]|(~subnet_mask[2]))&255, (ip[3]|(~subnet_mask[3]))&255);

    calculate_subnet(ip, subnet_mask);

    return 0;
}

int calculate_subnet(int ip[], int subnet_mask[]){
    int i;
    printf("\nSubnet Address\tFirst IP\t\tLast IP\t\tBroadcast Address\n");
    for(i=0; i<4; i++){
        printf("%d", ip[i]&subnet_mask[i]);
        printf(i==3 ? "\t\t" : ".");
    }
    printf("%d.%d.%d.%d\t", (ip[0]&subnet_mask[0]), (ip[1]&subnet_mask[1]), (ip[2]&subnet_mask[2]), (ip[3]&subnet_mask[3])+1);
    printf("%d.%d.%d.%d\t\t", (ip[0]|(~subnet_mask[0]))&255, (ip[1]|(~subnet_mask[1]))&255, (ip[2]|(~subnet_mask[2]))&255, (ip[3]|(~subnet_mask[3]))&254);
    for(i=0; i<4; i++){
        printf(i==3 ? "%d.%d.%d.%d\n" : ".", (ip[0]|(~subnet_mask[0]))&255, (ip[1]|(~subnet_mask[1]))&255, (ip[2]|(~subnet_mask[2]))&255, (ip[3]|(~subnet_mask[3]))&255);
    }
    return 0;
}