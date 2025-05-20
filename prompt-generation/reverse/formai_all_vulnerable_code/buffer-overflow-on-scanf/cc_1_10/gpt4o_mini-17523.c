//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define IP_LEN 16
#define MAX_SUBNETS 256

void ipv4_to_bin(const char *ip, char *binary) {
    unsigned char octets[4];
    sscanf(ip, "%hhu.%hhu.%hhu.%hhu", &octets[0], &octets[1], &octets[2], &octets[3]);

    for (int i = 0; i < 4; i++) {
        for (int j = 7; j >= 0; j--) {
            binary[i * 8 + (7 - j)] = (octets[i] & (1 << j)) ? '1' : '0';
        }
    }
    binary[32] = '\0';
}

void cidr_to_subnet(const char *cidr, char *subnet) {
    int prefixLength = atoi(cidr);
    if (prefixLength < 0 || prefixLength > 32) {
        fprintf(stderr, "Error: CIDR prefix must be between 0 and 32.\n");
        exit(EXIT_FAILURE);
    }

    unsigned int netmask = (0xFFFFFFFF << (32 - prefixLength)) & 0xFFFFFFFF;

    sprintf(subnet, "%d.%d.%d.%d", 
            (netmask >> 24) & 0xFF,
            (netmask >> 16) & 0xFF,
            (netmask >> 8) & 0xFF,
            netmask & 0xFF);
}

void calculate_subnets(const char *ip, int prefixLength) {
    char binary[33];
    ipv4_to_bin(ip, binary);

    printf("\nSubnet Information:\n");
    printf("IP Address: %s\n", ip);
    printf("Network Mask: /%d\n", prefixLength);
    
    // Subnetting Logic
    int total_subnets = pow(2, (32 - prefixLength));
    if (total_subnets > MAX_SUBNETS) {
        total_subnets = MAX_SUBNETS;
    }
    
    printf("Total Subnets Available: %d\n", total_subnets);
    printf("Subnet Addresses:\n");

    for (int i = 0; i < total_subnets; i++) {
        unsigned int subnetAddr = (inet_addr(ip) & (0xFFFFFFFF << (32 - prefixLength))) | (i << (32 - prefixLength));
        printf("%d.%d.%d.%d\n", 
            (subnetAddr >> 24) & 0xFF,
            (subnetAddr >> 16) & 0xFF,
            (subnetAddr >> 8) & 0xFF,
            subnetAddr & 0xFF);
    }
}

int main() {
    char ip[IP_LEN];
    char cidr[4];
    
    printf("Enter a valid IPv4 Address (format: xxx.xxx.xxx.xxx): ");
    scanf("%s", ip);
    
    printf("Enter CIDR prefix (e.g. 24 for /24): ");
    scanf("%s", cidr);
    
    int prefixLength = atoi(cidr);
    if (prefixLength <= 0 || prefixLength > 32) {
        fprintf(stderr, "Error: CIDR must be between 1 and 32.\n");
        return EXIT_FAILURE;
    }

    char subnet[IP_LEN];
    cidr_to_subnet(cidr, subnet);
    
    printf("Subnet Mask for /%d is: %s\n", prefixLength, subnet);
    
    calculate_subnets(ip, prefixLength);
    
    return EXIT_SUCCESS;
}