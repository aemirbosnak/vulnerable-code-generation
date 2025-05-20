//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define IP_ADDR_LENGTH 16
#define SUBNET_MASK_LENGTH 4
#define MAX_SUBNETS 32

struct subnet {
    char ip_address[IP_ADDR_LENGTH+1];
    char subnet_mask[SUBNET_MASK_LENGTH+1];
    int num_hosts;
};

int main() {
    int num_subnets, i;
    struct subnet subnets[MAX_SUBNETS];

    printf("Enter the number of subnets you want to create: ");
    scanf("%d", &num_subnets);

    for (i = 0; i < num_subnets; i++) {
        printf("\nEnter the IP address and subnet mask for subnet %d:\n", i+1);
        printf("IP address: ");
        scanf("%s", subnets[i].ip_address);
        printf("Subnet mask: ");
        scanf("%s", subnets[i].subnet_mask);

        // Calculate the number of hosts in the subnet
        int num_ones = 0;
        char *ip_octet = strtok(subnets[i].ip_address, ".");
        char *subnet_octet = strtok(subnets[i].subnet_mask, ".");
        while (ip_octet!= NULL && subnet_octet!= NULL) {
            int ip_octet_int = atoi(ip_octet);
            int subnet_octet_int = atoi(subnet_octet);
            int ones_in_octet = 0;
            while ((subnet_octet_int & 1) == 0) {
                ones_in_octet++;
                subnet_octet_int >>= 1;
            }
            num_ones += ones_in_octet;
            ip_octet = strtok(NULL, ".");
            subnet_octet = strtok(NULL, ".");
        }
        subnets[i].num_hosts = pow(2, 8 - num_ones) - 2; // Subtract 2 for network address and broadcast address
    }

    printf("\nSubnet information:\n");
    for (i = 0; i < num_subnets; i++) {
        printf("Subnet %d:\n", i+1);
        printf("IP address: %s\n", subnets[i].ip_address);
        printf("Subnet mask: %s\n", subnets[i].subnet_mask);
        printf("Number of hosts: %d\n\n", subnets[i].num_hosts);
    }

    return 0;
}