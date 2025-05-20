//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

// Function to calculate subnet mask based on the CIDR notation
void calculate_subnet_mask(int cidr, int* subnet_mask) {
    int i, j;
    for(i = 0; i < 4; i++) {
        subnet_mask[i] = 0;
        for(j = 0; j < 8; j++) {
            if(cidr > 0) {
                subnet_mask[i] |= (1 << (7 - j));
                cidr--;
            }
        }
    }
}

// Function to display IP address in dotted decimal format
void display_ip_address(int* ip_address) {
    printf("%d.%d.%d.%d", ip_address[0], ip_address[1], ip_address[2], ip_address[3]);
}

// Function to display subnet mask in dotted decimal format
void display_subnet_mask(int* subnet_mask) {
    printf("%d.%d.%d.%d", subnet_mask[0], subnet_mask[1], subnet_mask[2], subnet_mask[3]);
}

// Function to calculate network address
void calculate_network_address(int* ip_address, int* subnet_mask, int* network_address) {
    int i;
    for(i = 0; i < 4; i++) {
        network_address[i] = ip_address[i] & subnet_mask[i];
    }
}

// Function to calculate broadcast address
void calculate_broadcast_address(int* ip_address, int* subnet_mask, int* broadcast_address) {
    int i;
    for(i = 0; i < 4; i++) {
        broadcast_address[i] = ip_address[i] | (~subnet_mask[i] & 0xFF);
    }
}

// Function to calculate number of hosts in the subnet
int calculate_no_of_hosts(int cidr) {
    return pow(2, (32 - cidr)) - 2;
}

int main() {
    int ip_address[4]; // To store IP address
    int cidr; // To store CIDR notation
    int subnet_mask[4]; // To store subnet mask
    int network_address[4]; // To store network address
    int broadcast_address[4]; // To store broadcast address
    int no_of_hosts; // To store number of hosts in the subnet
    char choice; // To store user choice

    do {
        printf("Enter IP Address in dotted decimal format (Eg: 192.168.1.1): ");
        scanf("%d.%d.%d.%d", &ip_address[0], &ip_address[1], &ip_address[2], &ip_address[3]);
        printf("Enter CIDR notation (Eg: 24): ");
        scanf("%d", &cidr);

        calculate_subnet_mask(cidr, subnet_mask);
        calculate_network_address(ip_address, subnet_mask, network_address);
        calculate_broadcast_address(ip_address, subnet_mask, broadcast_address);
        no_of_hosts = calculate_no_of_hosts(cidr);

        printf("\n========================================\n");
        printf("IP Address: ");
        display_ip_address(ip_address);
        printf("\nSubnet Mask: ");
        display_subnet_mask(subnet_mask);
        printf("\nNetwork Address: ");
        display_ip_address(network_address);
        printf("\nBroadcast Address: ");
        display_ip_address(broadcast_address);
        printf("\nNumber of Hosts in the Subnet: %d", no_of_hosts);
        printf("\n========================================\n");

        printf("\nDo you want to continue (Y/N)? ");
        scanf("%s", &choice);

    } while (choice == 'y' || choice == 'Y');

    return 0;
}