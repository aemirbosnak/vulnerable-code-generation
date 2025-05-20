//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>
#include <stdbool.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;

    if (argc != 3) {
        fprintf(stderr, "Usage: ./proxy <local_port> <remote_server_ip>\n");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[1]));
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Error creating server socket");
        exit(EXIT_FAILURE);
    }

    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error binding server socket");
        exit(EXIT_FAILURE);
    }

    if (listen(server_fd, 10) < 0) {
        perror("Error listening on server socket");
        exit(EXIT_FAILURE);
    }

    printf("Proxy server listening on port %d\n", atoi(argv[1]));

    while (true) {
        socklen_t client_addr_len = sizeof(client_addr);
        char buffer[BUFFER_SIZE] = {0};

        if ((client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_addr_len)) < 0) {
            perror("Error accepting incoming connection");
            exit(EXIT_FAILURE);
        }

        char *remote_server_ip = argv[2];
        int remote_server_port = 80;
        struct sockaddr_in remote_server_addr;

        if ((remote_server_addr.sin_addr.s_addr = inet_addr(remote_server_ip)) == INADDR_NONE) {
            perror("Error converting remote server IP");
            close(client_fd);
            continue;
        }

        remote_server_addr.sin_family = AF_INET;
        remote_server_addr.sin_port = htons(remote_server_port);

        if (connect(client_fd, (struct sockaddr *)&remote_server_addr, sizeof(remote_server_addr)) < 0) {
            perror("Error connecting to remote server");
            close(client_fd);
            continue;
        }

        long total_bytes_transferred = 0;
        while (true) {
            long bytes_read = recv(client_fd, buffer, BUFFER_SIZE, 0);
            total_bytes_transferred += bytes_read;
            if (bytes_read == 0) {
                break;
            }
            if (bytes_read < 0) {
                perror("Error reading from client socket");
                break;
            }

            printf("Read %ld bytes from client\n", bytes_read);

            if (send(client_fd, buffer, bytes_read, 0) < 0) {
                perror("Error sending to remote server");
                break;
            }

            printf("Sent %ld bytes to remote server\n", bytes_read);

            if (send(client_fd, buffer, bytes_read, 0) < 0) {
                perror("Error sending to remote server");
                break;
            }

            printf("Sent %ld bytes to client\n", bytes_read);
        }

        printf("Total %ld bytes transferred between client and server\n", total_bytes_transferred);
        close(client_fd);
    }

    return 0;
}