//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct IP {
    int octets[4];
};

struct SubnetInfo {
    struct IP network;
    struct IP broadcast;
    struct IP firstUsable;
    struct IP lastUsable;
};

void parseIP(char *ipStr, struct IP *ip) {
    sscanf(ipStr, "%d.%d.%d.%d", &ip->octets[0], &ip->octets[1], &ip->octets[2], &ip->octets[3]);
}

void printIP(struct IP ip) {
    printf("%d.%d.%d.%d", ip.octets[0], ip.octets[1], ip.octets[2], ip.octets[3]);
}

struct SubnetInfo calculateSubnet(struct IP ip, int subnetMask) {
    struct SubnetInfo info;
    
    // Calculate Network Address
    for (int i = 0; i < 4; i++) {
        if (subnetMask >= 8) {
            info.network.octets[i] = ip.octets[i];
        } else {
            info.network.octets[i] = ip.octets[i] & (255 << (8 - subnetMask));
            subnetMask -= 8;
        }
    }
    
    // Calculate Broadcast Address
    for (int i = 0; i < 4; i++) {
        if (subnetMask >= 8) {
            info.broadcast.octets[i] = ip.octets[i];
        } else {
            info.broadcast.octets[i] = ip.octets[i] | ~(255 << (8 - subnetMask));
            subnetMask -= 8;
        }
    }
    
    // Calculate First Usable Address
    info.firstUsable = info.network;
    info.firstUsable.octets[3] += 1; // Increment the last octet by 1

    // Calculate Last Usable Address
    info.lastUsable = info.broadcast;
    info.lastUsable.octets[3] -= 1; // Decrement the last octet by 1

    return info;
}

int main() {
    char ipStr[16];
    int subnetMask;
    
    printf("Enter an IP address (x.x.x.x): ");
    scanf("%s", ipStr);
    
    printf("Enter subnet mask (8, 16, 24): ");
    scanf("%d", &subnetMask);
    
    struct IP ip;
    parseIP(ipStr, &ip);
    
    struct SubnetInfo info = calculateSubnet(ip, subnetMask);

    printf("\nNetwork Address: ");
    printIP(info.network);
    
    printf("\nBroadcast Address: ");
    printIP(info.broadcast);
    
    printf("\nFirst Usable IP: ");
    printIP(info.firstUsable);
    
    printf("\nLast Usable IP: ");
    printIP(info.lastUsable);
    
    printf("\n");
    
    return 0;
}