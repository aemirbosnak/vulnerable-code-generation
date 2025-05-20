//Falcon-180B DATASET v1.0 Category: Simple Web Server ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define BACKLOG 10
#define BUFFER_SIZE 1024

int main() {
    int listen_fd, conn_fd;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];

    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT);

    if (bind(listen_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        exit(2);
    }

    if (listen(listen_fd, BACKLOG) == -1) {
        printf("Error listening on socket\n");
        exit(3);
    }

    while (1) {
        socklen_t client_size = sizeof(client_addr);
        conn_fd = accept(listen_fd, (struct sockaddr *)&client_addr, &client_size);

        if (conn_fd == -1) {
            printf("Error accepting connection\n");
            continue;
        }

        printf("Connection accepted from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while (1) {
            bzero(buffer, BUFFER_SIZE);
            int bytes_received = recv(conn_fd, buffer, BUFFER_SIZE, 0);

            if (bytes_received == 0) {
                printf("Client disconnected\n");
                close(conn_fd);
                break;
            }

            if (bytes_received == -1) {
                printf("Error receiving data\n");
                close(conn_fd);
                break;
            }

            buffer[bytes_received] = '\0';
            printf("Received data: %s\n", buffer);

            if (send(conn_fd, buffer, bytes_received, 0) == -1) {
                printf("Error sending data\n");
                close(conn_fd);
                break;
            }
        }
    }

    close(listen_fd);
    return 0;
}