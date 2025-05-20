//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char **argv) {

    if (argc!= 3) {
        printf("Usage: %s <IP Address> <Port Number>\n", argv[0]);
        return 1;
    }

    char *ip = argv[1];
    int port = atoi(argv[2]);

    struct addrinfo hints, *server;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(ip, NULL, &hints, &server)!= 0) {
        printf("Error resolving hostname\n");
        return 1;
    }

    int sockfd = socket(server->ai_family, server->ai_socktype, server->ai_protocol);

    if (sockfd == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    if (connect(sockfd, server->ai_addr, server->ai_addrlen)!= 0) {
        printf("Error connecting to server\n");
        close(sockfd);
        return 1;
    }

    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);

    send(sockfd, "PING", strlen("PING"), 0);

    int bytes_received = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);

    if (bytes_received <= 0) {
        printf("Error receiving response from server\n");
        close(sockfd);
        return 1;
    }

    buffer[bytes_received] = '\0';

    printf("Response from server: %s\n", buffer);

    close(sockfd);

    return 0;
}