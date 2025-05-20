//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024

void error_handling(char *message) {
    perror(message);
    exit(1);
}

int main(int argc, char *argv[]) {
    int listen_fd, client_fd, bytes_received, bytes_sent;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in server_addr, client_addr;

    if (argc!= 3) {
        printf("Usage: %s <IP address> <port>\n", argv[0]);
        return 1;
    }

    listen_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_fd == -1)
        error_handling("socket failed");

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    if (bind(listen_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1)
        error_handling("bind failed");

    if (listen(listen_fd, 5) == -1)
        error_handling("listen failed");

    printf("Proxy server started on %s:%d\n", argv[1], atoi(argv[2]));

    while (1) {
        socklen_t addr_size;
        client_fd = accept(listen_fd, (struct sockaddr *)&client_addr, &addr_size);
        if (client_fd == -1)
            error_handling("accept failed");

        printf("Connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while (1) {
            memset(buffer, 0, BUFFER_SIZE);
            bytes_received = recv(client_fd, buffer, BUFFER_SIZE, 0);

            if (bytes_received <= 0) {
                close(client_fd);
                break;
            }

            printf("Received %d bytes from client\n", bytes_received);

            bytes_sent = send(client_fd, buffer, bytes_received, 0);

            if (bytes_sent!= bytes_received)
                error_handling("send failed");
        }
    }

    return 0;
}