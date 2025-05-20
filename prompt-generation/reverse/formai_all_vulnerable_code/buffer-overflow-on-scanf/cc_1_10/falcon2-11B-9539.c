//Falcon2-11B DATASET v1.0 Category: Subnet Calculator ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NETWORK 8
#define MAX_HOST 255

void print_subnet(unsigned char* subnet) {
    printf("Subnet: %d.%d.%d.%d/%d\n",
            subnet[0], subnet[1], subnet[2], subnet[3], subnet[4]);
}

void print_host(unsigned char* subnet, unsigned char* host) {
    printf("Host: %d.%d.%d.%d\n",
            host[0], host[1], host[2], host[3]);
}

void print_subnet_range(unsigned char* subnet, int* start, int* end) {
    printf("Subnet range: %d.%d.%d.%d - %d.%d.%d.%d\n",
            subnet[0], subnet[1], subnet[2], subnet[3],
            *start, subnet[4], *end, subnet[4]);
}

int main() {
    unsigned char subnet[5];
    unsigned char host[4];

    printf("Enter the subnet mask (binary format): ");
    scanf("%d", &subnet[4]);
    for (int i = 0; i < 4; i++) {
        scanf("%d", &subnet[i]);
    }

    printf("Enter the host address (binary format): ");
    for (int i = 0; i < 4; i++) {
        scanf("%d", &host[i]);
    }

    printf("Subnet: %d.%d.%d.%d/%d\n",
            subnet[0], subnet[1], subnet[2], subnet[3], subnet[4]);
    printf("Host: %d.%d.%d.%d\n",
            host[0], host[1], host[2], host[3]);

    int start = 1;
    int end = 0;
    print_subnet_range(subnet, &start, &end);
    printf("Total number of hosts in the subnet: %d\n", (end - start + 1));

    return 0;
}