//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <linux/if.h>
#include <linux/if_addr.h>
#include <arpa/inet.h>

int main(int argc, char **argv)
{
    int sock;
    struct sockaddr_in *sin;
    char *interface;
    struct ifreq ifr;
    struct in_addr addr;
    int i;

    if (argc != 2) {
        printf("Usage: %s <interface>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    interface = argv[1];

    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    memset(&ifr, 0, sizeof(ifr));
    strncpy(ifr.ifr_name, interface, IFNAMSIZ);

    if (ioctl(sock, SIOCGIFADDR, &ifr) == -1) {
        perror("ioctl");
        exit(EXIT_FAILURE);
    }

    sin = (struct sockaddr_in *) &ifr.ifr_addr;
    addr = sin->sin_addr;
    printf("IP address: %s\n", inet_ntoa(addr));

    if (ioctl(sock, SIOCGIFDSTADDR, &ifr) == -1) {
        perror("ioctl");
        exit(EXIT_FAILURE);
    }

    sin = (struct sockaddr_in *) &ifr.ifr_addr;
    addr = sin->sin_addr;
    printf("Destination address: %s\n", inet_ntoa(addr));

    if (ioctl(sock, SIOCGIFNETMASK, &ifr) == -1) {
        perror("ioctl");
        exit(EXIT_FAILURE);
    }

    sin = (struct sockaddr_in *) &ifr.ifr_addr;
    addr = sin->sin_addr;
    printf("Netmask: %s\n", inet_ntoa(addr));

    if (ioctl(sock, SIOCGIFBRDADDR, &ifr) == -1) {
        perror("ioctl");
        exit(EXIT_FAILURE);
    }

    sin = (struct sockaddr_in *) &ifr.ifr_addr;
    addr = sin->sin_addr;
    printf("Broadcast address: %s\n", inet_ntoa(addr));

    if (ioctl(sock, SIOCGIFMTU, &ifr) == -1) {
        perror("ioctl");
        exit(EXIT_FAILURE);
    }

    printf("MTU: %d\n", ifr.ifr_mtu);

    if (ioctl(sock, SIOCGIFFLAGS, &ifr) == -1) {
        perror("ioctl");
        exit(EXIT_FAILURE);
    }

    printf("Flags: %08x\n", ifr.ifr_flags);

    for (i = 0; i < sizeof(ifr.ifr_hwaddr); i++) {
        printf("%02x", (unsigned char) ifr.ifr_hwaddr.sa_data[i]);
        if (i < sizeof(ifr.ifr_hwaddr.sa_data) - 1) {
            printf(":");
        }
    }

    printf("\n");

    close(sock);

    return EXIT_SUCCESS;
}