//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>
#include <string.h>

#define MAX_BUFFER 2048

int main(int argc, char **argv) {
    int sock_fd;
    struct sockaddr_in addr;
    char buffer[MAX_BUFFER];
    char *ip_address, *netmask, *ssid, *encryption;
    int i, success = 0;

    // Create socket
    if ((sock_fd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0) {
        fprintf(stderr, "Error creating socket: %s\n", strerror(errno));
        exit(1);
    }

    // Set broadcast option
    int broadcastEnable = 1;
    int ret = setsockopt(sock_fd, SOL_SOCKET, SO_BROADCAST, &broadcastEnable, sizeof(broadcastEnable));
    if (ret) {
        fprintf(stderr, "Error setting broadcast option: %s\n", strerror(errno));
        exit(1);
    }

    // Bind socket
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(0);
    if (bind(sock_fd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        fprintf(stderr, "Error binding socket: %s\n", strerror(errno));
        exit(1);
    }

    // Send broadcast
    addr.sin_addr.s_addr = inet_addr("255.255.255.255");
    addr.sin_port = htons(30718);
    sprintf(buffer, "SCAN");
    if (sendto(sock_fd, buffer, sizeof(buffer), 0, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        fprintf(stderr, "Error sending broadcast: %s\n", strerror(errno));
        exit(1);
    }

    // Listen for responses
    struct sockaddr_in recv_addr;
    int recv_len;
    while (1) {
        recv_len = sizeof(recv_addr);
        memset((char *)&recv_addr, 0, sizeof(recv_addr));
        recvfrom(sock_fd, buffer, sizeof(buffer), 0, (struct sockaddr *)&recv_addr, &recv_len);

        // Parse response
        ip_address = strtok(buffer, ",");
        if (!ip_address) break;
        netmask = strtok(NULL, ",");
        if (!netmask) break;
        ssid = strtok(NULL, ",");
        if (!ssid) break;
        encryption = strtok(NULL, ",");
        if (!encryption) break;

        // Print results
        printf("IP Address: %s\nNetmask: %s\nSSID: %s\nEncryption: %s\n\n", ip_address, netmask, ssid, encryption);
        success = 1;
    }

    // Check if any networks were found
    if (!success) {
        printf("No networks found.\n");
    }

    close(sock_fd);
    return 0;
}