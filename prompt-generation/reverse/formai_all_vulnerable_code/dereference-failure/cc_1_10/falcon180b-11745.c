//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int listen_fd, client_fd, sock;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];

    if (argc!= 3) {
        printf("Usage: %s <port> <host>\n", argv[0]);
        return -1;
    }

    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd == -1) {
        printf("Error creating socket\n");
        return -1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[1]));
    server_addr.sin_addr.s_addr = inet_addr(argv[2]);

    if (bind(listen_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        return -1;
    }

    if (listen(listen_fd, 5) == -1) {
        printf("Error listening on socket\n");
        return -1;
    }

    while (1) {
        sock = accept(listen_fd, (struct sockaddr *)&client_addr, sizeof(client_addr));
        if (sock == -1) {
            printf("Error accepting connection\n");
            continue;
        }

        printf("Connection accepted from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while (1) {
            memset(buffer, 0, BUFFER_SIZE);
            ssize_t bytes_read = read(sock, buffer, BUFFER_SIZE);

            if (bytes_read <= 0) {
                printf("Error reading from socket\n");
                break;
            }

            printf("Received data: %s\n", buffer);

            ssize_t bytes_written = write(sock, buffer, bytes_read);
            if (bytes_written <= 0) {
                printf("Error writing to socket\n");
                break;
            }
        }

        close(sock);
    }

    close(listen_fd);
    return 0;
}