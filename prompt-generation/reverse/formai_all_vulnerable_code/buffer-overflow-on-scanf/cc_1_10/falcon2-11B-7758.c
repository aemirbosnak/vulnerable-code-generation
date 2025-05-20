//Falcon2-11B DATASET v1.0 Category: Network Packet Monitoring ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/ioctl.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <net/ethernet.h>
#include <net/if.h>

#define MAX_PACKETS 10

void print_packet(char* packet) {
    int i;
    for (i = 0; i < strlen(packet); i++) {
        if (packet[i] == '\n') {
            printf("Packet: %s\n", packet);
            return;
        }
        printf("%c", packet[i]);
    }
    printf("\n");
}

int main() {
    int sockfd, n, ret;
    struct sockaddr_in addr;
    struct ifreq ifr;
    char packet[MAX_PACKETS][MAX_PACKETS];

    printf("Enter the interface name: ");
    scanf("%s", &ifr.ifr_name);

    ret = ioctl(sockfd, SIOCGIFINDEX, &ifr);
    if (ret < 0) {
        printf("Unable to get interface index.\n");
        exit(1);
    }

    printf("Interface index: %d\n", ifr.ifr_ifindex);

    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_RAW);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(0);

    ret = bind(sockfd, (struct sockaddr *)&addr, sizeof(addr));
    if (ret < 0) {
        perror("bind");
        exit(1);
    }

    printf("Listening on interface %s...\n", ifr.ifr_name);

    while (1) {
        n = recvfrom(sockfd, packet[0], MAX_PACKETS - 1, 0, NULL, NULL);
        if (n <= 0) {
            perror("recvfrom");
            exit(1);
        }

        for (int i = 0; i < MAX_PACKETS; i++) {
            printf("%s", packet[i]);
            if (packet[i][0] == '\0') {
                break;
            }
        }
        printf("\n");

        for (int i = 0; i < n; i++) {
            packet[i + 1][i] = '\0';
            print_packet(packet[i + 1]);
        }
    }

    return 0;
}