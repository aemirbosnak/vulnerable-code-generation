//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct subnet_t {
    unsigned char address[4];
    unsigned int mask;
} subnet_t;

subnet_t calculate_subnet(const char *ip_addr, const char *subnet_mask) {
    subnet_t subnet;
    char *tok;
    int octet = 0;

    // Parse IP address
    tok = strtok((char *) ip_addr, ".");
    while (tok) {
        subnet.address[octet++] = atoi(tok);
        tok = strtok(NULL, ".");
    }

    // Parse subnet mask
    subnet.mask = atoi(subnet_mask);

    // Calculate subnet address
    unsigned int num_hosts = pow(2, (32 - subnet.mask)) - 2;
    unsigned int mask = ~(0xFFFFFFFF >> subnet.mask);
    unsigned int network_addr = *(unsigned int *) &subnet.address & mask;

    // Store subnet address in subnet struct
    memcpy(subnet.address, &network_addr, sizeof(network_addr));

    return subnet;
}

int main() {
    char ip_addr[16];
    char subnet_mask_str[3];
    subnet_t subnet;
    unsigned int i, octet;
    char *tok;

    // Ask for IP Address and Subnet Mask
    printf("Enter IP Address: ");
    scanf("%s", ip_addr);
    printf("Enter Subnet Mask (CIDR): ");
    scanf("%s", subnet_mask_str);

    // Calculate Subnet Address
    subnet = calculate_subnet(ip_addr, subnet_mask_str);

    // Print Subnet Address and some extra information
    printf("\nSubnet Address: %d.%d.%d.%d/%d\n",
           subnet.address[0], subnet.address[1],
           subnet.address[2], subnet.address[3], subnet.mask);
    printf("Max Number of Hosts: %u\n", pow(2, (32 - subnet.mask)) - 2);
    printf("Broadcast Address: %d.%d.%d.%d\n",
           subnet.address[0] | ~(0xFF >> (subnet.mask % 8)),
           subnet.address[1] | ~(0xFF >> (subnet.mask % 8)),
           subnet.address[2] | ~(0xFF >> (subnet.mask % 8)),
           subnet.address[3] | ~(0xFF >> (subnet.mask % 8)));

    return 0;
}