//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <errno.h>

#define TIMEOUT 10 // timeout value
#define PACKET_SIZE 1024 // packet size

struct packet {
    int seq;
    struct timeval send_time;
    char data[PACKET_SIZE];
};

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <ip> <port>\n", argv[0]);
        return 1;
    }

    // create socket
    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        perror("socket");
        return 1;
    }

    // set socket non-blocking
    int flags = fcntl(sock, F_GETFL, 0);
    if (flags < 0) {
        perror("fcntl");
        return 1;
    }
    fcntl(sock, F_SETFL, flags | O_NONBLOCK);

    // set socket options
    int optval = 1;
    if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval)) < 0) {
        perror("setsockopt");
        return 1;
    }

    // bind to local address
    struct sockaddr_in local_addr = {0};
    local_addr.sin_family = AF_INET;
    local_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    local_addr.sin_port = htons(0);
    if (bind(sock, (struct sockaddr *)&local_addr, sizeof(local_addr)) < 0) {
        perror("bind");
        return 1;
    }

    // set remote address
    struct sockaddr_in remote_addr = {0};
    remote_addr.sin_family = AF_INET;
    remote_addr.sin_addr.s_addr = inet_addr(argv[1]);
    remote_addr.sin_port = htons(atoi(argv[2]));

    // initialize packet
    struct packet pkt = {0};
    pkt.seq = 1;
    gettimeofday(&pkt.send_time, NULL);

    // send packet
    if (sendto(sock, &pkt, sizeof(pkt), 0, (struct sockaddr *)&remote_addr, sizeof(remote_addr)) < 0) {
        perror("sendto");
        return 1;
    }

    // receive packet
    struct packet recv_pkt = {0};
    struct timeval start_time = {0}, end_time = {0};
    gettimeofday(&start_time, NULL);
    while (1) {
        // check timeout
        gettimeofday(&end_time, NULL);
        if (end_time.tv_sec - start_time.tv_sec > TIMEOUT) {
            printf("Connection timed out\n");
            return 1;
        }

        // receive packet
        fd_set rfds;
        FD_ZERO(&rfds);
        FD_SET(sock, &rfds);
        struct timeval timeout = {0};
        timeout.tv_sec = 1;
        timeout.tv_usec = 0;

        if (select(sock+1, &rfds, NULL, NULL, &timeout) <= 0) {
            continue;
        }

        if (recvfrom(sock, &recv_pkt, sizeof(recv_pkt), 0, NULL, NULL) < 0) {
            perror("recvfrom");
            return 1;
        }

        // check packet sequence number
        if (recv_pkt.seq == pkt.seq) {
            break;
        }
    }

    // calculate network quality of service
    struct timeval rtt = {0};
    timersub(&end_time, &start_time, &rtt);
    printf("RTT: %ld.%06lds\n", rtt.tv_sec, rtt.tv_usec);

    return 0;
}