//Code Llama-13B DATASET v1.0 Category: Network Ping Test ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_PACKET_SIZE 8192

int main(int argc, char *argv[]) {
    char *host = argv[1];
    int sockfd, n, len;
    char recv_buf[MAX_PACKET_SIZE];
    struct sockaddr_in server;
    struct hostent *host_info;
    struct timeval timeout;

    if (argc != 2) {
        printf("Usage: %s <host>\n", argv[0]);
        exit(1);
    }

    host_info = gethostbyname(host);
    if (host_info == NULL) {
        printf("Error: Host not found\n");
        exit(2);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error: Could not create socket\n");
        exit(3);
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(80);
    server.sin_addr = *((struct in_addr *)host_info->h_addr);
    len = sizeof(server);

    if (connect(sockfd, (struct sockaddr *)&server, len) < 0) {
        printf("Error: Could not connect to host\n");
        exit(4);
    }

    timeout.tv_sec = 1;
    timeout.tv_usec = 0;

    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout)) < 0) {
        printf("Error: Could not set timeout\n");
        exit(5);
    }

    n = recv(sockfd, recv_buf, MAX_PACKET_SIZE, 0);
    if (n < 0) {
        printf("Error: Could not receive data\n");
        exit(6);
    }

    printf("Received %d bytes of data\n", n);

    close(sockfd);

    return 0;
}