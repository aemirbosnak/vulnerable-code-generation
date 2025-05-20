//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int client_socket, server_socket;
    struct sockaddr_in client_addr, server_addr;
    socklen_t client_addr_size, server_addr_size;
    char buffer[BUFFER_SIZE];

    if (argc!= 3) {
        printf("Usage: %s <server_ip> <server_port>\n", argv[0]);
        return 1;
    }

    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);
    server_addr.sin_port = htons(atoi(argv[2]));

    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (server_socket == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    if (connect(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        return 1;
    }

    printf("Connected to server\n");

    while (1) {
        client_addr_size = sizeof(client_addr);
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_size);

        if (client_socket == -1) {
            printf("Error accepting connection\n");
            continue;
        }

        printf("Connection accepted from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while (1) {
            memset(buffer, 0, BUFFER_SIZE);

            if (recv(client_socket, buffer, BUFFER_SIZE, 0) == 0) {
                printf("Client disconnected\n");
                break;
            }

            printf("Received data: %s\n", buffer);

            if (send(server_socket, buffer, strlen(buffer), 0) == -1) {
                printf("Error sending data to server\n");
                break;
            }
        }

        close(client_socket);
    }

    close(server_socket);

    return 0;
}