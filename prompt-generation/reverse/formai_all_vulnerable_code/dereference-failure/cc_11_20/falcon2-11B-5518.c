//Falcon2-11B DATASET v1.0 Category: Socket programming ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len;
    char buffer[256];

    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        return 1;
    }

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        fprintf(stderr, "Failed to create socket\n");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(atoi(argv[1]));

    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        fprintf(stderr, "Failed to bind socket\n");
        return 1;
    }

    if (listen(server_fd, 5) == -1) {
        fprintf(stderr, "Failed to listen on socket\n");
        return 1;
    }

    printf("Listening on port %d...\n", ntohs(server_addr.sin_port));

    while (1) {
        client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_len);
        if (client_fd == -1) {
            fprintf(stderr, "Failed to accept connection\n");
            continue;
        }

        printf("Connected to client: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while (1) {
            if (read(client_fd, buffer, sizeof(buffer)) <= 0) {
                printf("Read error\n");
                break;
            }

            if (write(client_fd, buffer, strlen(buffer))!= strlen(buffer)) {
                printf("Write error\n");
                break;
            }

            if (strcmp(buffer, "quit") == 0) {
                printf("Client disconnected\n");
                break;
            }
        }

        printf("Client disconnected\n");
        close(client_fd);
    }

    close(server_fd);
    return 0;
}