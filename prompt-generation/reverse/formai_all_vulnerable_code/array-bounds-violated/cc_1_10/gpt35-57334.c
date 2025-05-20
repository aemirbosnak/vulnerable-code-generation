//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <net/if.h>

#define MAX_INTERFACES 16
#define MAX_BUFFER_SIZE 1024

int main(void) {

    struct ifreq ifaces[MAX_INTERFACES];
    struct sockaddr_in *sin;
    int sock, count, ifaces_count, i, j, k;
    char buffer[MAX_BUFFER_SIZE];
    unsigned char mac_address[6];

    // Open socket to get list of network interfaces
    sock = socket(PF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        exit(1);
    }

    // Get list of network interfaces
    ifaces_count = 0;
    count = ioctl(sock, SIOCGIFCONF, ifaces);
    if (count < 0) {
        perror("ioctl");
        exit(1);
    }

    // Loop through network interfaces
    for (i = 0; i < count / sizeof(struct ifreq); i++) {
        // Check if this is a wireless network interface
        if (ioctl(sock, SIOCGIFFLAGS, &ifaces[i]) < 0) {
            perror("ioctl");
            exit(1);
        }
        if (!(ifaces[i].ifr_flags & IFF_UP) || (ifaces[i].ifr_flags & IFF_LOOPBACK))
            continue;
        if (ioctl(sock, SIOCGIFHWADDR, &ifaces[i]) < 0) {
            perror("ioctl");
            exit(1);
        }

        // Get MAC address of interface
        memcpy(mac_address, ifaces[i].ifr_hwaddr.sa_data, 6);

        // Print scan results
        sin = (struct sockaddr_in *)&ifaces[i].ifr_addr;
        inet_ntop(AF_INET, &sin->sin_addr, buffer, sizeof(buffer));
        printf("Wireless interface %d - MAC: %02X:%02X:%02X:%02X:%02X:%02X, IP address: %s\n", i + 1,
               mac_address[0], mac_address[1], mac_address[2], mac_address[3], mac_address[4], mac_address[5], buffer);
    }

    return 0;
}