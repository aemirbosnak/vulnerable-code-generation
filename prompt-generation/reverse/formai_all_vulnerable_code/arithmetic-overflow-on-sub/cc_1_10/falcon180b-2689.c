//Falcon-180B DATASET v1.0 Category: Antivirus scanner ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024
#define PORT 8080

void handle_client(int client_socket);

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    int opt = 1;
    int addrlen = sizeof(client_addr);

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));
    listen(server_socket, 5);

    printf("Server is listening on port %d\n", PORT);

    while (1) {
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, (socklen_t*)&addrlen);
        if (client_socket == -1) {
            printf("Error accepting connection\n");
            continue;
        }

        handle_client(client_socket);
        close(client_socket);
    }

    return 0;
}

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    int bytes_received, total_bytes = 0;

    while (1) {
        bytes_received = recv(client_socket, buffer + total_bytes, BUFFER_SIZE - total_bytes, 0);
        if (bytes_received == 0) {
            printf("Client disconnected\n");
            break;
        } else if (bytes_received == -1) {
            printf("Error receiving data\n");
            break;
        }

        total_bytes += bytes_received;

        if (total_bytes >= BUFFER_SIZE) {
            printf("Data received: %s\n", buffer);
            total_bytes = 0;
        }
    }
}