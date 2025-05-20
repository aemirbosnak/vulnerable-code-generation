//Falcon-180B DATASET v1.0 Category: Subnet Calculator ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate subnet mask
void calculate_subnet(int ip_address[], int subnet_mask[]) {
    int i;
    
    // Copy IP address to subnet mask
    for(i=0; i<4; i++) {
        subnet_mask[i] = ip_address[i];
    }
    
    // Set the last byte to 255
    subnet_mask[3] = 255;
}

// Function to print IP address and subnet mask
void print_ip_and_subnet(int ip_address[], int subnet_mask[]) {
    int i;
    
    printf("IP Address: ");
    for(i=0; i<4; i++) {
        printf("%d. ", ip_address[i]);
    }
    printf("\n");
    
    printf("Subnet Mask: ");
    for(i=0; i<4; i++) {
        printf("%d. ", subnet_mask[i]);
    }
    printf("\n");
}

// Function to get IP address from user
void get_ip_address(int ip_address[]) {
    int i;
    
    printf("Enter the IP address: ");
    scanf("%d. %d. %d. %d", &ip_address[0], &ip_address[1], &ip_address[2], &ip_address[3]);
    
    // Check if IP address is valid
    for(i=0; i<4; i++) {
        if(ip_address[i] < 0 || ip_address[i] > 255) {
            printf("Invalid IP address.\n");
            exit(1);
        }
    }
}

int main() {
    int ip_address[4];
    int subnet_mask[4];
    
    // Get IP address from user
    get_ip_address(ip_address);
    
    // Calculate subnet mask
    calculate_subnet(ip_address, subnet_mask);
    
    // Print IP address and subnet mask
    print_ip_and_subnet(ip_address, subnet_mask);
    
    return 0;
}