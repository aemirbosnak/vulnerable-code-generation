//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <port> <host>\n", argv[0]);
        exit(1);
    }

    int port = atoi(argv[1]);
    char *host = argv[2];

    int listen_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_socket == -1) {
        perror("socket");
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, host, &server_addr.sin_addr);

    if (bind(listen_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(1);
    }

    if (listen(listen_socket, 5) == -1) {
        perror("listen");
        exit(1);
    }

    while (1) {
        struct sockaddr_in client_addr;
        socklen_t client_size = sizeof(client_addr);
        int client_socket = accept(listen_socket, (struct sockaddr *)&client_addr, &client_size);
        if (client_socket == -1) {
            perror("accept");
            continue;
        }

        char buffer[1024];
        while (1) {
            memset(buffer, 0, sizeof(buffer));
            ssize_t bytes_received = recv(client_socket, buffer, sizeof(buffer), MSG_DONTWAIT);
            if (bytes_received <= 0) {
                if (errno == EAGAIN) {
                    break;
                } else {
                    perror("recv");
                    close(client_socket);
                    break;
                }
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