//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int ping(const char *hostname, int port) {
    int sockfd, ret;
    struct sockaddr_in server_addr;
    char send_buffer[BUFFER_SIZE];
    char recv_buffer[BUFFER_SIZE];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        return -1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    ret = inet_pton(AF_INET, hostname, &server_addr.sin_addr);
    if (ret <= 0) {
        printf("Error resolving hostname\n");
        close(sockfd);
        return -1;
    }

    ret = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (ret == -1) {
        printf("Error connecting to host\n");
        close(sockfd);
        return -1;
    }

    send(sockfd, "PING", strlen("PING"), 0);
    ret = recv(sockfd, recv_buffer, BUFFER_SIZE, 0);
    if (ret <= 0) {
        printf("Error receiving response\n");
        close(sockfd);
        return -1;
    }

    close(sockfd);

    if (strncmp(recv_buffer, "PONG", strlen("PONG")) == 0) {
        printf("Host is alive\n");
        return 0;
    } else {
        printf("Host is not responding\n");
        return -1;
    }
}

int main() {
    char hostname[256];
    int port;

    printf("Enter hostname or IP address: ");
    scanf("%s", hostname);

    printf("Enter port number: ");
    scanf("%d", &port);

    int result = ping(hostname, port);

    if (result == 0) {
        printf("Ping successful\n");
    } else {
        printf("Ping failed\n");
    }

    return 0;
}