//Code Llama-13B DATASET v1.0 Category: Network Topology Mapper ; Style: expert-level
// C Network Topology Mapper example program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <ifaddrs.h>
#include <net/if.h>
#include <netinet/in.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    // Declare variables
    struct ifaddrs *ifaddr, *ifa;
    int family, s;
    char host[NI_MAXHOST];

    // Get all network interfaces
    if (getifaddrs(&ifaddr) == -1) {
        perror("getifaddrs");
        exit(EXIT_FAILURE);
    }

    // Iterate through all network interfaces
    for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) {
        // Check if interface is up and running
        if (ifa->ifa_flags & IFF_UP && ifa->ifa_flags & IFF_RUNNING) {
            // Get interface family
            family = ifa->ifa_addr->sa_family;
            // Check if interface is IPv4 or IPv6
            if (family == AF_INET || family == AF_INET6) {
                // Get interface name
                printf("%s: ", ifa->ifa_name);
                // Get interface IP address
                if (getnameinfo(ifa->ifa_addr, sizeof(struct sockaddr_storage), host, NI_MAXHOST, NULL, 0, NI_NUMERICHOST) == 0) {
                    printf("%s\n", host);
                }
                // Get interface subnet mask
                if (family == AF_INET) {
                    struct sockaddr_in *addr = (struct sockaddr_in *)ifa->ifa_netmask;
                    printf("  Subnet mask: %s\n", inet_ntoa(addr->sin_addr));
                } else if (family == AF_INET6) {
                    struct sockaddr_in6 *addr = (struct sockaddr_in6 *)ifa->ifa_netmask;
                    printf("  Subnet mask: %s\n", inet_ntop(AF_INET6, &addr->sin6_addr, host, NI_MAXHOST));
                }
                // Get interface broadcast address
                if (family == AF_INET) {
                    struct sockaddr_in *addr = (struct sockaddr_in *)ifa->ifa_broadaddr;
                    printf("  Broadcast address: %s\n", inet_ntoa(addr->sin_addr));
                } else if (family == AF_INET6) {
                    struct sockaddr_in6 *addr = (struct sockaddr_in6 *)ifa->ifa_broadaddr;
                    printf("  Broadcast address: %s\n", inet_ntop(AF_INET6, &addr->sin6_addr, host, NI_MAXHOST));
                }
                // Get interface destination address
                if (family == AF_INET) {
                    struct sockaddr_in *addr = (struct sockaddr_in *)ifa->ifa_dstaddr;
                    printf("  Destination address: %s\n", inet_ntoa(addr->sin_addr));
                } else if (family == AF_INET6) {
                    struct sockaddr_in6 *addr = (struct sockaddr_in6 *)ifa->ifa_dstaddr;
                    printf("  Destination address: %s\n", inet_ntop(AF_INET6, &addr->sin6_addr, host, NI_MAXHOST));
                }
            }
        }
    }

    freeifaddrs(ifaddr);

    return 0;
}