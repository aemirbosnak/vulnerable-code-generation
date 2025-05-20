//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>

#define BUF_SIZE 1024

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void listen_socket(int socket) {
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(12345);

    if (bind(socket, (struct sockaddr *)&server_addr, sizeof(server_addr))) {
        error("bind failed");
    }

    if (listen(socket, 5)) {
        error("listen");
    }
}

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        error("socket failed");
    }

    listen_socket(server_socket);

    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);
        if (client_socket == -1) {
            error("accept");
        }

        char buffer[BUF_SIZE];
        memset(buffer, 0, BUF_SIZE);

        while (1) {
            int bytes_received = recv(client_socket, buffer, BUF_SIZE, 0);
            if (bytes_received <= 0) {
                break;
            }

            buffer[bytes_received] = '\0';
            printf("Received message: %s\n", buffer);

            if (strcmp(buffer, "exit") == 0) {
                break;
            }

            send(client_socket, buffer, strlen(buffer), 0);
        }

        close(client_socket);
    }

    return 0;
}