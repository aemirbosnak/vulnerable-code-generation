//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024
#define PORT 8080

int main(int argc, char **argv) {
    int listen_socket, client_socket, bytes_received, bytes_sent;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];
    
    listen_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_socket == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT);

    if (bind(listen_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket: %s\n", strerror(errno));
        exit(1);
    }

    if (listen(listen_socket, 5) == -1) {
        printf("Error listening on socket: %s\n", strerror(errno));
        exit(1);
    }

    while (1) {
        client_socket = accept(listen_socket, (struct sockaddr *)&client_addr, sizeof(client_addr));
        if (client_socket == -1) {
            printf("Error accepting connection: %s\n", strerror(errno));
            continue;
        }

        printf("Connection accepted from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while (1) {
            bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
            if (bytes_received == 0) {
                printf("Client disconnected\n");
                break;
            } else if (bytes_received == -1) {
                printf("Error receiving data: %s\n", strerror(errno));
                break;
            }

            buffer[bytes_received] = '\0';
            printf("Received data: %s", buffer);

            bytes_sent = send(client_socket, buffer, bytes_received, 0);
            if (bytes_sent == -1) {
                printf("Error sending data: %s\n", strerror(errno));
                break;
            }
        }

        close(client_socket);
    }

    close(listen_socket);

    return 0;
}