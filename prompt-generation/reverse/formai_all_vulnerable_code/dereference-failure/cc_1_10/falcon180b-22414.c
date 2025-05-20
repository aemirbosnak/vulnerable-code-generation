//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netinet/tcp.h>

#define BUFFER_SIZE 1024

void error_handling(char *message);

int main(int argc, char *argv[]) {
    int listen_socket, client_socket, bytes_received, bytes_sent;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_size;
    char buffer[BUFFER_SIZE];

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return 1;
    }

    listen_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_socket == -1) {
        error_handling("socket");
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[1]));
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(listen_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        error_handling("bind");
    }

    if (listen(listen_socket, 10) == -1) {
        error_handling("listen");
    }

    while (1) {
        client_addr_size = sizeof(client_addr);
        client_socket = accept(listen_socket, (struct sockaddr *)&client_addr, &client_addr_size);
        if (client_socket == -1) {
            error_handling("accept");
        }

        while (1) {
            bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
            if (bytes_received == 0) {
                break;
            }

            if (bytes_received == -1) {
                error_handling("recv");
            }

            bytes_sent = send(client_socket, buffer, bytes_received, 0);
            if (bytes_sent == -1) {
                error_handling("send");
            }
        }

        close(client_socket);
    }

    close(listen_socket);
    return 0;
}

void error_handling(char *message) {
    perror(message);
    exit(1);
}