//Falcon-180B DATASET v1.0 Category: Firewall ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>

#define MAX_CLIENTS 100
#define BUFFER_SIZE 1024

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("socket");
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(1);
    }

    if (listen(server_socket, MAX_CLIENTS) == -1) {
        perror("listen");
        exit(1);
    }

    printf("Firewall is running on port 8080\n");

    int client_socket;
    struct sockaddr_in client_addr;
    socklen_t client_addr_size = sizeof(client_addr);

    while (1) {
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_size);
        if (client_socket == -1) {
            perror("accept");
            continue;
        }

        char buffer[BUFFER_SIZE];
        memset(buffer, 0, BUFFER_SIZE);

        int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
        if (bytes_received == -1) {
            perror("recv");
            close(client_socket);
            continue;
        }

        buffer[bytes_received] = '\0';

        if (strstr(buffer, "GET") == NULL && strstr(buffer, "POST") == NULL) {
            send(client_socket, "HTTP/1.1 403 Forbidden\r\nContent-Length: 0\r\n\r\n", strlen("HTTP/1.1 403 Forbidden\r\nContent-Length: 0\r\n\r\n"), 0);
            close(client_socket);
            continue;
        }

        send(client_socket, buffer, bytes_received, 0);
        close(client_socket);
    }

    close(server_socket);
    return 0;
}