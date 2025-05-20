//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Initialize the noble data structures to hold domain information
typedef struct {
    unsigned char octet[4];
} IPAddress;

typedef struct {
    int prefixLength;
    IPAddress subnetMask;
    IPAddress networkAddress;
    IPAddress broadcastAddress;
} Subnet;

// A noble function to compute the subnet mask
void computeSubnetMask(Subnet* s) {
    for (int i = 0; i < 4; i++) {
        if (s->prefixLength >= 8) {
            s->subnetMask.octet[i] = 255;
            s->prefixLength -= 8;
        } else {
            s->subnetMask.octet[i] = (unsigned char)(255 << (8 - s->prefixLength));
            for (int j = i + 1; j < 4; j++) {
                s->subnetMask.octet[j] = 0;
            }
            break;
        }
    }
}

// A majestic function to compute the network address
void computeNetworkAddress(Subnet* s, IPAddress* ip) {
    for (int i = 0; i < 4; i++) {
        s->networkAddress.octet[i] = ip->octet[i] & s->subnetMask.octet[i];
    }
}

// A noble function to compute the broadcast address
void computeBroadcastAddress(Subnet* s) {
    for (int i = 0; i < 4; i++) {
        s->broadcastAddress.octet[i] = s->networkAddress.octet[i] | ~s->subnetMask.octet[i];
    }
}

// A function to display an IP address in a regal manner
void displayIPAddress(const IPAddress* ip) {
    printf("%d.%d.%d.%d\n", ip->octet[0], ip->octet[1], ip->octet[2], ip->octet[3]);
}

// A function to exhibit the riches of the subnet
void displaySubnetInfo(const Subnet* s, const IPAddress* ip) {
    printf("Thine IP Address: ");
    displayIPAddress(ip);
    printf("Noble Subnet Mask: ");
    displayIPAddress(&s->subnetMask);
    printf("Majestic Network Address: ");
    displayIPAddress(&s->networkAddress);
    printf("Bountiful Broadcast Address: ");
    displayIPAddress(&s->broadcastAddress);
    printf("\n");
}

// The grand entrance of our noble program
int main() {
    // Declare mighty variables
    IPAddress nobleIp;
    Subnet nobleSubnet;

    // Cast thine eyes upon the user input
    printf("Enter thine noble IP Address (format: a.b.c.d): ");
    scanf("%hhu.%hhu.%hhu.%hhu", &nobleIp.octet[0], &nobleIp.octet[1], &nobleIp.octet[2], &nobleIp.octet[3]);

    printf("Enter thine prefix length (between 0 and 32): ");
    scanf("%d", &nobleSubnet.prefixLength);

    // Ensure the prefix length is of noble character
    if (nobleSubnet.prefixLength < 0 || nobleSubnet.prefixLength > 32) {
        printf("Alas! The prefix length must be between 0 and 32!\n");
        return 1;
    }

    // Make haste, compute the subnet information
    computeSubnetMask(&nobleSubnet);
    computeNetworkAddress(&nobleSubnet, &nobleIp);
    computeBroadcastAddress(&nobleSubnet);

    // Exhibit the treasures of our calculations
    displaySubnetInfo(&nobleSubnet, &nobleIp);

    return 0;
}