//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {

    if (argc != 4) {
        printf("Usage: %s <server_address> <username> <password>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *server_address = argv[1];
    char *username = argv[2];
    char *password = argv[3];
    char buffer[BUFFER_SIZE];

    // Connect to POP3 server
    struct addrinfo hints, *res;
    int status;
    int sockfd;
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    if ((status = getaddrinfo(server_address, "pop3", &hints, &res)) != 0) {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
        exit(EXIT_FAILURE);
    }
    sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (connect(sockfd, res->ai_addr, res->ai_addrlen) < 0) {
        perror("connect");
        exit(EXIT_FAILURE);
    }
    freeaddrinfo(res);

    // Receive and print welcome message from server
    ssize_t recvbytes = recv(sockfd, buffer, BUFFER_SIZE-1, 0);
    if (recvbytes < 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    buffer[recvbytes] = '\0';
    printf("Server: %s\n", buffer);

    // Send username to server
    snprintf(buffer, BUFFER_SIZE, "USER %s\r\n", username);
    ssize_t sentbytes = send(sockfd, buffer, strlen(buffer), 0);
    if (sentbytes < 0) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Receive and print response from server
    recvbytes = recv(sockfd, buffer, BUFFER_SIZE-1, 0);
    if (recvbytes < 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    buffer[recvbytes] = '\0';
    printf("Server: %s\n", buffer);

    // Send password to server
    snprintf(buffer, BUFFER_SIZE, "PASS %s\r\n", password);
    sentbytes = send(sockfd, buffer, strlen(buffer), 0);
    if (sentbytes < 0) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Receive and print response from server
    recvbytes = recv(sockfd, buffer, BUFFER_SIZE-1, 0);
    if (recvbytes < 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    buffer[recvbytes] = '\0';
    printf("Server: %s\n", buffer);

    // Send LIST command to server
    snprintf(buffer, BUFFER_SIZE, "LIST\r\n");
    sentbytes = send(sockfd, buffer, strlen(buffer), 0);
    if (sentbytes < 0) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Receive and print response from server
    recvbytes = recv(sockfd, buffer, BUFFER_SIZE-1, 0);
    if (recvbytes < 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    buffer[recvbytes] = '\0';
    printf("Server: %s\n", buffer);

    // Send QUIT command to server
    snprintf(buffer, BUFFER_SIZE, "QUIT\r\n");
    sentbytes = send(sockfd, buffer, strlen(buffer), 0);
    if (sentbytes < 0) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Receive and print response from server
    recvbytes = recv(sockfd, buffer, BUFFER_SIZE-1, 0);
    if (recvbytes < 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    buffer[recvbytes] = '\0';
    printf("Server: %s\n", buffer);

    close(sockfd);

    return 0;
}