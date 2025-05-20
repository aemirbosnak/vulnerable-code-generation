//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];
    int addrlen;

    if (argc!= 3) {
        printf("Usage:./proxy_server <server_ip> <server_port>\n");
        return 1;
    }

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Error creating socket.\n");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    if (connect(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server.\n");
        close(server_socket);
        return 1;
    }

    while (1) {
        addrlen = sizeof(client_addr);
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addrlen);
        if (client_socket == -1) {
            printf("Error accepting connection.\n");
            close(client_socket);
            continue;
        }

        printf("Connection accepted from: %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while (1) {
            memset(buffer, 0, BUFFER_SIZE);
            int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
            if (bytes_received <= 0) {
                printf("Client disconnected.\n");
                close(client_socket);
                break;
            }

            int bytes_sent = send(server_socket, buffer, bytes_received, 0);
            if (bytes_sent <= 0) {
                printf("Server disconnected.\n");
                close(server_socket);
                close(client_socket);
                break;
            }
        }
    }

    close(server_socket);
    return 0;
}