//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void proxy_error(int client_socket, char* message) {
    write(client_socket, message, strlen(message));
    close(client_socket);
    exit(1);
}

int main(int argc, char** argv) {
    if(argc!= 3) {
        fprintf(stderr, "Usage: %s <port> <host>\n", argv[0]);
        return 1;
    }

    int port = atoi(argv[1]);
    char* host = argv[2];

    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(server_socket == -1) {
        proxy_error(0, "Error creating socket\n");
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, host, &server_addr.sin_addr);

    if(connect(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        proxy_error(0, "Error connecting to server\n");
    }

    int client_socket = accept(server_socket, NULL, NULL);
    if(client_socket == -1) {
        proxy_error(0, "Error accepting client connection\n");
    }

    char buffer[BUFFER_SIZE];
    while(1) {
        int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
        if(bytes_received <= 0) {
            break;
        }

        send(server_socket, buffer, bytes_received, 0);

        bytes_received = recv(server_socket, buffer, BUFFER_SIZE, 0);
        if(bytes_received <= 0) {
            break;
        }

        send(client_socket, buffer, bytes_received, 0);
    }

    close(client_socket);
    close(server_socket);

    return 0;
}