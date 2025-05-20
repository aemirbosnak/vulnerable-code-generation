//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

void surreal_socket_program() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Surreal error: Could not create socket.\n");
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(8080);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Surreal error: Could not bind socket.\n");
        exit(1);
    }

    if (listen(server_socket, 5) == -1) {
        printf("Surreal error: Could not listen on socket.\n");
        exit(1);
    }

    char surreal_buffer[BUFFER_SIZE];
    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);
        if (client_socket == -1) {
            printf("Surreal error: Could not accept connection.\n");
            continue;
        }

        printf("Surreal connection accepted.\n");

        while (1) {
            memset(surreal_buffer, 0, BUFFER_SIZE);
            int bytes_received = recv(client_socket, surreal_buffer, BUFFER_SIZE, 0);
            if (bytes_received <= 0) {
                printf("Surreal error: Could not receive data.\n");
                break;
            }

            surreal_buffer[bytes_received] = '\0';
            printf("Surreal data received: %s\n", surreal_buffer);

            send(client_socket, surreal_buffer, strlen(surreal_buffer), 0);
        }

        close(client_socket);
    }

    close(server_socket);
}

int main() {
    surreal_socket_program();
    return 0;
}