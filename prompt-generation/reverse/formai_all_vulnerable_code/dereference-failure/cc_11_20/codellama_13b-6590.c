//Code Llama-13B DATASET v1.0 Category: TCP/IP Programming ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char **argv) {
    int sockfd, n;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);

    if (argc != 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Failed to create socket");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[1]));
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("Failed to bind socket");
        exit(1);
    }

    if (listen(sockfd, 10) < 0) {
        perror("Failed to listen on socket");
        exit(1);
    }

    while (1) {
        int client_fd = accept(sockfd, (struct sockaddr *) &client_addr, &client_len);
        if (client_fd < 0) {
            perror("Failed to accept connection");
            continue;
        }

        while (1) {
            memset(buffer, 0, BUFFER_SIZE);
            n = recv(client_fd, buffer, BUFFER_SIZE, 0);
            if (n < 0) {
                perror("Failed to receive message");
                break;
            } else if (n == 0) {
                break;
            }

            printf("Received message: %s\n", buffer);

            n = send(client_fd, buffer, n, 0);
            if (n < 0) {
                perror("Failed to send message");
                break;
            }
        }

        close(client_fd);
    }

    close(sockfd);

    return 0;
}