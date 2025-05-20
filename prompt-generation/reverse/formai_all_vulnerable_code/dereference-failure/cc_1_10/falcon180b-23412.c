//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUF_SIZE 1024

void proxy_request(int client_socket, int server_socket) {
    char buffer[BUF_SIZE];
    while (1) {
        memset(buffer, 0, BUF_SIZE);
        int bytes_received = recv(client_socket, buffer, BUF_SIZE, 0);
        if (bytes_received <= 0) {
            break;
        }
        send(server_socket, buffer, bytes_received, 0);
        memset(buffer, 0, BUF_SIZE);
        int bytes_received_from_server = recv(server_socket, buffer, BUF_SIZE, 0);
        if (bytes_received_from_server <= 0) {
            break;
        }
        send(client_socket, buffer, bytes_received_from_server, 0);
    }
    close(client_socket);
    close(server_socket);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <port> <host>\n", argv[0]);
        return 1;
    }
    int port = atoi(argv[1]);
    char *host = argv[2];

    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, host, &server_addr.sin_addr);

    if (connect(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        return 1;
    }

    printf("Connected to server\n");

    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);
        if (client_socket == -1) {
            printf("Error accepting connection\n");
            continue;
        }
        printf("Accepted connection from client\n");
        proxy_request(client_socket, server_socket);
    }

    return 0;
}