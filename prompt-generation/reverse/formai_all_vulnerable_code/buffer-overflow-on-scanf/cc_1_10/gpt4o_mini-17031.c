//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SUBNETS 100
#define IP_ADDRESS_LENGTH 16

void display_welcome_message() {
    printf("==========================================\n");
    printf("       Welcome to the Visionary C Subnet     \n");
    printf("              Calculator!                     \n");
    printf("==========================================\n");
}

void split_ip(const char *ip, int *parts) {
    char *token;
    char ip_copy[IP_ADDRESS_LENGTH];
    strcpy(ip_copy, ip);
    
    token = strtok(ip_copy, ".");
    for (int i = 0; i < 4 && token != NULL; i++) {
        parts[i] = atoi(token);
        token = strtok(NULL, ".");
    }
}

int calculate_subnets(int subnet_mask) {
    return pow(2, (32 - subnet_mask));
}

void display_subnets(int total_subnets) {
    printf("\nTotal Number of Subnets: %d\n", total_subnets);
    for (int i = 0; i < total_subnets; i++) {
        printf("Subnet %d: ", i + 1);
        // Display subnets in a visionary way.
        printf("This is a virtual realm number %d in the vast network universe!\n", i + 1);
    }
}

int main() {
    char ip_address[IP_ADDRESS_LENGTH];
    int subnet_mask;

    display_welcome_message();

    printf("Please enter the IP address (Format: xxx.xxx.xxx.xxx): ");
    scanf("%s", ip_address);

    printf("Please enter the subnet mask (in CIDR format, e.g., 24): ");
    scanf("%d", &subnet_mask);

    // Validate IP address
    int ip_parts[4];
    split_ip(ip_address, ip_parts);
    
    for (int i = 0; i < 4; i++) {
        if (ip_parts[i] < 0 || ip_parts[i] > 255) {
            printf("Invalid IP Address!\n");
            return 1;
        }
    }

    // Validate subnet mask
    if (subnet_mask < 0 || subnet_mask > 32) {
        printf("Invalid Subnet Mask!\n");
        return 1;
    }

    int total_subnets = calculate_subnets(subnet_mask);
    
    printf("\nIP Address: %s\nSubnet Mask: /%d\n", ip_address, subnet_mask);
    display_subnets(total_subnets);

    printf("\nThank you for using the Visionary C Subnet Calculator!\n");
    printf("May your networking journey be prosperous!\n");

    return 0;
}