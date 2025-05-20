//GPT-4o-mini DATASET v1.0 Category: Subnet Calculator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <arpa/inet.h>

#define MAX_LEN 16

void calculateSubnet(const char *ip, int prefix);
void convertPrefixToSubnet(int prefix, uint8_t *subnetMask);
void printSubnetDetails(uint8_t *subnetMask, const char *ip, int prefix);

int main() {
    char ip[MAX_LEN];
    int prefix;

    printf("🎉 Welcome to the C Subnet Calculator! 🎉\n");
    printf("Please enter the IP address (xxx.xxx.xxx.xxx): ");
    scanf("%s", ip);
    printf("Now, enter the subnet prefix (0-32): ");
    scanf("%d", &prefix);

    if (prefix < 0 || prefix > 32) {
        printf("😱 Oops! Invalid prefix! It should be between 0 and 32.\n");
        return EXIT_FAILURE;
    }

    calculateSubnet(ip, prefix);
    return EXIT_SUCCESS;
}

void calculateSubnet(const char *ip, int prefix) {
    uint8_t subnetMask[4] = {0};
    convertPrefixToSubnet(prefix, subnetMask);
    printSubnetDetails(subnetMask, ip, prefix);
}

void convertPrefixToSubnet(int prefix, uint8_t *subnetMask) {
    for (int i = 0; i < 4; i++) {
        if (prefix >= 8) {
            subnetMask[i] = 255;
            prefix -= 8;
        } else {
            subnetMask[i] = prefix == 0 ? 0 : (255 << (8 - prefix)) & 255;
            break;
        }
    }
}

void printSubnetDetails(uint8_t *subnetMask, const char *ip, int prefix) {
    struct in_addr ipAddr;
    if (inet_pton(AF_INET, ip, &ipAddr) != 1) {
        printf("🤯 Invalid IP address!\n");
        return;
    }

    printf("🏠 Calculating for IP: %s/%d...\n", ip, prefix);
    printf("🌐 Subnet Mask: %d.%d.%d.%d\n", subnetMask[0], subnetMask[1], subnetMask[2], subnetMask[3]);

    uint32_t ipNet = ntohl(ipAddr.s_addr) & (subnetMask[0] << 24 | subnetMask[1] << 16 | subnetMask[2] << 8 | subnetMask[3]);
    uint32_t numHosts = (1 << (32 - prefix)) - 2; // -2 for network and broadcast addresses

    printf("🔍 Network Address: %d.%d.%d.%d\n", (ipNet >> 24) & 0xFF, (ipNet >> 16) & 0xFF, (ipNet >> 8) & 0xFF, ipNet & 0xFF);
    printf("🛑 Total Usable Hosts: %u\n", numHosts);

    uint32_t startHost = ipNet + 1;
    uint32_t endHost = ipNet + numHosts + 1;
    printf("📦 Usable IP Range: %d.%d.%d.%d - %d.%d.%d.%d\n",
           (startHost >> 24) & 0xFF, (startHost >> 16) & 0xFF, (startHost >> 8) & 0xFF, startHost & 0xFF,
           (endHost >> 24) & 0xFF, (endHost >> 16) & 0xFF, (endHost >> 8) & 0xFF, endHost & 0xFF);

    // Broadcast address
    uint32_t broadcastAddr = ipNet + numHosts + 1;
    printf("📡 Broadcast Address: %d.%d.%d.%d\n", (broadcastAddr >> 24) & 0xFF, (broadcastAddr >> 16) & 0xFF,
           (broadcastAddr >> 8) & 0xFF, broadcastAddr & 0xFF);
}