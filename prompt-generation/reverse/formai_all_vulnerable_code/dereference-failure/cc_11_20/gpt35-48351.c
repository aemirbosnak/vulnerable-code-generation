//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <ifaddrs.h>
#include <unistd.h>
#include <errno.h>

#define MAX_INTERFACES 16
#define MAX_HOSTS 256

struct host {
    char *ip;
    char *name;
};

int main(int argc, char *argv[]) {
    // retrieve list of network interfaces
    struct ifaddrs *ifap, *ifa;
    if (getifaddrs(&ifap) == -1) {
        perror("getifaddrs");
        exit(1);
    }

    // initialize list of hosts
    struct host hosts[MAX_HOSTS];
    int num_hosts = 0;

    // iterate over network interfaces
    for (ifa = ifap; ifa != NULL && num_hosts < MAX_HOSTS; ifa = ifa->ifa_next) {
        if (ifa->ifa_addr == NULL) {
            continue;
        }

        int family = ifa->ifa_addr->sa_family;

        // only consider IPv4 or IPv6
        if (family != AF_INET && family != AF_INET6) {
            continue;
        }

        // retrieve IP address as string
        char ip[INET6_ADDRSTRLEN];
        void *addr;
        if (family == AF_INET) {
            addr = &((struct sockaddr_in *)ifa->ifa_addr)->sin_addr;
        } else {
            addr = &((struct sockaddr_in6 *)ifa->ifa_addr)->sin6_addr;
        }
        inet_ntop(family, addr, ip, sizeof(ip));

        // retrieve hostname associated with IP address
        struct addrinfo hints, *result;
        memset(&hints, 0, sizeof(struct addrinfo));
        hints.ai_family = family;
        hints.ai_socktype = SOCK_STREAM;
        hints.ai_flags = AI_CANONNAME;
        int status = getaddrinfo(ip, NULL, &hints, &result);
        if (status != 0) {
            fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
            continue;
        }
        char *name = result->ai_canonname;

        // add host to list
        hosts[num_hosts].ip = strdup(ip);
        hosts[num_hosts].name = name ? strdup(name) : NULL;
        num_hosts++;

        // free memory allocated by getaddrinfo
        freeaddrinfo(result);
    }

    // print list of hosts
    printf("%-20s %s\n", "IP Address", "Hostname");
    for (int i = 0; i < num_hosts; i++) {
        printf("%-20s %s\n", hosts[i].ip, hosts[i].name ? hosts[i].name : "");
        free(hosts[i].ip);
        free(hosts[i].name);
    }

    // free memory allocated by getifaddrs
    freeifaddrs(ifap);

    return 0;
}