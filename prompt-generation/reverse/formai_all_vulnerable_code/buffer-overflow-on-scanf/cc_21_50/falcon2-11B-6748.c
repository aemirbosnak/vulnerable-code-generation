//Falcon2-11B DATASET v1.0 Category: Network Topology Mapper ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char hostname[100];
    char ipaddr[100];
    char netmask[100];
    char gateway[100];

    printf("Enter hostname: ");
    scanf("%s", hostname);

    printf("Enter IP address: ");
    scanf("%s", ipaddr);

    printf("Enter network mask: ");
    scanf("%s", netmask);

    printf("Enter gateway: ");
    scanf("%s", gateway);

    // convert ip address to binary format
    char binary[100];
    sprintf(binary, "%d.%d.%d.%d", atoi(ipaddr + 0) & 0xff, atoi(ipaddr + 1) & 0xff, atoi(ipaddr + 2) & 0xff, atoi(ipaddr + 3) & 0xff);

    // convert network mask to binary format
    char mask_binary[100];
    sprintf(mask_binary, "%d.%d.%d.%d", atoi(netmask + 0) & 0xff, atoi(netmask + 1) & 0xff, atoi(netmask + 2) & 0xff, atoi(netmask + 3) & 0xff);

    // check if hostname is valid
    if (strlen(hostname) < 1 || strlen(hostname) > 63) {
        printf("Invalid hostname length");
        return 1;
    }

    // check if IP address is valid
    if (strlen(ipaddr) < 1 || strlen(ipaddr) > 255) {
        printf("Invalid IP address length");
        return 1;
    }

    // check if network mask is valid
    if (strlen(netmask) < 1 || strlen(netmask) > 32) {
        printf("Invalid network mask length");
        return 1;
    }

    // check if gateway is valid
    if (strlen(gateway) < 1 || strlen(gateway) > 255) {
        printf("Invalid gateway length");
        return 1;
    }

    // check if IP address and network mask are valid
    if (atoi(ipaddr + 0) < 0 || atoi(ipaddr + 0) > 255 || atoi(ipaddr + 1) < 0 || atoi(ipaddr + 1) > 255 || atoi(ipaddr + 2) < 0 || atoi(ipaddr + 2) > 255 || atoi(ipaddr + 3) < 0 || atoi(ipaddr + 3) > 255) {
        printf("Invalid IP address");
        return 1;
    }

    if (atoi(netmask + 0) < 0 || atoi(netmask + 0) > 255 || atoi(netmask + 1) < 0 || atoi(netmask + 1) > 255 || atoi(netmask + 2) < 0 || atoi(netmask + 2) > 255 || atoi(netmask + 3) < 0 || atoi(netmask + 3) > 255) {
        printf("Invalid network mask");
        return 1;
    }

    // check if gateway is in the same network as host
    if (strncmp(gateway, ipaddr, strlen(gateway)) == 0) {
        printf("Gateway is in the same network as host");
        return 1;
    }

    // check if gateway is in the same network as host and has the same IP address
    if (strncmp(gateway, binary, strlen(binary)) == 0) {
        printf("Gateway is in the same network as host and has the same IP address");
        return 1;
    }

    // check if gateway is in the same network as host and has the same IP address and the same network mask
    if (strncmp(gateway, mask_binary, strlen(mask_binary)) == 0) {
        printf("Gateway is in the same network as host and has the same IP address and the same network mask");
        return 1;
    }

    printf("Gateway is not in the same network as host");

    return 0;
}