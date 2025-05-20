//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <net/if.h>
#include <netinet/if_ether.h>
#include <arpa/inet.h>

#define MAX_BPS 1000000000
#define MAX_PPS 1000000

struct qos_monitor {
    int sock;
    struct sockaddr_in addr;
    unsigned int bps;
    unsigned int pps;
};

int init_qos_monitor(struct qos_monitor *monitor) {
    monitor->sock = socket(AF_PACKET, SOCK_RAW, htons(ETH_P_ALL));
    if (monitor->sock < 0) {
        perror("socket");
        return -1;
    }

    memset(&monitor->addr, 0, sizeof(monitor->addr));
    monitor->addr.sin_family = AF_INET;
    monitor->addr.sin_addr.s_addr = htonl(INADDR_ANY);
    monitor->addr.sin_port = htons(0);

    if (bind(monitor->sock, (struct sockaddr *)&monitor->addr, sizeof(monitor->addr)) < 0) {
        perror("bind");
        return -1;
    }

    monitor->bps = 0;
    monitor->pps = 0;

    return 0;
}

void update_qos_monitor(struct qos_monitor *monitor) {
    unsigned char buf[4096];
    ssize_t nbytes;

    nbytes = recvfrom(monitor->sock, buf, sizeof(buf), 0, NULL, NULL);
    if (nbytes < 0) {
        perror("recvfrom");
        return;
    }

    monitor->bps += nbytes * 8;
    monitor->pps++;
}

void print_qos_monitor(struct qos_monitor *monitor) {
    printf("BPS: %u\n", monitor->bps);
    printf("PPS: %u\n", monitor->pps);
}

int main() {
    struct qos_monitor monitor;

    if (init_qos_monitor(&monitor) < 0) {
        return -1;
    }

    while (1) {
        update_qos_monitor(&monitor);
        print_qos_monitor(&monitor);
    }

    return 0;
}