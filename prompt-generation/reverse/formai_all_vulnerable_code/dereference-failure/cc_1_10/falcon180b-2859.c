//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_LINE 1024
#define BACKLOG 10

int main(int argc, char *argv[]) {
    int listen_fd, client_fd, sock;
    int port = 8080;
    struct sockaddr_in server_addr, client_addr;
    char buffer[MAX_LINE];

    if (argc > 1) {
        port = atoi(argv[1]);
    }

    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd == -1) {
        perror("socket");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(port);

    if (bind(listen_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(1);
    }

    if (listen(listen_fd, BACKLOG) == -1) {
        perror("listen");
        exit(1);
    }

    printf("HTTP proxy started on port %d\n", port);

    while (1) {
        sock = accept(listen_fd, (struct sockaddr *) &client_addr, \
                      sizeof(client_addr));
        if (sock == -1) {
            perror("accept");
            exit(1);
        }

        printf("Connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), \
               ntohs(client_addr.sin_port));

        while (1) {
            memset(buffer, 0, MAX_LINE);
            int bytes_received = recv(sock, buffer, MAX_LINE, 0);
            if (bytes_received <= 0) {
                break;
            }
            printf("Received: %s", buffer);

            int bytes_sent = send(sock, buffer, strlen(buffer), 0);
            if (bytes_sent <= 0) {
                break;
            }
        }

        close(sock);
    }

    close(listen_fd);
    return 0;
}