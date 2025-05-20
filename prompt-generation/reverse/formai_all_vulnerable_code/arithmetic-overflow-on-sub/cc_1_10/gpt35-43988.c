//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: Cyberpunk
#include <stdio.h>
#include <string.h>

int main() {
    printf("     .-~~~-. \n");
    printf("    / .     \\ \n");
    printf("   / /       \\ \n");
    printf("  { {         } } \n");
    printf("   \\ \\       / / \n");
    printf("    \\ `-.___,-' \n");
    printf("     `-.___,-' \n\n");
    
    char ip_address[16];
    int subnet_mask;
    
    printf("Enter IP address in the format xxx.xxx.xxx.xxx: ");
    scanf("%s", ip_address);
    
    printf("\nEnter subnet mask in CIDR notation (0-32): ");
    scanf("%d", &subnet_mask);
    
    printf("\nCalculating subnet information...\n");
    printf("IP Address: %s/%d\n", ip_address, subnet_mask);
    
    char *token;
    int octet[4];
    
    token = strtok(ip_address, ".");
    octet[0] = atoi(token);
    token = strtok(NULL, ".");
    octet[1] = atoi(token);
    token = strtok(NULL, ".");
    octet[2] = atoi(token);
    token = strtok(NULL, ".");
    octet[3] = atoi(token);
    
    unsigned long ip_number = (octet[0] << 24) + (octet[1] << 16) + (octet[2] << 8) + octet[3];
    unsigned long subnet_mask_number = ((unsigned long)0xffffffff) << (32 - subnet_mask);
    unsigned long network_address = ip_number & subnet_mask_number;
    unsigned long broadcast_address = network_address | (~subnet_mask_number);
    
    printf("\nNetwork Address: %lu.%lu.%lu.%lu\n", (network_address >> 24) & 0xff,
                                                    (network_address >> 16) & 0xff,
                                                    (network_address >> 8) & 0xff,
                                                    network_address & 0xff);
                                                    
    printf("Broadcast Address: %lu.%lu.%lu.%lu\n", (broadcast_address >> 24) & 0xff,
                                                    (broadcast_address >> 16) & 0xff,
                                                    (broadcast_address >> 8) & 0xff,
                                                    broadcast_address & 0xff);
                                                    
    printf("Subnet Mask: ");
    if (subnet_mask <= 8) {
        printf("%d.0.0.0\n", 256 - (1 << (8 - subnet_mask)));
    } else if (subnet_mask <= 16) {
        printf("255.%d.0.0\n", 256 - (1 << (16 - subnet_mask)));
    } else if (subnet_mask <= 24) {
        printf("255.255.%d.0\n", 256 - (1 << (24 - subnet_mask)));
    } else {
        printf("255.255.255.%d\n", 256 - (1 << (32 - subnet_mask)));
    }
    
    return 0;
}