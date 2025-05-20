//Falcon-180B DATASET v1.0 Category: Simple Web Server ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define TRUE 1
#define FALSE 0
#define BACKLOG 10
#define SERVER_PORT 8080
#define SERVER_IP "127.0.0.1"

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    char buffer[1024];
    int addrlen = sizeof(client_addr);
    int bytes_received;

    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
    server_addr.sin_port = htons(SERVER_PORT);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error binding socket\n");
        exit(1);
    }

    if (listen(server_socket, BACKLOG) < 0) {
        printf("Error listening on socket\n");
        exit(1);
    }

    printf("Server listening on port %d\n", SERVER_PORT);

    while (TRUE) {
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, (socklen_t*)&addrlen)) < 0) {
            printf("Error accepting connection\n");
            exit(1);
        }

        printf("Connection accepted from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while (TRUE) {
            bytes_received = recv(client_socket, buffer, sizeof(buffer), 0);

            if (bytes_received <= 0) {
                break;
            }

            buffer[bytes_received] = '\0';
            printf("Received message: %s\n", buffer);

            if (send(client_socket, buffer, strlen(buffer), 0) < 0) {
                printf("Error sending message\n");
                exit(1);
            }
        }

        close(client_socket);
    }

    close(server_socket);
    return 0;
}