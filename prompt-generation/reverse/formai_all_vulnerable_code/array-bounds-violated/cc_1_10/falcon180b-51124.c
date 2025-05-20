//Falcon-180B DATASET v1.0 Category: Firewall ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUF_SIZE 1024
#define PORT 8080

int main() {
    int server_socket;
    struct sockaddr_in server_addr;
    int client_socket;
    struct sockaddr_in client_addr;
    char buffer[BUF_SIZE];
    int addrlen;
    int bytes_received;

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        exit(1);
    }

    if (listen(server_socket, 5) == -1) {
        printf("Error listening on socket\n");
        exit(1);
    }

    printf("Server started on port %d\n", PORT);

    while (1) {
        addrlen = sizeof(client_addr);
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addrlen);
        if (client_socket == -1) {
            printf("Error accepting connection\n");
            continue;
        }

        printf("Connection accepted from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while (1) {
            bytes_received = recv(client_socket, buffer, BUF_SIZE, 0);
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
            printf("Received: %s", buffer);

            send(client_socket, buffer, bytes_received, 0);
        }
    }

    close(server_socket);
    return 0;
}