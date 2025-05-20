//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: invasive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int server_port = 8080;
    char *server_ip = "127.0.0.1";

    if (argc >= 2) {
        server_ip = argv[1];
    }

    if (argc >= 3) {
        server_port = atoi(argv[2]);
    }

    int server_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (server_socket < 0) {
        perror("Failed to create socket");
        return 1;
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(server_port);
    server_address.sin_addr.s_addr = inet_addr(server_ip);

    if (connect(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("Failed to connect to server");
        return 1;
    }

    int client_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (client_socket < 0) {
        perror("Failed to create socket");
        return 1;
    }

    struct sockaddr_in client_address;
    bzero((char *) &client_address, sizeof(client_address));
    client_address.sin_family = AF_INET;
    client_address.sin_addr.s_addr = INADDR_ANY;
    client_address.sin_port = htons(8081);

    if (bind(client_socket, (struct sockaddr *) &client_address, sizeof(client_address)) < 0) {
        perror("Failed to bind socket");
        return 1;
    }

    listen(client_socket, 1);

    printf("Listening on port %d\n", 8081);

    while (true) {
        int client_connection = accept(client_socket, NULL, NULL);

        if (client_connection < 0) {
            perror("Failed to accept client connection");
            continue;
        }

        printf("Accepted connection\n");

        char buffer[BUFFER_SIZE];
        bzero(buffer, BUFFER_SIZE);

        int n = read(client_connection, buffer, BUFFER_SIZE - 1);

        if (n < 0) {
            perror("Failed to read from socket");
            close(client_connection);
            continue;
        }

        printf("Read %d bytes\n", n);
        printf("Request:\n%s\n", buffer);

        if (write(server_socket, buffer, n) < 0) {
            perror("Failed to write to server socket");
            close(client_connection);
            continue;
        }

        printf("Sent %d bytes to server\n", n);

        while (true) {
            bzero(buffer, BUFFER_SIZE);

            n = read(server_socket, buffer, BUFFER_SIZE - 1);

            if (n < 0) {
                perror("Failed to read from server socket");
                close(client_connection);
                break;
            }

            if (n == 0) {
                printf("Connection closed by server\n");
                break;
            }

            printf("Read %d bytes from server\n", n);
            printf("Response:\n%s\n", buffer);

            if (write(client_connection, buffer, n) < 0) {
                perror("Failed to write to client socket");
                close(client_connection);
                break;
            }

            printf("Sent %d bytes to client\n", n);
        }

        close(client_connection);
    }

    close(client_socket);
    close(server_socket);

    return 0;
}