//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define BUFFER_SIZE 1024

void error_handling(char *message);

int main(int argc, char *argv[]) {
    int server_socket, new_socket;
    struct sockaddr_in server_addr, client_addr;
    int opt = 1;
    int addrlen = sizeof(client_addr);
    char buffer[BUFFER_SIZE];

    if (argc!= 2) {
        printf("Usage: %s <port>\n", argv[0]);
        return 1;
    }

    server_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (server_socket == -1) {
        error_handling("socket failed");
    }

    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        error_handling("setsockopt");
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(atoi(argv[1]));

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error_handling("bind failed");
    }

    if (listen(server_socket, 5) < 0) {
        error_handling("listen");
    }

    while (1) {
        printf("Waiting for connection...\n");
        new_socket = accept(server_socket, (struct sockaddr *)&client_addr, (socklen_t*)&addrlen);

        if (new_socket < 0) {
            error_handling("accept");
        }

        printf("New client connected\n");

        while (1) {
            memset(buffer, 0, BUFFER_SIZE);
            if (recv(new_socket, buffer, BUFFER_SIZE, 0) <= 0) {
                error_handling("recv");
            }

            printf("Received message: %s\n", buffer);

            send(new_socket, buffer, strlen(buffer), 0);
        }
    }

    return 0;
}

void error_handling(char *message) {
    fprintf(stderr, "Error: %s\n", message);
    exit(1);
}