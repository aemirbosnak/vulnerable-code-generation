//Falcon2-11B DATASET v1.0 Category: Subnet Calculator ; Style: cheerful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define MAX_IP_LENGTH 16

int getSubnetMask(int mask) {
    if (mask == 0) {
        return 0;
    } else {
        int i = 0;
        while (mask!= 0) {
            if ((mask & 1) == 1) {
                i++;
            }
            mask = 1;
        }
        return i;
    }
}

int getHostMask(int mask) {
    int i = 0;
    while (mask!= 0) {
        if ((mask & 1) == 1) {
            i++;
        }
        mask = 1;
    }
    return ~(i + 1);
}

int getNetwork(int ip, int mask) {
    int net = ip & mask;
    return net;
}

int getSubnet(int ip, int mask) {
    int subnet = ip & ~mask;
    return subnet;
}

int getBroadcast(int ip, int mask) {
    int bcast = ip | ~mask;
    return bcast;
}

int getNetworkPrefix(int ip, int mask) {
    return (ip & mask) + 1;
}

int main() {
    int ip_address;
    int subnet_mask;

    printf("Enter the IP address: ");
    scanf("%d", &ip_address);

    printf("Enter the subnet mask: ");
    scanf("%d", &subnet_mask);

    printf("Subnet mask: ");
    printf("%d\n", getSubnetMask(subnet_mask));

    printf("Host mask: ");
    printf("%d\n", getHostMask(subnet_mask));

    printf("Network address: ");
    printf("%d\n", getNetwork(ip_address, subnet_mask));

    printf("Subnet address: ");
    printf("%d\n", getSubnet(ip_address, subnet_mask));

    printf("Broadcast address: ");
    printf("%d\n", getBroadcast(ip_address, subnet_mask));

    printf("Network prefix: ");
    printf("%d\n", getNetworkPrefix(ip_address, subnet_mask));

    return 0;
}