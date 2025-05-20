//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_LINE 1024
#define BACKLOG 10

int main(int argc, char **argv) {
    int listen_socket, client_socket, sockopt;
    struct sockaddr_in server_addr, client_addr;
    char buffer[MAX_LINE];

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <port> <hostname>\n", argv[0]);
        exit(1);
    }

    listen_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_socket == -1) {
        perror("socket");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[1]));
    inet_pton(AF_INET, argv[2], &server_addr.sin_addr);

    if (bind(listen_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(1);
    }

    if (listen(listen_socket, BACKLOG) == -1) {
        perror("listen");
        exit(1);
    }

    sockopt = 1;
    if (setsockopt(listen_socket, SOL_SOCKET, SO_REUSEADDR, &sockopt, sizeof(sockopt)) == -1) {
        perror("setsockopt");
        exit(1);
    }

    while (1) {
        socklen_t addr_len;
        client_socket = accept(listen_socket, (struct sockaddr *)&client_addr, &addr_len);
        if (client_socket == -1) {
            perror("accept");
            continue;
        }

        printf("Connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while (1) {
            memset(buffer, 0, MAX_LINE);
            ssize_t bytes_received = recv(client_socket, buffer, MAX_LINE, 0);
            if (bytes_received <= 0) {
                if (bytes_received == 0) {
                    printf("Client disconnected\n");
                } else {
                    perror("recv");
                }

                close(client_socket);
                break;
            }

            ssize_t bytes_sent = send(client_socket, buffer, bytes_received, 0);
            if (bytes_sent!= bytes_received) {
                perror("send");
                close(client_socket);
                break;
            }
        }
    }

    close(listen_socket);
    return 0;
}