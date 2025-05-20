//Falcon-180B DATASET v1.0 Category: Client Server Application ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SERVER_PORT 8080
#define BUFFER_SIZE 1024

void handle_client(int client_socket);

int main() {
    int server_socket;
    struct sockaddr_in server_addr;
    int opt = 1;
    int addrlen = sizeof(server_addr);

    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(SERVER_PORT);

    if (bind(server_socket, (struct sockaddr *)&server_addr, addrlen) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, 5) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server is running on port %d\n", SERVER_PORT);

    while (1) {
        int client_socket;
        if ((client_socket = accept(server_socket, (struct sockaddr *)&server_addr, (socklen_t*)&addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }
        handle_client(client_socket);
    }

    return 0;
}

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    int bytes_received, total_bytes = 0;

    while ((bytes_received = recv(client_socket, buffer + total_bytes, BUFFER_SIZE - total_bytes, 0)) > 0) {
        total_bytes += bytes_received;
        buffer[total_bytes] = '\0';
        printf("Client sent: %s\n", buffer);
    }

    if (bytes_received == -1) {
        perror("recv");
    }

    close(client_socket);
}