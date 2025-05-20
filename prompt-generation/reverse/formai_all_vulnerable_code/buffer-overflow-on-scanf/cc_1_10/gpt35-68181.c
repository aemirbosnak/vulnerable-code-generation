//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: careful
#include <stdio.h>
#include <stdlib.h>

/* This program is a C Subnet Calculator that takes in an IP address and netmask 
values and calculates the corresponding network address, broadcast address, 
number of subnets and hosts per subnet for Class C networks (CIDR notation /24).
*/

int main() {

    // variables to store the IP address and netmask values
    int ip[4], netmask[4];

    // read in the IP address from the user
    printf("Enter the IP address in the format x.x.x.x: ");
    scanf("%d.%d.%d.%d", &ip[0], &ip[1], &ip[2], &ip[3]);

    // read in the netmask from the user
    printf("Enter the netmask in the format x.x.x.x: ");
    scanf("%d.%d.%d.%d", &netmask[0], &netmask[1], &netmask[2], &netmask[3]);

    // calculate the network address
    int network[4];
    network[0] = ip[0] & netmask[0];
    network[1] = ip[1] & netmask[1];
    network[2] = ip[2] & netmask[2];
    network[3] = ip[3] & netmask[3];

    // calculate the broadcast address
    int broadcast[4];
    broadcast[0] = ip[0] | ~netmask[0];
    broadcast[1] = ip[1] | ~netmask[1];
    broadcast[2] = ip[2] | ~netmask[2];
    broadcast[3] = ip[3] | ~netmask[3];

    // calculate the number of subnets
    int num_subnets = 256 / netmask[3];

    // calculate the number of hosts per subnet
    int num_hosts = ~(netmask[3]) & 0xff;

    // print out the results to the user
    printf("IP Address: %d.%d.%d.%d\n", ip[0], ip[1], ip[2], ip[3]);
    printf("Netmask: %d.%d.%d.%d\n", netmask[0], netmask[1], netmask[2], netmask[3]);
    printf("Network Address: %d.%d.%d.%d\n", network[0], network[1], network[2], network[3]);
    printf("Broadcast Address: %d.%d.%d.%d\n", broadcast[0], broadcast[1], broadcast[2], broadcast[3]);
    printf("Number of Subnets: %d\n", num_subnets);
    printf("Number of Hosts per Subnet: %d\n", num_hosts);
    
    return 0;
}