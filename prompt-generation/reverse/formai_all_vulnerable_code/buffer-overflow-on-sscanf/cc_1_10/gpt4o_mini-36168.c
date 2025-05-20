//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef struct {
    uint8_t octets[4]; // IPv4 address
} IPAddress;

typedef struct {
    IPAddress address; // Subnet Address
    IPAddress mask;    // Subnet Mask
} Subnet;

const char* convertToBinary(uint8_t octet) {
    static char binary[9];
    for (int i = 0; i < 8; i++) {
        binary[i] = (octet & (1 << (7 - i))) ? '1' : '0';
    }
    binary[8] = '\0';
    return binary;
}

void printBinarySubnet(Subnet subnet) {
    printf("Subnet: %d.%d.%d.%d\n", subnet.address.octets[0], subnet.address.octets[1], 
           subnet.address.octets[2], subnet.address.octets[3]);
    printf("Mask:   %d.%d.%d.%d\n", subnet.mask.octets[0], subnet.mask.octets[1], 
           subnet.mask.octets[2], subnet.mask.octets[3]);
    
    printf("Binary Representation:\n");
    printf("Subnet: %s.%s.%s.%s\n", 
           convertToBinary(subnet.address.octets[0]), 
           convertToBinary(subnet.address.octets[1]), 
           convertToBinary(subnet.address.octets[2]), 
           convertToBinary(subnet.address.octets[3]));
           
    printf("Mask:   %s.%s.%s.%s\n", 
           convertToBinary(subnet.mask.octets[0]), 
           convertToBinary(subnet.mask.octets[1]), 
           convertToBinary(subnet.mask.octets[2]), 
           convertToBinary(subnet.mask.octets[3]));
}

Subnet calculateSubnet(IPAddress ip, int cidr) {
    Subnet subnet;
    subnet.address = ip;     
    
    // Calculate the subnet mask based on CIDR
    for (int i = 0; i < 4; i++) {
        if (cidr >= 8) {
            subnet.mask.octets[i] = 255;
            cidr -= 8;
        } else {
            subnet.mask.octets[i] = (uint8_t)(255 << (8 - cidr)) & 255;
            cidr = 0;
        }
    }

    return subnet;
}

void takeIPAddress(IPAddress *ip) {
    printf("Enter IP address (format: xxx.xxx.xxx.xxx): ");
    char input[16];
    fgets(input, sizeof(input), stdin);
    sscanf(input, "%hhu.%hhu.%hhu.%hhu", 
           &ip->octets[0], 
           &ip->octets[1], 
           &ip->octets[2], 
           &ip->octets[3]);
}

int main() {
    IPAddress ip;
    int cidr;

    takeIPAddress(&ip);
    
    printf("Enter CIDR notation (e.g., 24 for /24): ");
    scanf("%d", &cidr);
    
    if (cidr < 0 || cidr > 32) {
        printf("CIDR value should be between 0 and 32.\n");
        return 1;
    }

    Subnet subnet = calculateSubnet(ip, cidr);
    
    printf("\nCalculated Subnet Information:\n");
    printBinarySubnet(subnet);

    return 0;
}