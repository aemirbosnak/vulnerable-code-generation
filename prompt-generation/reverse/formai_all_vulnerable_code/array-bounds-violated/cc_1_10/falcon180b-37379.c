//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(8080);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        exit(2);
    }

    if (listen(server_socket, 5) == -1) {
        printf("Error listening on socket\n");
        exit(3);
    }

    printf("Server listening on port 8080\n");

    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);
        if (client_socket == -1) {
            printf("Error accepting connection\n");
            exit(4);
        }

        char buffer[1024];
        memset(buffer, 0, sizeof(buffer));

        while (1) {
            ssize_t bytes_received = recv(client_socket, buffer, sizeof(buffer), 0);
            if (bytes_received == 0) {
                printf("Client disconnected\n");
                close(client_socket);
                break;
            }

            if (bytes_received == -1) {
                printf("Error receiving data from client\n");
                close(client_socket);
                break;
            }

            buffer[bytes_received] = '\0';
            printf("Received message: %s\n", buffer);

            ssize_t bytes_sent = send(client_socket, buffer, strlen(buffer), 0);
            if (bytes_sent == -1) {
                printf("Error sending data to client\n");
                close(client_socket);
                break;
            }
        }
    }

    close(server_socket);
    return 0;
}