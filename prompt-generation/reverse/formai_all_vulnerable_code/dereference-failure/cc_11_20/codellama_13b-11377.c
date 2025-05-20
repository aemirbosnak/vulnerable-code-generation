//Code Llama-13B DATASET v1.0 Category: Simple HTTP Proxy ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_BUF 1024

int main(int argc, char *argv[]) {
    int sock_fd, client_fd, proxy_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    char buffer[MAX_BUF];

    if (argc != 2) {
        printf("Usage: %s <port>\n", argv[0]);
        return 1;
    }

    sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd == -1) {
        perror("socket");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[1]));
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        return 1;
    }

    if (listen(sock_fd, 5) == -1) {
        perror("listen");
        return 1;
    }

    printf("Listening on port %d\n", atoi(argv[1]));

    while (1) {
        client_fd = accept(sock_fd, (struct sockaddr *)&client_addr, &client_len);
        if (client_fd == -1) {
            perror("accept");
            return 1;
        }

        printf("Client connected from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        proxy_fd = socket(AF_INET, SOCK_STREAM, 0);
        if (proxy_fd == -1) {
            perror("socket");
            return 1;
        }

        if (connect(proxy_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
            perror("connect");
            return 1;
        }

        printf("Connected to server\n");

        while (1) {
            int n = recv(client_fd, buffer, MAX_BUF, 0);
            if (n == -1) {
                perror("recv");
                return 1;
            }

            if (n == 0) {
                printf("Client disconnected\n");
                break;
            }

            int m = send(proxy_fd, buffer, n, 0);
            if (m == -1) {
                perror("send");
                return 1;
            }
        }

        close(client_fd);
        close(proxy_fd);
    }

    close(sock_fd);

    return 0;
}