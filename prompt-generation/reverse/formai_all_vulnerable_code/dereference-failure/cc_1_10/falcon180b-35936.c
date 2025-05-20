//Falcon-180B DATASET v1.0 Category: Networking ; Style: cheerful
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
#define PORT 8080
#define BACKLOG 10

int main(int argc, char *argv[]) {
    int server_socket, client_socket, bytes_received, total_bytes_received = 0;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];

    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        printf("Error creating socket\n");
        return 1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        return 1;
    }

    if (listen(server_socket, BACKLOG) == -1) {
        printf("Error listening on socket\n");
        return 1;
    }

    printf("Server started on port %d\n", PORT);

    while (1) {
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, sizeof(client_addr))) == -1) {
            printf("Error accepting connection\n");
            return 1;
        }

        printf("Connection accepted from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while ((bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0)) > 0) {
            total_bytes_received += bytes_received;
            printf("Received: %s\n", buffer);
            memset(buffer, 0, BUFFER_SIZE);
        }

        if (bytes_received == 0) {
            printf("Client disconnected\n");
            close(client_socket);
            break;
        } else {
            printf("Error receiving data: %s\n", strerror(errno));
            close(client_socket);
        }
    }

    close(server_socket);
    return 0;
}