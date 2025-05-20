//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

void process_request(int client_socket, int server_socket) {
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);

    while (1) {
        int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            break;
        }

        char *request_line = strstr(buffer, "\r\n\r\n");
        if (request_line!= NULL) {
            *request_line = '\0';

            send(server_socket, buffer, strlen(buffer), 0);

            char *response = "HTTP/1.1 200 OK\r\nContent-Length: 0\r\n\r\n";
            send(client_socket, response, strlen(response), 0);

            break;
        }

        memmove(buffer, buffer + bytes_received, strlen(buffer) - bytes_received);
    }

    close(client_socket);
    close(server_socket);
}

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr));
    listen(server_socket, 5);

    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);
        process_request(client_socket, server_socket);
    }

    return 0;
}