//Falcon-180B DATASET v1.0 Category: Networking ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <sys/time.h>
#include <pthread.h>

#define BUFFER_SIZE 1024
#define SERVER_PORT 8080
#define SERVER_ADDR "127.0.0.1"

int main(int argc, char *argv[]) {
    int sockfd;
    struct addrinfo server_addr;
    struct addrinfo hints;
    char buffer[BUFFER_SIZE];
    int bytes_read;
    int bytes_sent;
    char *message = "Hello, World!\n";
    struct timeval timeout = { 5, 0 };

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    getaddrinfo(SERVER_ADDR, SERVER_PORT, &hints, &server_addr);

    sockfd = socket(server_addr.ai_family, server_addr.ai_socktype,
        server_addr.ai_protocol);

    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout,
        sizeof(timeout))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    if (connect(sockfd, server_addr.ai_addr, server_addr.ai_addrlen)!= 0) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    bytes_sent = send(sockfd, message, strlen(message), 0);

    if (bytes_sent < 0) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    while (1) {
        bytes_read = recv(sockfd, buffer, BUFFER_SIZE, 0);

        if (bytes_read <= 0) {
            break;
        }

        buffer[bytes_read] = '\0';
        printf("%s", buffer);
    }

    close(sockfd);

    return 0;
}