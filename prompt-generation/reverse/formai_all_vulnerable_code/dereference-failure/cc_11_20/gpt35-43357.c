//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <net/if.h>
#include <netdb.h>
#include <errno.h>
#include <ifaddrs.h>

#define MAX_INTERFACES 64

int main(int argc, char *argv[])
{
    struct ifaddrs *ifaddr, *ifa;
    int family, s;
    int n = 0;
    char host[NI_MAXHOST];
    int if_flags, ifa_flags;
    int is_up, is_running;
    int is_loopback, is_multicast, is_p2p;

    if (getifaddrs(&ifaddr) == -1) {
        perror("getifaddrs");
        exit(EXIT_FAILURE);
    }

    for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) {
        if (ifa->ifa_addr == NULL)
            continue;

        family = ifa->ifa_addr->sa_family;

        if (family != AF_INET && family != AF_INET6)
            continue;

        s = socket(family, SOCK_DGRAM, 0);
        if (s == -1) {
            perror("socket");
            continue;
        }

        if_flags = ifa->ifa_flags;
        is_up = (if_flags & IFF_UP) ? 1 : 0;
        is_running = (if_flags & IFF_RUNNING) ? 1 : 0;
        is_loopback = (if_flags & IFF_LOOPBACK) ? 1 : 0;
        is_multicast = (if_flags & IFF_MULTICAST) ? 1 : 0;
#ifdef IFF_POINTOPOINT
        is_p2p = (if_flags & IFF_POINTOPOINT) ? 1 : 0;
#else
        is_p2p = 0;
#endif

        ifa_flags = ifa->ifa_flags;
        if (!(ifa_flags & IFF_UP) || !(ifa_flags & IFF_RUNNING))
            continue;

        if (family == AF_INET) {
            struct sockaddr_in *sin = (struct sockaddr_in *)ifa->ifa_addr;
            inet_ntop(AF_INET, &sin->sin_addr, host, sizeof(host));
            printf("%d.%d.%d.%d\n", host[0], host[1], host[2], host[3]);
        } else {
            struct sockaddr_in6 *sin6 = (struct sockaddr_in6 *)ifa->ifa_addr;
            inet_ntop(AF_INET6, &sin6->sin6_addr, host, sizeof(host));
            printf("%s\n", host);
        }
        
        if (s)
            close(s);
        
        ++n;
        if (n >= MAX_INTERFACES)
            break;
    }

    freeifaddrs(ifaddr);

    return 0;
}