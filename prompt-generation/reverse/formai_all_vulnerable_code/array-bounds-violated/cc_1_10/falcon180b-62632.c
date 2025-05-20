//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define MAX_CONNECTIONS 10
#define SERVER_PORT 8080

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
    server_addr.sin_port = htons(SERVER_PORT);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        exit(1);
    }

    if (listen(server_socket, MAX_CONNECTIONS) == -1) {
        printf("Error listening on socket\n");
        exit(1);
    }

    printf("Server started on port %d\n", SERVER_PORT);

    int client_socket;
    struct sockaddr_in client_addr;
    socklen_t client_size = sizeof(client_addr);

    while (1) {
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_size);
        if (client_socket == -1) {
            printf("Error accepting connection\n");
            continue;
        }

        char buffer[BUFFER_SIZE];
        int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            printf("Error receiving data\n");
            close(client_socket);
            continue;
        }

        buffer[bytes_received] = '\0';
        printf("Received message: %s\n", buffer);

        send(client_socket, "ACK", 4, 0);
        close(client_socket);
    }

    return 0;
}