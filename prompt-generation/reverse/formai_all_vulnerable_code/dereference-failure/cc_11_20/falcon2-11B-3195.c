//Falcon2-11B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in serveraddr;
    int optval = 1;

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <server_ip> <port>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    memset(&serveraddr, 0, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &serveraddr.sin_addr) <= 0) {
        fprintf(stderr, "inet_pton: %s\n", strerror(errno));
        exit(1);
    }

    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &optval, sizeof(optval))) {
        perror("setsockopt");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0) {
        perror("connect");
        exit(1);
    }

    printf("Connected to %s:%d\n", argv[1], atoi(argv[2]));

    char buffer[BUFFER_SIZE];
    int total_packets = 0, total_bytes = 0;
    int qos_drops = 0, qos_bytes = 0;

    while (1) {
        n = read(sockfd, buffer, BUFFER_SIZE);
        if (n <= 0) {
            perror("read");
            exit(1);
        }

        total_packets += n;
        total_bytes += n;

        int qos_drops_total = 0, qos_bytes_total = 0;
        int i;
        for (i = 0; i < n; i++) {
            if (buffer[i] == '\0') {
                break;
            }

            if (buffer[i] == '\x00') {
                qos_drops_total++;
                qos_bytes_total += i + 1;
                break;
            }

            qos_drops_total = 0;
            qos_bytes_total = 0;
        }

        qos_drops += qos_drops_total;
        qos_bytes += qos_bytes_total;

        printf("%d packets received, %d bytes total\n", total_packets, total_bytes);
        printf("QoS drops: %d, %d bytes\n", qos_drops, qos_bytes);

        total_packets = 0;
        total_bytes = 0;
        qos_drops = 0;
        qos_bytes = 0;

        sleep(10);
    }

    return 0;
}