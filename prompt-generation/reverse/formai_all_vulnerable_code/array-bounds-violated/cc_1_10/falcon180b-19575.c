//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024
#define SERVER_PORT 12345

int main() {
    int listen_socket, client_socket, bytes_received;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];

    listen_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_socket == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(listen_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        exit(1);
    }

    if (listen(listen_socket, 5) == -1) {
        printf("Error listening on socket\n");
        exit(1);
    }

    printf("QoS monitor is listening on port %d\n", SERVER_PORT);

    while (1) {
        client_socket = accept(listen_socket, (struct sockaddr *)&client_addr, sizeof(client_addr));
        if (client_socket == -1) {
            printf("Error accepting connection\n");
            continue;
        }

        bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            printf("Error receiving data\n");
            close(client_socket);
            continue;
        }

        buffer[bytes_received] = '\0';
        printf("Received data: %s\n", buffer);

        close(client_socket);
    }

    return 0;
}