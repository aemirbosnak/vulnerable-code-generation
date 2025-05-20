//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUF_SIZE 2048
#define SERVER_PORT 8080
#define SERVER_IP "127.0.0.1"

int main(int argc, char **argv) {
    int server_socket;
    struct sockaddr_in server_addr;
    int client_socket;
    struct sockaddr_in client_addr;
    char buffer[BUF_SIZE];
    int bytes_received;
    int bytes_sent;

    if (argc!= 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[1]));
    server_addr.sin_addr.s_addr = inet_addr(SERVER_IP);

    if (connect(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    while (1) {
        bytes_received = recv(server_socket, buffer, BUF_SIZE, 0);
        if (bytes_received <= 0) {
            printf("Error receiving data from server\n");
            exit(1);
        }

        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, sizeof(client_addr));
        if (client_socket == -1) {
            printf("Error accepting client connection\n");
            exit(1);
        }

        while (1) {
            bytes_received = recv(client_socket, buffer, BUF_SIZE, 0);
            if (bytes_received <= 0) {
                printf("Error receiving data from client\n");
                exit(1);
            }

            bytes_sent = send(server_socket, buffer, bytes_received, 0);
            if (bytes_sent <= 0) {
                printf("Error sending data to server\n");
                exit(1);
            }

            bytes_sent = send(client_socket, buffer, bytes_received, 0);
            if (bytes_sent <= 0) {
                printf("Error sending data to client\n");
                exit(1);
            }
        }

        close(client_socket);
    }

    close(server_socket);
    return 0;
}