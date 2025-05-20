//FormAI DATASET v1.0 Category: Subnet Calculator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct IPAddress {
    int octet1;
    int octet2;
    int octet3;
    int octet4;
} IPAddress;

typedef struct SubnetMask {
    int maskBits;
    IPAddress maskIPAddress;
} SubnetMask;

typedef struct IPNetwork {
    SubnetMask subnetMask;
    IPAddress networkAddress;
    IPAddress broadcastAddress;
} IPNetwork;

void printIPAddress(IPAddress ip) {
    printf("%d.%d.%d.%d", ip.octet1, ip.octet2, ip.octet3, ip.octet4);
}

void printSubnetMask(SubnetMask sm) {
    printIPAddress(sm.maskIPAddress);
}

IPAddress calculateNetworkAddress(IPAddress ip, SubnetMask sm) {
    IPAddress networkAddress;
    networkAddress.octet1 = ip.octet1 & sm.maskIPAddress.octet1;
    networkAddress.octet2 = ip.octet2 & sm.maskIPAddress.octet2;
    networkAddress.octet3 = ip.octet3 & sm.maskIPAddress.octet3;
    networkAddress.octet4 = ip.octet4 & sm.maskIPAddress.octet4;
    return networkAddress;
}

IPAddress calculateBroadcastAddress(IPAddress ip, SubnetMask sm) {
    IPAddress broadcastAddress;
    broadcastAddress.octet1 = ip.octet1 | (~sm.maskIPAddress.octet1 & 0xFF);
    broadcastAddress.octet2 = ip.octet2 | (~sm.maskIPAddress.octet2 & 0xFF);
    broadcastAddress.octet3 = ip.octet3 | (~sm.maskIPAddress.octet3 & 0xFF);
    broadcastAddress.octet4 = ip.octet4 | (~sm.maskIPAddress.octet4 & 0xFF);
    return broadcastAddress;
}

int main() {
    IPAddress ip;
    SubnetMask sm;
    IPNetwork network;

    printf("Enter the IP address (ex. 192.168.1.1): ");
    scanf("%d.%d.%d.%d", &ip.octet1, &ip.octet2, &ip.octet3, &ip.octet4);

    printf("Enter the subnet mask (ex. 255.255.255.0): ");
    scanf("%d.%d.%d.%d", &sm.maskIPAddress.octet1, &sm.maskIPAddress.octet2, &sm.maskIPAddress.octet3, &sm.maskIPAddress.octet4);

    if (sm.maskIPAddress.octet1 < 0 || sm.maskIPAddress.octet1 > 255 ||
        sm.maskIPAddress.octet2 < 0 || sm.maskIPAddress.octet2 > 255 ||
        sm.maskIPAddress.octet3 < 0 || sm.maskIPAddress.octet3 > 255 ||
        sm.maskIPAddress.octet4 < 0 || sm.maskIPAddress.octet4 > 255) {
        printf("Invalid subnet mask.\n");
        exit(1);
    }

    // count the number of bits turned on in the subnet mask
    int c = 0;
    for (int i = 0; i < 32 && i < sm.maskBits; i++) {
        int bit = 1 << (31 - i);
        if ((sm.maskIPAddress.octet1 & bit) ||
            (sm.maskIPAddress.octet2 & bit) ||
            (sm.maskIPAddress.octet3 & bit) ||
            (sm.maskIPAddress.octet4 & bit)) {
            c++;
        }
    }
    sm.maskBits = c;

    network.subnetMask = sm;
    network.networkAddress = calculateNetworkAddress(ip, sm);
    network.broadcastAddress = calculateBroadcastAddress(ip, sm);

    printf("\nIP address: ");
    printIPAddress(ip);

    printf("\nSubnet mask: ");
    printSubnetMask(sm);

    printf("\nNetwork address: ");
    printIPAddress(network.networkAddress);

    printf("\nBroadcast address: ");
    printIPAddress(network.broadcastAddress);

    printf("\nTotal number of hosts: %d\n", (int)pow(2, (32 - sm.maskBits)) - 2);
    
    return 0;
}