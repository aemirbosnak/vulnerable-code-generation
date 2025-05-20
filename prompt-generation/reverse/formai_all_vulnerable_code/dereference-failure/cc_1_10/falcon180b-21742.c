//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

void handle_client(int client_socket, struct sockaddr_in server_addr) {
    char buffer[BUFFER_SIZE];
    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            break;
        }
        send(client_socket, buffer, bytes_received, 0);
    }
    close(client_socket);
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s [port] [ip]\n", argv[0]);
        return 1;
    }
    int port = atoi(argv[1]);
    char *ip = argv[2];
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, ip, &server_addr.sin_addr);

    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        fprintf(stderr, "Error creating socket: %s\n", strerror(errno));
        return 1;
    }

    if (connect(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        fprintf(stderr, "Error connecting to server: %s\n", strerror(errno));
        return 1;
    }

    int listener_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listener_socket == -1) {
        fprintf(stderr, "Error creating listener socket: %s\n", strerror(errno));
        return 1;
    }

    struct sockaddr_in listener_addr;
    memset(&listener_addr, 0, sizeof(listener_addr));
    listener_addr.sin_family = AF_INET;
    listener_addr.sin_port = htons(8080);
    listener_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(listener_socket, (struct sockaddr *)&listener_addr, sizeof(listener_addr)) == -1) {
        fprintf(stderr, "Error binding listener socket: %s\n", strerror(errno));
        return 1;
    }

    if (listen(listener_socket, 10) == -1) {
        fprintf(stderr, "Error listening on socket: %s\n", strerror(errno));
        return 1;
    }

    while (1) {
        struct sockaddr_in client_addr;
        socklen_t addr_len = sizeof(client_addr);
        int client_socket = accept(listener_socket, (struct sockaddr *)&client_addr, &addr_len);
        if (client_socket == -1) {
            fprintf(stderr, "Error accepting connection: %s\n", strerror(errno));
            continue;
        }
        handle_client(client_socket, server_addr);
    }

    return 0;
}