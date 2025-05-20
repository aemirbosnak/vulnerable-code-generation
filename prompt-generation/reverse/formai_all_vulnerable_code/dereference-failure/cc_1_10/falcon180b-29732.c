//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <netdb.h>

#define BUFSIZE 1024
#define SERVER_PORT 80
#define SERVER_ADDR "www.example.com"

int main() {
    int sockfd;
    struct addrinfo server_addr;
    char buffer[BUFSIZE];
    int bytes_received;
    int total_bytes_received = 0;
    int qos_score = 0;
    int qos_threshold = 10;

    if (getaddrinfo(SERVER_ADDR, SERVER_PORT, &server_addr, NULL)!= 0) {
        fprintf(stderr, "getaddrinfo failed: %s\n", gai_strerror(errno));
        exit(1);
    }

    sockfd = socket(server_addr.ai_family, server_addr.ai_socktype, server_addr.ai_protocol);

    if (sockfd == -1) {
        fprintf(stderr, "socket failed: %s\n", strerror(errno));
        exit(2);
    }

    printf("Starting QoS monitor...\n");

    while (1) {
        bytes_received = recv(sockfd, buffer, BUFSIZE, 0);

        if (bytes_received == -1) {
            fprintf(stderr, "recv failed: %s\n", strerror(errno));
            exit(3);
        }

        total_bytes_received += bytes_received;

        if (total_bytes_received >= qos_threshold) {
            qos_score = 100;
        } else {
            qos_score = ((float) total_bytes_received / qos_threshold) * 100;
        }

        printf("QoS score: %d%%\n", qos_score);

        usleep(100000);
    }

    close(sockfd);
    return 0;
}