//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define MAX_SUBNETS 256

typedef struct {
    uint8_t octets[4];
    uint8_t subnet_mask[4];
    uint32_t num_hosts;
    uint32_t num_subnets;
} SubnetInfo;

void displaySubnetInfo(SubnetInfo *subnet) {
    printf("Subnet: %u.%u.%u.%u\n", subnet->octets[0], subnet->octets[1], subnet->octets[2], subnet->octets[3]);
    printf("Subnet Mask: %u.%u.%u.%u\n", subnet->subnet_mask[0], subnet->subnet_mask[1], subnet->subnet_mask[2], subnet->subnet_mask[3]);
    printf("Number of Hosts: %u\n", subnet->num_hosts);
    printf("Number of Subnets: %u\n", subnet->num_subnets);
}

void calculateSubnet(SubnetInfo *subnet, int prefix) {
    // Calculate subnet mask
    for (int i = 0; i < 4; i++) {
        if (prefix >= 8) {
            subnet->subnet_mask[i] = 255;
            prefix -= 8;
        } else {
            subnet->subnet_mask[i] = 256 - (1 << (8 - prefix));
            break;
        }
    }

    // Calculate number of hosts
    subnet->num_hosts = (1 << (32 - prefix)) - 2; // Subtracting 2 for network & broadcast addresses

    // Calculate number of subnets (assuming Class C)
    if (prefix > 24) {
        subnet->num_subnets = 1 << (prefix - 24);
    } else {
        subnet->num_subnets = 1; // No additional subnets for Class C
    }
}

void getIpOctets(const char *ip, uint8_t *octets) {
    char *token;
    char *ip_copy = strdup(ip);
    int i = 0;

    token = strtok(ip_copy, ".");
    while (token != NULL && i < 4) {
        octets[i++] = (uint8_t)atoi(token);
        token = strtok(NULL, ".");
    }

    free(ip_copy);
}

int main() {
    SubnetInfo subnet;
    char ip[16];
    int prefix;

    printf("Welcome to the C Subnet Calculator!\n");
    printf("Enter an IP address (e.g., 192.168.1.0) : ");
    fgets(ip, sizeof(ip), stdin);
    ip[strcspn(ip, "\n")] = 0; // Remove the newline character

    getIpOctets(ip, subnet.octets);

    printf("Enter the prefix length (e.g., 24): ");
    scanf("%d", &prefix);

    // Ensure valid prefix length
    if (prefix < 0 || prefix > 32) {
        printf("Invalid prefix length. Prefix must be between 0 and 32.\n");
        return 1;
    }

    calculateSubnet(&subnet, prefix);
    
    displaySubnetInfo(&subnet);

    printf("Thank you for using the C Subnet Calculator!\n");

    return 0;
}