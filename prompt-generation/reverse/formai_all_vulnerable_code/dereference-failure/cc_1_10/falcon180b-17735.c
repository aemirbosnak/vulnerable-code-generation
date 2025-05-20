//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_HOSTNAME_LENGTH 256
#define MAX_DATA_SIZE 1024

void print_error(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        return 1;
    }

    char hostname[MAX_HOSTNAME_LENGTH];
    strncpy(hostname, argv[1], MAX_HOSTNAME_LENGTH);
    hostname[MAX_HOSTNAME_LENGTH - 1] = '\0';

    int port = atoi(argv[2]);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        print_error("socket");
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);

    if (inet_pton(AF_INET, hostname, &server_addr.sin_addr) <= 0) {
        print_error("inet_pton");
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        print_error("connect");
    }

    char send_data[MAX_DATA_SIZE];
    strncpy(send_data, "PING", MAX_DATA_SIZE);
    send_data[MAX_DATA_SIZE - 1] = '\0';

    if (send(sockfd, send_data, strlen(send_data), 0) == -1) {
        print_error("send");
    }

    char recv_data[MAX_DATA_SIZE];
    memset(recv_data, 0, sizeof(recv_data));

    if (recv(sockfd, recv_data, sizeof(recv_data), 0) == -1) {
        print_error("recv");
    }

    printf("PING %s:%d - %s\n", hostname, port, recv_data);

    close(sockfd);
    return 0;
}