//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_IP_LEN 16
#define MAX_SUBNET_PREFIX 32

int main() {
    char ip[MAX_IP_LEN];
    int prefix;
    
    printf("Please enter an IP address (e.g. 192.168.1.1): ");
    scanf("%15s", ip);
    
    printf("Please enter the prefix length (0 - 32): ");
    scanf("%d", &prefix);
    
    unsigned long ip_long = 0;
    int octet;
    char *end_ptr;
    
    for (int i = 0; i < 4; i++) {
        octet = strtol(strtok((i == 0) ? ip : NULL, "."), &end_ptr, 10);
        
        if (octet < 0 || octet > 255 || (*end_ptr != '\0' && *end_ptr != '.')) {
            fprintf(stderr, "Invalid IP address\n");
            return 1;
        }
        
        ip_long += (unsigned long) octet << (24 - 8 * i);
    }
    
    if (prefix < 0 || prefix > MAX_SUBNET_PREFIX) {
        fprintf(stderr, "Invalid prefix length\n");
        return 1;
    }
    
    unsigned long subnet_mask = (unsigned long) pow(2, prefix) - 1;
    subnet_mask = ~subnet_mask;
    
    unsigned long network_addr = ip_long & subnet_mask;
    unsigned long broadcast_addr = network_addr | ~subnet_mask;
    
    printf("IP address: %s\n", ip);
    printf("Prefix length: %d\n", prefix);
    printf("Subnet mask: %lu.%lu.%lu.%lu\n", (subnet_mask >> 24) & 255, (subnet_mask >> 16) & 255, (subnet_mask >> 8) & 255, subnet_mask & 255);
    printf("Network address: %lu.%lu.%lu.%lu\n", (network_addr >> 24) & 255, (network_addr >> 16) & 255, (network_addr >> 8) & 255, network_addr & 255);
    printf("Broadcast address: %lu.%lu.%lu.%lu\n", (broadcast_addr >> 24) & 255, (broadcast_addr >> 16) & 255, (broadcast_addr >> 8) & 255, broadcast_addr & 255);
    
    return 0;
}