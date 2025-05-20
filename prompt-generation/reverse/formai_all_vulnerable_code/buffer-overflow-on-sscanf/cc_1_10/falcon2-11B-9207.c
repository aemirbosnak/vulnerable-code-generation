//Falcon2-11B DATASET v1.0 Category: Subnet Calculator ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HOSTS 255

struct subnet {
    unsigned short netmask;
    unsigned short network;
    unsigned short broadcast;
    unsigned short host_count;
};

void usage(void)
{
    printf("Usage: subnetcalc [network] [netmask] [host_count]\n");
    printf("where:\n");
    printf("  network = IP address of network\n");
    printf("  netmask = IP address of netmask\n");
    printf("  host_count = number of hosts on the subnet\n");
}

struct subnet parse_args(int argc, char *argv[])
{
    if (argc!= 4) {
        usage();
        exit(1);
    }

    struct subnet subnet;

    if (sscanf(argv[1], "%hu", &subnet.network)!= 1) {
        usage();
        exit(1);
    }
    if (sscanf(argv[2], "%hu", &subnet.netmask)!= 1) {
        usage();
        exit(1);
    }
    if (sscanf(argv[3], "%hu", &subnet.host_count)!= 1) {
        usage();
        exit(1);
    }

    return subnet;
}

void print_subnet(struct subnet subnet)
{
    printf("Network address: %u\n", subnet.network);
    printf("Netmask: %u\n", subnet.netmask);
    printf("Broadcast address: %u\n", subnet.broadcast);
    printf("Host count: %u\n", subnet.host_count);
}

int main(int argc, char *argv[])
{
    struct subnet subnet = parse_args(argc, argv);

    unsigned short netmask = subnet.netmask;
    unsigned short network = subnet.network;
    unsigned short broadcast = network | ~netmask;

    printf("Netmask: %u\n", netmask);
    printf("Network address: %u\n", network);
    printf("Broadcast address: %u\n", broadcast);
    printf("Host count: %u\n", subnet.host_count);

    return 0;
}