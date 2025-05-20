//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

int main() {
    int server_fd, client_fd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_addr_len;

    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        perror("socket");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(1);
    }

    if (listen(server_fd, 5) == -1) {
        perror("listen");
        exit(1);
    }

    while (1) {
        client_fd = accept(server_fd, (struct sockaddr *)&client_addr, &client_addr_len);
        if (client_fd == -1) {
            perror("accept");
            continue;
        }

        char buffer[1024];
        int bytes_received = recv(client_fd, buffer, sizeof(buffer), 0);
        if (bytes_received == -1) {
            perror("recv");
            close(client_fd);
            continue;
        }

        char *host = strstr(buffer, "Host: ");
        if (host == NULL) {
            printf("Invalid request\n");
            close(client_fd);
            continue;
        }

        host += strlen("Host: ");
        char *end_of_host = strchr(host, '\r');
        *end_of_host = '\0';

        int target_fd = socket(AF_INET, SOCK_STREAM, 0);
        if (target_fd == -1) {
            perror("socket");
            close(client_fd);
            continue;
        }

        struct sockaddr_in target_addr;
        target_addr.sin_family = AF_INET;
        target_addr.sin_addr.s_addr = inet_addr(host);
        target_addr.sin_port = htons(80);

        if (connect(target_fd, (struct sockaddr *)&target_addr, sizeof(target_addr)) == -1) {
            perror("connect");
            close(client_fd);
            close(target_fd);
            continue;
        }

        send(target_fd, buffer, bytes_received, 0);

        char target_buffer[1024];
        int bytes_received_from_target = recv(target_fd, target_buffer, sizeof(target_buffer), 0);
        if (bytes_received_from_target == -1) {
            perror("recv");
            close(client_fd);
            close(target_fd);
            continue;
        }

        send(client_fd, target_buffer, bytes_received_from_target, 0);

        close(client_fd);
        close(target_fd);
    }

    return 0;
}