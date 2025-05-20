//Falcon-180B DATASET v1.0 Category: Client Server Application ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define BUFFER_SIZE 1024

int main(int argc, char **argv) {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];

    if (argc!= 3) {
        printf("Usage:./server <IP address> <port number>\n");
        exit(1);
    }

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_port = htons(atoi(argv[2]));

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        exit(1);
    }

    if (listen(server_socket, 10) == -1) {
        printf("Error listening on socket\n");
        exit(1);
    }

    printf("Server is listening on %s:%d\n", argv[1], atoi(argv[2]));

    while (1) {
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, sizeof(client_addr));
        if (client_socket == -1) {
            printf("Error accepting connection\n");
            exit(1);
        }

        printf("Connection accepted from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while (1) {
            memset(buffer, 0, BUFFER_SIZE);
            ssize_t bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
            if (bytes_received == 0) {
                printf("Client disconnected\n");
                close(client_socket);
                break;
            }

            if (bytes_received == -1) {
                printf("Error receiving data\n");
                exit(1);
            }

            printf("Received message: %s\n", buffer);

            ssize_t bytes_sent = send(client_socket, buffer, bytes_received, 0);
            if (bytes_sent == -1) {
                printf("Error sending data\n");
                exit(1);
            }
        }
    }

    close(server_socket);
    return 0;
}