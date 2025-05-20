//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>

#define BUF_SIZE 1024
#define PORT 8080
#define BACKLOG 5

int main(int argc, char *argv[]) {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    int addrlen = sizeof(client_addr);
    char buffer[BUF_SIZE];
    int bytes_received;
    int pid;
    int status;

    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        printf("Socket creation failed\n");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Bind failed\n");
        return 2;
    }

    if (listen(server_socket, BACKLOG) < 0) {
        printf("Listen failed\n");
        return 3;
    }

    while (1) {
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, (socklen_t*)&addrlen)) < 0) {
            printf("Accept failed\n");
            return 4;
        }

        pid = fork();

        if (pid == 0) {
            close(server_socket);
            while (1) {
                bytes_received = recv(client_socket, buffer, BUF_SIZE, 0);

                if (bytes_received <= 0) {
                    break;
                }

                buffer[bytes_received] = '\0';
                printf("Client message: %s\n", buffer);

                send(client_socket, buffer, strlen(buffer), 0);
            }

            close(client_socket);
            exit(0);
        }

        close(client_socket);
    }

    return 0;
}