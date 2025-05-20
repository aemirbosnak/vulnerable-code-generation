//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

void error_handling(char *message);

int main(int argc, char *argv[]) {
    int listen_socket, client_socket, bytes_read, bytes_sent;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];

    listen_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_socket == -1) {
        error_handling("socket failed");
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);

    if (bind(listen_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        error_handling("bind failed");
    }

    if (listen(listen_socket, 5) < 0) {
        error_handling("listen failed");
    }

    printf("Proxy server is running on port 8080\n");

    while (1) {
        memset(&client_addr, 0, sizeof(client_addr));
        socklen_t addr_size = sizeof(client_addr);
        client_socket = accept(listen_socket, (struct sockaddr *) &client_addr, &addr_size);
        if (client_socket < 0) {
            error_handling("accept failed");
        }

        char host[1024];
        char request[1024];
        memset(host, 0, sizeof(host));
        memset(request, 0, sizeof(request));

        bytes_read = recv(client_socket, buffer, BUFFER_SIZE, 0);
        if (bytes_read <= 0) {
            error_handling("recv failed");
        }

        buffer[bytes_read] = '\0';
        strcat(host, buffer);

        strcat(request, "GET / HTTP/1.1\r\nHost: ");
        strcat(request, host);
        strcat(request, "\r\nConnection: close\r\n\r\n");

        send(client_socket, request, strlen(request), 0);

        close(client_socket);
    }

    close(listen_socket);

    return 0;
}

void error_handling(char *message) {
    perror(message);
    exit(1);
}