//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_LINE 1024
#define SERVER_PORT 8080
#define SERVER "127.0.0.1"

int main(int argc, char *argv[]) {
    int server_socket, client_socket, bytes_received, bytes_sent;
    struct sockaddr_in server_addr, client_addr;
    char buffer[MAX_LINE];

    if (argc!= 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER);

    if (connect(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    while (1) {
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, sizeof(client_addr));
        if (client_socket == -1) {
            printf("Error accepting connection\n");
            exit(1);
        }

        printf("Connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while (1) {
            bytes_received = recv(client_socket, buffer, MAX_LINE, 0);
            if (bytes_received == 0) {
                printf("Client disconnected\n");
                close(client_socket);
                break;
            }

            if (bytes_received == -1) {
                printf("Error receiving data\n");
                close(client_socket);
                break;
            }

            buffer[bytes_received] = '\0';
            printf("Received: %s\n", buffer);

            bytes_sent = send(server_socket, buffer, bytes_received, 0);
            if (bytes_sent == -1) {
                printf("Error sending data\n");
                close(client_socket);
                break;
            }

            if (bytes_sent == 0) {
                printf("Server disconnected\n");
                close(client_socket);
                break;
            }
        }
    }

    close(server_socket);
    return 0;
}