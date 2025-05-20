//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024
#define MAX_REQUEST_SIZE 4096

int main(int argc, char *argv[]) {
    int listener_socket, client_socket, bytes_received;
    struct sockaddr_in server_addr, client_addr;

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <IP address> <port>\n", argv[0]);
        exit(1);
    }

    listener_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listener_socket == -1) {
        fprintf(stderr, "Error creating socket: %s\n", strerror(errno));
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    if (bind(listener_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        fprintf(stderr, "Error binding socket: %s\n", strerror(errno));
        exit(1);
    }

    if (listen(listener_socket, 5) == -1) {
        fprintf(stderr, "Error listening on socket: %s\n", strerror(errno));
        exit(1);
    }

    printf("Proxy server started on %s:%d\n", argv[1], atoi(argv[2]));

    while (1) {
        client_socket = accept(listener_socket, (struct sockaddr *)&client_addr, sizeof(client_addr));
        if (client_socket == -1) {
            fprintf(stderr, "Error accepting connection: %s\n", strerror(errno));
            continue;
        }

        char request[MAX_REQUEST_SIZE];
        bytes_received = recv(client_socket, request, MAX_REQUEST_SIZE, 0);
        if (bytes_received <= 0) {
            fprintf(stderr, "Error receiving request: %s\n", strerror(errno));
            close(client_socket);
            continue;
        }

        request[bytes_received] = '\0';
        printf("Received request: %s\n", request);

        char response[BUFFER_SIZE];
        snprintf(response, BUFFER_SIZE, "HTTP/1.1 200 OK\r\nContent-Length: %d\r\n\r\n", strlen(request));

        send(client_socket, response, strlen(response), 0);
        send(client_socket, request, bytes_received, 0);

        close(client_socket);
    }

    return 0;
}