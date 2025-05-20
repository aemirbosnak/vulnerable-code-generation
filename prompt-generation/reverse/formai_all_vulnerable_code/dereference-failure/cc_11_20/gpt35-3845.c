//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define BUFFER_SIZE 1024

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: %s [proxy port] [remote server IP] [remote server port]\n", argv[0]);
        exit(0);
    }

    int proxy_port = atoi(argv[1]);
    char* remote_ip = argv[2];
    int remote_port = atoi(argv[3]);

    int proxy_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (proxy_socket < 0) {
        perror("Error creating socket\n");
        exit(1);
    }

    struct sockaddr_in proxy_addr, remote_addr;
    proxy_addr.sin_family = AF_INET;
    proxy_addr.sin_addr.s_addr = INADDR_ANY;
    proxy_addr.sin_port = htons(proxy_port);

    if (bind(proxy_socket, (struct sockaddr*) &proxy_addr, sizeof(proxy_addr)) < 0) {
        perror("Error binding socket\n");
        exit(1);
    }
    listen(proxy_socket, 5);

    char buffer[BUFFER_SIZE];

    while (1) {
        int client_socket = accept(proxy_socket, NULL, NULL);
        if (client_socket < 0) {
            perror("Error accepting connection");
            continue;
        }

        int remote_socket = socket(AF_INET, SOCK_STREAM, 0);
        remote_addr.sin_family = AF_INET;
        remote_addr.sin_addr.s_addr = inet_addr(remote_ip);
        remote_addr.sin_port = htons(remote_port);

        if (connect(remote_socket, (struct sockaddr*) &remote_addr, sizeof(remote_addr)) < 0) {
            perror("Error connecting to remote server");
            close(client_socket);
            close(remote_socket);
            continue;
        }

        while (1) {
            fd_set set;
            FD_ZERO(&set);
            FD_SET(client_socket, &set);
            FD_SET(remote_socket, &set);

            select(FD_SETSIZE, &set, NULL, NULL, NULL);

            if (FD_ISSET(client_socket, &set)) {
                int bytes_read = recv(client_socket, buffer, BUFFER_SIZE, 0);
                if (bytes_read <= 0) break;
                send(remote_socket, buffer, bytes_read, 0);
            }

            if (FD_ISSET(remote_socket, &set)) {
                int bytes_read = recv(remote_socket, buffer, BUFFER_SIZE, 0);
                if (bytes_read <= 0) break;
                send(client_socket, buffer, bytes_read, 0);
            }
        }

        close(client_socket);
        close(remote_socket);
    }

    close(proxy_socket);

    return 0;
}