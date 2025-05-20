//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>

#define BUFFER_SIZE 4096
#define PORT 8080

int main() {
    int listen_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];
    int bytes_received;
    int bytes_sent;
    int opt = 1;

    listen_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_socket == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    if (setsockopt(listen_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        printf("Error setting options on socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT);

    if (bind(listen_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        exit(1);
    }

    if (listen(listen_socket, 5) == -1) {
        printf("Error listening on socket\n");
        exit(1);
    }

    while (1) {
        client_socket = accept(listen_socket, (struct sockaddr *)&client_addr, sizeof(client_addr));
        if (client_socket == -1) {
            printf("Error accepting connection\n");
            continue;
        }

        printf("Connection accepted from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while (1) {
            bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
            if (bytes_received == -1) {
                printf("Error receiving data\n");
                break;
            }

            if (bytes_received == 0) {
                printf("Client disconnected\n");
                break;
            }

            buffer[bytes_received] = '\0';
            printf("Received: %s\n", buffer);

            bytes_sent = send(client_socket, buffer, strlen(buffer), 0);
            if (bytes_sent == -1) {
                printf("Error sending data\n");
                break;
            }
        }

        close(client_socket);
    }

    close(listen_socket);
    return 0;
}