//GEMINI-pro DATASET v1.0 Category: Wi-Fi Signal Strength Analyzer ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <ifaddrs.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <arpa/inet.h>
#include <net/if.h>
#include <signal.h>

#ifndef EXIT_FAILURE
#define EXIT_FAILURE -1
#endif

int main(int argc, char *argv[]) {
    struct ifaddrs *ifaddr;
    struct ifreq ifr;
    int sockfd;
    char *dev = "wlan0";

    if (argc > 1) {
        dev = argv[1];
    }

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    memset(&ifr, 0, sizeof(ifr));
    strncpy(ifr.ifr_name, dev, IFNAMSIZ);

    if (ioctl(sockfd, SIOCGIFADDR, &ifr) == -1) {
        perror("ioctl");
        close(sockfd);
        return EXIT_FAILURE;
    }

    printf("Interface: %s\n", ifr.ifr_name);

    getifaddrs(&ifaddr);

    struct ifaddrs *ifa = ifaddr;
    while (ifa) {
        if (ifa->ifa_addr && ifa->ifa_addr->sa_family == AF_INET) {
            printf("Address: %s\n", inet_ntoa(((struct sockaddr_in *)ifa->ifa_addr)->sin_addr));
        }

        if (ifa->ifa_flags & IFF_RUNNING) {
            printf("Interface is running\n");
        }

        if (ifa->ifa_flags & IFF_UP) {
            printf("Interface is up\n");
        }

        if (ifa->ifa_flags & IFF_BROADCAST) {
            printf("Interface is capable of broadcasting\n");
        }

        if (ifa->ifa_flags & IFF_MULTICAST) {
            printf("Interface is capable of multicasting\n");
        }

        if (ifa->ifa_flags & IFF_LOOPBACK) {
            printf("Interface is a loopback interface\n");
        }

        if (ifa->ifa_flags & IFF_POINTOPOINT) {
            printf("Interface is a point-to-point interface\n");
        }

        if (ifa->ifa_flags & IFF_NOARP) {
            printf("Interface does not use Address Resolution Protocol\n");
        }

        if (ifa->ifa_flags & IFF_PROMISC) {
            printf("Interface is in promiscuous mode\n");
        }

        if (ifa->ifa_flags & IFF_ALLMULTI) {
            printf("Interface is receiving all multicasts\n");
        }

        ifa = ifa->ifa_next;
    }

    freeifaddrs(ifaddr);

    close(sockfd);

    return EXIT_SUCCESS;
}