//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_INTERFACES 10
#define MAX_ADDRESSES 10

struct interface {
    char name[IFNAMSIZ];
    struct sockaddr_in *addresses[MAX_ADDRESSES];
    int num_addresses;
};

struct interface *interfaces[MAX_INTERFACES];
int num_interfaces;

int main() {
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    struct ifconf ifconf;
    ifconf.ifc_len = sizeof(struct ifreq) * MAX_INTERFACES;
    ifconf.ifc_req = malloc(ifconf.ifc_len);
    if (ifconf.ifc_req == NULL) {
        perror("malloc");
        return EXIT_FAILURE;
    }

    if (ioctl(sockfd, SIOCGIFCONF, &ifconf) == -1) {
        perror("ioctl");
        return EXIT_FAILURE;
    }

    num_interfaces = ifconf.ifc_len / sizeof(struct ifreq);
    for (int i = 0; i < num_interfaces; i++) {
        struct ifreq *ifr = &ifconf.ifc_req[i];
        struct interface *interface = malloc(sizeof(struct interface));
        if (interface == NULL) {
            perror("malloc");
            return EXIT_FAILURE;
        }

        strcpy(interface->name, ifr->ifr_name);
        interface->num_addresses = 0;

        if (ioctl(sockfd, SIOCGIFADDR, ifr) == -1) {
            perror("ioctl");
            return EXIT_FAILURE;
        }

        interface->addresses[interface->num_addresses++] = (struct sockaddr_in *)&ifr->ifr_addr;

        if (ioctl(sockfd, SIOCGIFBRDADDR, ifr) == -1) {
            perror("ioctl");
            return EXIT_FAILURE;
        }

        if (ifr->ifr_broadaddr.sa_family == AF_INET) {
            interface->addresses[interface->num_addresses++] = (struct sockaddr_in *)&ifr->ifr_broadaddr;
        }

        if (ioctl(sockfd, SIOCGIFDSTADDR, ifr) == -1) {
            perror("ioctl");
            return EXIT_FAILURE;
        }

        if (ifr->ifr_dstaddr.sa_family == AF_INET) {
            interface->addresses[interface->num_addresses++] = (struct sockaddr_in *)&ifr->ifr_dstaddr;
        }

        interfaces[i] = interface;
    }

    for (int i = 0; i < num_interfaces; i++) {
        struct interface *interface = interfaces[i];

        printf("Interface: %s\n", interface->name);
        for (int j = 0; j < interface->num_addresses; j++) {
            char address[INET_ADDRSTRLEN];
            inet_ntop(AF_INET, &interface->addresses[j]->sin_addr, address, INET_ADDRSTRLEN);
            printf(" - %s\n", address);
        }
    }

    free(ifconf.ifc_req);
    close(sockfd);

    return EXIT_SUCCESS;
}