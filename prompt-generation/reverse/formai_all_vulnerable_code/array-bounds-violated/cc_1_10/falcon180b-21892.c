//Falcon-180B DATASET v1.0 Category: Networking ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

void handle_client(int client_socket);

int main() {
    int server_socket;
    int client_socket;
    int opt = 1;
    struct sockaddr_in server_addr;
    struct sockaddr_in client_addr;
    socklen_t client_addr_size;

    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        printf("Error: socket() failed\n");
        return 1;
    }

    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        printf("Error: setsockopt() failed\n");
        return 1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(8080);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error: bind() failed\n");
        return 1;
    }

    if (listen(server_socket, 5) == -1) {
        printf("Error: listen() failed\n");
        return 1;
    }

    while (1) {
        client_addr_size = sizeof(client_addr);
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_size)) == -1) {
            printf("Error: accept() failed\n");
            continue;
        }

        handle_client(client_socket);

        close(client_socket);
    }

    return 0;
}

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    int bytes_received;

    while ((bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("Received message: %s\n", buffer);

        send(client_socket, buffer, strlen(buffer), 0);
    }

    if (bytes_received == 0) {
        printf("Client disconnected\n");
    } else {
        printf("Error: recv() failed\n");
    }

    close(client_socket);
}