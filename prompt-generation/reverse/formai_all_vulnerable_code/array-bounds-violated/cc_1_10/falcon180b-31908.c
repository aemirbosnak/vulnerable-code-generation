//Falcon-180B DATASET v1.0 Category: Simple Web Server ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024
#define PORT 8080

int main(int argc, char *argv[]) {
    int listen_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_size;

    listen_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_socket == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT);

    if (bind(listen_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        exit(1);
    }

    if (listen(listen_socket, 5) == -1) {
        printf("Error listening on socket\n");
        exit(1);
    }

    while (1) {
        client_size = sizeof(client_addr);
        client_socket = accept(listen_socket, (struct sockaddr *)&client_addr, &client_size);
        if (client_socket == -1) {
            printf("Error accepting connection\n");
            continue;
        }

        printf("Connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        char buffer[BUFFER_SIZE];
        memset(buffer, 0, BUFFER_SIZE);

        int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            printf("Error receiving data\n");
            close(client_socket);
            continue;
        }

        buffer[bytes_received] = '\0';
        printf("Received data: %s\n", buffer);

        char response[BUFFER_SIZE];
        memset(response, 0, BUFFER_SIZE);
        strcat(response, "HTTP/1.1 200 OK\r\n");
        strcat(response, "Content-Type: text/html\r\n");
        strcat(response, "Content-Length: ");
        int response_length = sprintf(response + strlen(response), "%d\r\n", strlen("Hello, World! "));
        strcat(response, "\r\n");
        strcat(response, "Hello, World!");

        send(client_socket, response, response_length, 0);
        close(client_socket);
    }

    close(listen_socket);
    return 0;
}