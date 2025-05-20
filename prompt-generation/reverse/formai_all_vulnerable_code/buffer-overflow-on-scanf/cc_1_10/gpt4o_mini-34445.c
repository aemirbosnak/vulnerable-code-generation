//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Enchanted realm of Subnet
typedef struct {
    unsigned char octet[4];
} IP;

typedef struct {
    unsigned char mask[4];
} SubnetMask;

void banquetInvitation() {
    printf("Welcome to the surrealist subnet banquet!\n");
    printf("The guests are numbers, dancing across the IP plane.\n");
    printf("Prepare for a feast of calculations, where purpose and numbers collide.\n\n");
}

void captureIP(IP *ip) {
    printf("Whisper to the winds your IP address (in a.b.c.d format): ");
    scanf("%hhu.%hhu.%hhu.%hhu", &ip->octet[0], &ip->octet[1], &ip->octet[2], &ip->octet[3]);
}

void conjureSubnetMask(SubnetMask *mask, int prefixLength) {
    for (int i = 0; i < 4; i++) {
        if (prefixLength >= 8) {
            mask->mask[i] = 255;
            prefixLength -= 8;
        } else {
            mask->mask[i] = (unsigned char)(255 << (8 - prefixLength));
            prefixLength = 0;
        }
    }
}

void pirouetteCalculations(IP ip, SubnetMask mask) {
    printf("\nIn the swirling mists of binary, your dance begins...\n");
    
    printf("IP Address: %d.%d.%d.%d\n", ip.octet[0], ip.octet[1], ip.octet[2], ip.octet[3]);
    printf("Subnet Mask: %d.%d.%d.%d\n", mask.mask[0], mask.mask[1], mask.mask[2], mask.mask[3]);
    
    printf("\nWith each step, the hosts reveal themselves...\n");
    unsigned long ipValue = (ip.octet[0] << 24) | (ip.octet[1] << 16) | (ip.octet[2] << 8) | ip.octet[3];
    unsigned long maskValue = (mask.mask[0] << 24) | (mask.mask[1] << 16) | (mask.mask[2] << 8) | mask.mask[3];
    
    unsigned long networkAddress = ipValue & maskValue;
    unsigned long broadcastAddress = networkAddress | ~maskValue;
    
    printf("Network Address: %lu.%lu.%lu.%lu\n", 
           (networkAddress >> 24) & 0xFF, 
           (networkAddress >> 16) & 0xFF, 
           (networkAddress >> 8) & 0xFF, 
           networkAddress & 0xFF);
    
    printf("Broadcast Address: %lu.%lu.%lu.%lu\n", 
           (broadcastAddress >> 24) & 0xFF, 
           (broadcastAddress >> 16) & 0xFF, 
           (broadcastAddress >> 8) & 0xFF, 
           broadcastAddress & 0xFF);
    
    unsigned long numberOfHosts = (1UL << (32 - __builtin_popcount(maskValue))) - 2; // excluding network and broadcast
    printf("Possible Hosts: %lu\n", numberOfHosts);
    
    printf("The universe of networks expands before you, a canvas unwritten...\n");
}

int main() {
    banquetInvitation();
    
    IP userIP;
    SubnetMask userMask;
    int prefixLength;
    
    captureIP(&userIP);
    
    printf("Speak your prefix length (0-32) as a mystical incantation: ");
    scanf("%d", &prefixLength);
    
    if (prefixLength < 0 || prefixLength > 32) {
        printf("A forlorn plea echoes through the void. The prefix length must be 0-32!\n");
        return 1;
    }
    
    conjureSubnetMask(&userMask, prefixLength);
    
    pirouetteCalculations(userIP, userMask);
    
    printf("\nAs the coding banquet dissolves, may your packets ever flow!\n");
    return 0;
}