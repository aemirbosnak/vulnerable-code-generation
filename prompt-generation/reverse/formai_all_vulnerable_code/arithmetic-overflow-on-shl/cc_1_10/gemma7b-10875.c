//Gemma-7B DATASET v1.0 Category: Subnet Calculator ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SUBNET_MASK_BITS 32

typedef struct SubnetCalculator {
    int subnetMaskBits;
    int networkAddress;
    int hostAddress;
    int broadcastAddress;
    int numHosts;
} SubnetCalculator;

SubnetCalculator* calculateSubnet(int subnetMask, int hostCount) {
    SubnetCalculator* sc = malloc(sizeof(SubnetCalculator));
    sc->subnetMaskBits = subnetMask;
    sc->networkAddress = (subnetMask & ~0xFF) << 8 | (subnetMask & 0xFF);
    sc->hostAddress = (subnetMask & 0xFF) - 1;
    sc->broadcastAddress = sc->networkAddress | 0xFF;
    sc->numHosts = sc->hostAddress;
    return sc;
}

int main() {
    int subnetMask, hostCount;
    printf("Enter subnet mask (in binary): ");
    scanf("%d", &subnetMask);
    printf("Enter number of hosts: ");
    scanf("%d", &hostCount);

    SubnetCalculator* sc = calculateSubnet(subnetMask, hostCount);

    printf("Subnet Mask: ");
    printf("%d", sc->subnetMaskBits);
    printf("/%d", sc->subnetMaskBits);

    printf("\nNetwork Address: ");
    printf("%d.%d.%d.%d", sc->networkAddress & 0xFF, (sc->networkAddress & 0xFF00) >> 8, (sc->networkAddress & 0xFF0000) >> 16, (sc->networkAddress & 0xFF000000) >> 24);

    printf("\nBroadcast Address: ");
    printf("%d.%d.%d.%d", sc->broadcastAddress & 0xFF, (sc->broadcastAddress & 0xFF00) >> 8, (sc->broadcastAddress & 0xFF0000) >> 16, (sc->broadcastAddress & 0xFF000000) >> 24);

    printf("\nNumber of Hosts: ");
    printf("%d", sc->numHosts);

    free(sc);

    return 0;
}