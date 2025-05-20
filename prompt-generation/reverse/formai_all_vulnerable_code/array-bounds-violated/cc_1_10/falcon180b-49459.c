//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc < 4) {
        printf("Usage: %s <server> <port> <username> <password>\n", argv[0]);
        exit(1);
    }

    char *server = argv[1];
    char *port = argv[2];
    char *username = argv[3];
    char *password = argv[4];

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    struct addrinfo *server_info = NULL;
    struct addrinfo hints = {
       .ai_family = AF_INET,
       .ai_socktype = SOCK_STREAM,
       .ai_protocol = IPPROTO_TCP,
       .ai_flags = AI_NUMERICSERV
    };

    if (getaddrinfo(server, port, &hints, &server_info)!= 0) {
        printf("Error resolving server address\n");
        exit(1);
    }

    if (connect(sockfd, server_info->ai_addr, server_info->ai_addrlen) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    char *auth_str = NULL;
    asprintf(&auth_str, "LOGIN %s %s", username, password);

    send(sockfd, auth_str, strlen(auth_str), 0);

    char buffer[BUFFER_SIZE];
    while (1) {
        int bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            printf("Error receiving data\n");
            exit(1);
        }

        buffer[bytes_received] = '\0';
        printf("%s\n", buffer);
    }

    return 0;
}