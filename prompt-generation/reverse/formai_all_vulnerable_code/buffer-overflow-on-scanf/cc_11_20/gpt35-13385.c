//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    printf("Welcome to the Happy C Subnet Calculator!\n");
    printf("Enter an IP address (e.g. 192.168.1.1): ");
    
    // User input
    char ip_address[16];
    scanf("%s", ip_address);
    
    printf("Enter the subnet mask (e.g. 255.255.255.0): ");
    char subnet_mask[16];
    scanf("%s", subnet_mask);
    
    // Converting IP address and subnet mask to binary
    char *ip_binary = malloc(sizeof(char) * 35);
    char *subnet_binary = malloc(sizeof(char) * 35);
    
    for (int i=0, j=0; i<16; i++) {
        if (ip_address[i] == '.') {
            ip_binary[j] = '.';
            subnet_binary[j] = '.';
            j++;
        } else {
            int decimal = ip_address[i] - '0';
            for (int k=7; k>=0; k--) {
                ip_binary[j] = (decimal & (1 << k)) ? '1' : '0';
                decimal <<= 1;
                subnet_binary[j] = (subnet_mask[i] - '0' & (1 << k)) ? '1' : '0';
                j++;
            }
        }
    }
    
    // Calculating the network address and broadcast address
    char *network_address = malloc(sizeof(char) * 16);
    char *broadcast_address = malloc(sizeof(char) * 16);
    
    for (int i=0; i<32; i++) {
        if (ip_binary[i] == '.') {
            network_address[i] = '.';
            broadcast_address[i] = '.';
        } else {
            if (subnet_binary[i] == '1') {
                network_address[i] = ip_binary[i];
                broadcast_address[i] = ip_binary[i];
            } else {
                network_address[i] = '0';
                broadcast_address[i] = '1';
            }
        }
    }
    
    // Printing results
    printf("IP address: %s\n", ip_address);
    printf("Subnet mask: %s\n", subnet_mask);
    printf("Network address: ");
    for (int i=0; i<32; i+=8) {
        printf("%d.", strtol(&network_address[i], NULL, 2));
    }
    printf("\n");
    printf("Broadcast address: ");
    for (int i=0; i<32; i+=8) {
        printf("%d.", strtol(&broadcast_address[i], NULL, 2));
    }
    printf("\n");
    
    // Freeing memory
    free(ip_binary);
    free(subnet_binary);
    free(network_address);
    free(broadcast_address);
    
    printf("Thank you for using the Happy C Subnet Calculator! :)");
    return 0;
}