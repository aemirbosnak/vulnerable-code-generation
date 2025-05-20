//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>

#define MAX_PACKET_SIZE 1024

struct ping_packet {
    char data[MAX_PACKET_SIZE];
    time_t timestamp;
};

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <ip address>\n", argv[0]);
        return EXIT_FAILURE;
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(argv[1]);
    addr.sin_port = htons(5555);

    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    struct ping_packet packet;
    memset(&packet, 0, sizeof(packet));
    packet.timestamp = time(NULL);

    int packet_size = sizeof(packet);
    int sent_bytes = sendto(sockfd, &packet, packet_size, 0, (struct sockaddr *)&addr, sizeof(addr));
    if (sent_bytes < 0) {
        perror("sendto");
        return EXIT_FAILURE;
    }

    struct timeval timeout;
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;

    fd_set readfds;
    FD_ZERO(&readfds);
    FD_SET(sockfd, &readfds);

    int select_result = select(sockfd + 1, &readfds, NULL, NULL, &timeout);
    if (select_result < 0) {
        perror("select");
        return EXIT_FAILURE;
    }

    if (FD_ISSET(sockfd, &readfds)) {
        recvfrom(sockfd, &packet, packet_size, 0, NULL, NULL);
    } else {
        printf("Request timed out.\n");
        return EXIT_FAILURE;
    }

    time_t received_timestamp = time(NULL);
    double rtt = difftime(received_timestamp, packet.timestamp);

    printf("Ping to %s: rtt = %f ms\n", argv[1], rtt * 1000);

    close(sockfd);
    return EXIT_SUCCESS;
}