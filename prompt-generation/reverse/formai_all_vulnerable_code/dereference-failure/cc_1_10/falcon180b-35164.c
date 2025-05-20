//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: minimalist
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUFFER_SIZE 1024
#define PORT 8080

int main(int argc, char *argv[]) {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];

    if (argc!= 2) {
        printf("Usage: %s <server_address>\n", argv[0]);
        return 1;
    }

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    if (connect(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        return 1;
    }

    while (true) {
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, sizeof(client_addr));
        if (client_socket == -1) {
            printf("Error accepting client connection\n");
            continue;
        }

        char *request = "GET / HTTP/1.1\r\nHost: ";
        strcat(request, argv[1]);
        strcat(request, "\r\nConnection: close\r\n\r\n");

        send(client_socket, request, strlen(request), 0);

        while (true) {
            memset(buffer, 0, BUFFER_SIZE);
            int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
            if (bytes_received == 0) {
                printf("Client disconnected\n");
                break;
            }

            send(server_socket, buffer, bytes_received, 0);
        }

        close(client_socket);
    }

    close(server_socket);
    return 0;
}