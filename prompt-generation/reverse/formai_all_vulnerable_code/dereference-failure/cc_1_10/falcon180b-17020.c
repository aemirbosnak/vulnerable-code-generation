//Falcon-180B DATASET v1.0 Category: Building a HTTP Client ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

int create_socket(int port) {
    int socket_fd;
    struct sockaddr_in server_addr;
    int opt = 1;

    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd < 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error binding socket\n");
        exit(1);
    }

    return socket_fd;
}

void send_request(int socket_fd, char *request) {
    send(socket_fd, request, strlen(request), 0);
}

char *receive_response(int socket_fd) {
    char response[BUFFER_SIZE];
    char *ptr;
    int bytes_received = 0;

    while (bytes_received < BUFFER_SIZE) {
        int bytes_read = recv(socket_fd, response + bytes_received, BUFFER_SIZE - bytes_received, 0);
        if (bytes_read <= 0) {
            printf("Error receiving response\n");
            exit(1);
        }
        bytes_received += bytes_read;
    }

    response[bytes_received] = '\0';
    ptr = strtok(response, "\r\n\r\n");
    return ptr;
}

int main(int argc, char *argv[]) {
    int socket_fd, port;
    char *request, *response;

    if (argc < 3) {
        printf("Usage: %s <port> <method> [path]\n", argv[0]);
        exit(1);
    }

    port = atoi(argv[1]);
    request = malloc(100);
    sprintf(request, "%s / HTTP/1.1\r\nHost: localhost:%d\r\n\r\n", argv[2], port);

    socket_fd = create_socket(port);
    send_request(socket_fd, request);
    response = receive_response(socket_fd);

    printf("Response:\n%s", response);

    close(socket_fd);
    free(request);

    return 0;
}