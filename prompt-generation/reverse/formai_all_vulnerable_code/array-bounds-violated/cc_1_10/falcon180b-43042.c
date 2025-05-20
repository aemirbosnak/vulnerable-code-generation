//Falcon-180B DATASET v1.0 Category: Chat server ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080
#define BACKLOG 10
#define BUFFER_SIZE 1024

int main() {
    int listen_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];

    listen_fd = socket(AF_INET, SOCK_STREAM, 0);

    if (listen_fd == -1) {
        printf("Could not create socket\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT);

    if (bind(listen_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Could not bind to address\n");
        exit(1);
    }

    if (listen(listen_fd, BACKLOG) == -1) {
        printf("Could not listen to socket\n");
        exit(1);
    }

    printf("Server listening on port %d\n", PORT);

    while (1) {
        socklen_t client_size = sizeof(client_addr);
        client_fd = accept(listen_fd, (struct sockaddr *)&client_addr, &client_size);

        if (client_fd == -1) {
            printf("Could not accept connection\n");
            continue;
        }

        printf("Connection accepted from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while (1) {
            memset(buffer, 0, BUFFER_SIZE);

            int bytes_received = recv(client_fd, buffer, BUFFER_SIZE, 0);

            if (bytes_received == 0) {
                printf("Client disconnected\n");
                close(client_fd);
                break;
            }

            if (bytes_received == -1) {
                printf("Error receiving data\n");
                break;
            }

            buffer[bytes_received] = '\0';

            printf("Received message: %s\n", buffer);

            send(client_fd, buffer, strlen(buffer), 0);
        }

        close(client_fd);
    }

    close(listen_fd);

    return 0;
}