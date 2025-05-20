//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

int main()
{
    int IP[4]; // to store the ip address
    int subnet; // to store the subnet mask
    int subnet_octets[4]; // to store subnet mask octets
    int network_address[4], broadcast_address[4]; // to store network and broadcast addresses
    int no_of_hosts; // to store number of possible hosts in the network
    int i = 0, j = 0;
    char ip_address[16]; // to store ip address in string format

    printf("Enter the IP address in dotted decimal format: ");
    scanf("%s", ip_address);

    char *ptr = strtok(ip_address, "."); // to split ip address at .
    while(ptr != NULL)
    {
        IP[i++] = atoi(ptr);
        ptr = strtok(NULL, ".");
    }

    printf("\nEnter the subnet mask in CIDR notation: ");
    scanf("%d", &subnet);

    // Calculate subnet mask
    memset(subnet_octets, 0, sizeof(subnet_octets)); // set all bits to 0
    
    j = subnet / 8; // number of complete octets
    for(i = 0; i < j; i++) subnet_octets[i] = 255; // octets with all 1s

    j = subnet % 8; // bits in incomplete octet
    if(j) subnet_octets[i] = (unsigned char)pow(2, j) - 1;

    // Calculate network and broadcast addresses
    for(i = 0; i < 4; i++)
    {
        network_address[i] = IP[i] & subnet_octets[i];
        broadcast_address[i] = IP[i] | (~subnet_octets[i] & 0xFF);
    }

    // Calculate number of possible hosts
    no_of_hosts = pow(2, 32 - subnet) - 2;

    printf("\nSubnet mask: %d.%d.%d.%d\n", subnet_octets[0], subnet_octets[1], subnet_octets[2], subnet_octets[3]);
    printf("Network address: %d.%d.%d.%d\n", network_address[0], network_address[1], network_address[2], network_address[3]);
    printf("Broadcast address: %d.%d.%d.%d\n", broadcast_address[0], broadcast_address[1], broadcast_address[2], broadcast_address[3]);
    printf("Number of possible hosts: %d\n", no_of_hosts);

    return 0;
}