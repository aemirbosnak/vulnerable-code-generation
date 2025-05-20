//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define PORT 21
#define MAX_CONNECTIONS 10

int main() {
    int master_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (master_socket == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(master_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    while (1) {
        int client_socket = accept(master_socket, NULL, NULL);
        if (client_socket == -1) {
            printf("Error accepting client\n");
            exit(1);
        }

        printf("Client connected\n");

        char buffer[BUFFER_SIZE];
        int bytes_received = 0;

        while (1) {
            int bytes_read = recv(client_socket, buffer + bytes_received, BUFFER_SIZE - bytes_received, 0);
            if (bytes_read == 0) {
                printf("Client disconnected\n");
                close(client_socket);
                break;
            } else if (bytes_read == -1) {
                printf("Error receiving data\n");
                close(client_socket);
                break;
            }

            bytes_received += bytes_read;

            if (bytes_received >= BUFFER_SIZE) {
                printf("Data received: %s\n", buffer);
                bytes_received = 0;
            }
        }
    }

    close(master_socket);
    return 0;
}