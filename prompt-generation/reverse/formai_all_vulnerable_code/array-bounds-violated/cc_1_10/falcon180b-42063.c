//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUFFER_SIZE 1024

void error(const char* msg) {
    perror(msg);
    exit(1);
}

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        error("socket failed");
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        error("bind failed");
    }

    if (listen(server_socket, 5) == -1) {
        error("listen failed");
    }

    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);
        if (client_socket == -1) {
            error("accept failed");
        }

        char buffer[BUFFER_SIZE];
        memset(buffer, 0, BUFFER_SIZE);

        while (1) {
            int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
            if (bytes_received <= 0) {
                break;
            }

            buffer[bytes_received] = '\0';
            printf("Received: %s\n", buffer);

            strcat(buffer, "Echo: ");
            send(client_socket, buffer, strlen(buffer), 0);
        }

        close(client_socket);
    }

    close(server_socket);
    return 0;
}