//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024
#define PORT 8080

int main(int argc, char *argv[]) {
    int listen_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_size;
    char buffer[BUFFER_SIZE];
    int bytes_received;
    int client_port;

    listen_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_socket == -1) {
        perror("socket");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(listen_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(1);
    }

    if (listen(listen_socket, 5) == -1) {
        perror("listen");
        exit(1);
    }

    printf("HTTP proxy server started on port %d\n", PORT);

    while (1) {
        addr_size = sizeof(client_addr);
        client_socket = accept(listen_socket, (struct sockaddr *) &client_addr, &addr_size);
        if (client_socket == -1) {
            perror("accept");
            continue;
        }

        client_port = ntohs(client_addr.sin_port);
        printf("Connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), client_port);

        while (1) {
            bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
            if (bytes_received <= 0) {
                printf("Connection closed\n");
                break;
            }

            buffer[bytes_received] = '\0';
            printf("Received %d bytes: %s", bytes_received, buffer);

            if (send(client_socket, buffer, bytes_received, 0) == -1) {
                perror("send");
                break;
            }
        }

        close(client_socket);
    }

    close(listen_socket);
    return 0;
}