//Falcon-180B DATASET v1.0 Category: Wireless Network Scanner ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netinet/in.h>

#define BUF_LEN 1024

int main() {
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        printf("Error creating socket: %d\n", errno);
        exit(1);
    }

    struct ifreq ifr;
    strcpy(ifr.ifr_name, "wlan0");

    if (ioctl(sock, SIOCGIFHWADDR, &ifr) < 0) {
        printf("Error getting interface hardware address: %d\n", errno);
        exit(1);
    }

    char mac[18];
    sprintf(mac, "%02X:%02X:%02X:%02X:%02X:%02X",
            ifr.ifr_hwaddr.sa_data[0],
            ifr.ifr_hwaddr.sa_data[1],
            ifr.ifr_hwaddr.sa_data[2],
            ifr.ifr_hwaddr.sa_data[3],
            ifr.ifr_hwaddr.sa_data[4],
            ifr.ifr_hwaddr.sa_data[5]);

    printf("MAC address: %s\n", mac);

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(12345);
    inet_pton(AF_INET, "192.168.1.100", &server_addr.sin_addr);

    char buffer[BUF_LEN];
    int bytes_received = recvfrom(sock, buffer, BUF_LEN, 0, NULL, NULL);
    if (bytes_received < 0) {
        printf("Error receiving data: %d\n", errno);
        exit(1);
    }

    printf("Received %d bytes:\n", bytes_received);
    for (int i = 0; i < bytes_received; i++) {
        printf("%02X ", buffer[i]);
    }
    printf("\n");

    close(sock);
    return 0;
}