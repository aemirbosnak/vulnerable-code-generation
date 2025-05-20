//GEMINI-pro DATASET v1.0 Category: Subnet Calculator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <ifaddrs.h>

#ifdef WIN32
#define IFE_IADDR rtea_ifa.irtea_addr
#else
#define IFE_IADDR ifa_addr
#endif

struct subnet {
    struct in_addr network;
    struct in_addr broadcast;
    struct in_addr subnet_mask;
    struct in_addr host_min;
    struct in_addr host_max;
    int prefix_length;
};

struct subnet calculate_subnet(struct in_addr ip, struct in_addr mask) {
    struct subnet subnet;
    subnet.network.s_addr = ip.s_addr & mask.s_addr;
    subnet.broadcast.s_addr = ip.s_addr | ~mask.s_addr;
    subnet.subnet_mask.s_addr = mask.s_addr;
    subnet.host_min.s_addr = subnet.network.s_addr + 1;
    subnet.host_max.s_addr = subnet.broadcast.s_addr - 1;
    subnet.prefix_length = 0;
    for (int i = 0; i < 32; i++) {
        if (mask.s_addr & (1 << i)) {
            subnet.prefix_length++;
        }
    }
    return subnet;
}

void print_subnet(struct subnet subnet) {
    printf("Network: %s\n", inet_ntoa(subnet.network));
    printf("Broadcast: %s\n", inet_ntoa(subnet.broadcast));
    printf("Subnet Mask: %s\n", inet_ntoa(subnet.subnet_mask));
    printf("Host Minimum: %s\n", inet_ntoa(subnet.host_min));
    printf("Host Maximum: %s\n", inet_ntoa(subnet.host_max));
    printf("Prefix Length: %d\n", subnet.prefix_length);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <ip address> <subnet mask>\n", argv[0]);
        return EXIT_FAILURE;
    }

    struct in_addr ip, mask;
    if (!inet_aton(argv[1], &ip)) {
        fprintf(stderr, "Invalid IP address: %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    if (!inet_aton(argv[2], &mask)) {
        fprintf(stderr, "Invalid subnet mask: %s\n", argv[2]);
        return EXIT_FAILURE;
    }

    struct subnet subnet = calculate_subnet(ip, mask);
    print_subnet(subnet);

    return EXIT_SUCCESS;
}