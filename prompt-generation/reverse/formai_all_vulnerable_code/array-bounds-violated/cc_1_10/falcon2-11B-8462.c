//Falcon2-11B DATASET v1.0 Category: Chat server ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define MAX_MESSAGE_LEN 1024
#define MAX_CONNECTIONS 10

int main(int argc, char *argv[]) {
    int server_socket, connfd, len;
    struct sockaddr_in server_addr, client_addr;
    char buffer[MAX_MESSAGE_LEN], message[MAX_MESSAGE_LEN];

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s port\n", argv[0]);
        exit(1);
    }

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("socket");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(atoi(argv[1]));

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        exit(1);
    }

    if (listen(server_socket, MAX_CONNECTIONS) < 0) {
        perror("listen");
        exit(1);
    }

    while (1) {
        connfd = accept(server_socket, (struct sockaddr *)&client_addr, (socklen_t*)&len);
        if (connfd < 0) {
            perror("accept");
            exit(1);
        }

        printf("New connection from %s\n", inet_ntoa(client_addr.sin_addr));

        while (1) {
            len = recv(connfd, buffer, MAX_MESSAGE_LEN - 1, 0);
            if (len <= 0) {
                break;
            }

            buffer[len] = '\0';
            printf("Received: %s\n", buffer);

            send(connfd, message, strlen(message), 0);
            printf("Sent: %s\n", message);
        }

        close(connfd);
    }

    close(server_socket);
    return 0;
}