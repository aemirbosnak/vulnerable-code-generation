//Falcon-180B DATASET v1.0 Category: Client Server Application ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 8080
#define BACKLOG 10
#define BUFFER_SIZE 1024

void error_handling(const char* message);

int main(int argc, char* argv[]) {
    int listen_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_size;

    listen_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (listen_socket == -1) {
        error_handling("socket failed");
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(listen_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        error_handling("bind failed");
    }

    if (listen(listen_socket, BACKLOG) == -1) {
        error_handling("listen failed");
    }

    printf("Server is listening on port %d\n", PORT);

    while (1) {
        client_size = sizeof(client_addr);
        client_socket = accept(listen_socket, (struct sockaddr*)&client_addr, &client_size);

        if (client_socket == -1) {
            error_handling("accept failed");
        }

        char buffer[BUFFER_SIZE];
        bzero(buffer, BUFFER_SIZE);

        while (1) {
            ssize_t bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);

            if (bytes_received == -1) {
                error_handling("recv failed");
            } else if (bytes_received == 0) {
                printf("Client disconnected\n");
                close(client_socket);
                break;
            }

            buffer[bytes_received] = '\0';
            printf("Received message: %s\n", buffer);

            ssize_t bytes_sent = send(client_socket, "ACK", strlen("ACK"), 0);

            if (bytes_sent == -1) {
                error_handling("send failed");
            }
        }
    }

    return 0;
}

void error_handling(const char* message) {
    perror(message);
    exit(1);
}