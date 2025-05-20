//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/time.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

void error_handling(char* message);

int main(int argc, char* argv[]) {
    int listen_socket, client_socket, bytes_received, bytes_sent;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];
    int opt = 1;

    if (argc!= 3) {
        printf("Usage: %s <port> <ip>\n", argv[0]);
        return 1;
    }

    listen_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_socket == -1) {
        error_handling("socket failed");
        return 1;
    }

    if (setsockopt(listen_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        error_handling("setsockopt");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[2]);
    server_addr.sin_port = htons(atoi(argv[1]));

    if (bind(listen_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        error_handling("bind failed");
        return 1;
    }

    if (listen(listen_socket, 5) == -1) {
        error_handling("listen");
        return 1;
    }

    printf("Proxy server listening on port %s\n", argv[1]);

    while (1) {
        client_socket = accept(listen_socket, (struct sockaddr*)&client_addr, sizeof(client_addr));
        if (client_socket == -1) {
            error_handling("accept");
            continue;
        }

        printf("Connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while (1) {
            bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
            if (bytes_received <= 0) {
                error_handling("recv");
                break;
            }

            send(client_socket, buffer, bytes_received, 0);
        }

        close(client_socket);
    }

    close(listen_socket);
    return 0;
}

void error_handling(char* message) {
    perror(message);
    exit(1);
}