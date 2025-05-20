//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    int addr_size;
    char buffer[BUFFER_SIZE];

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <port_number> <IP_address>\n", argv[0]);
        exit(1);
    }

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        fprintf(stderr, "Error creating socket\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[1]));
    inet_pton(AF_INET, argv[2], &server_addr.sin_addr);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        fprintf(stderr, "Error binding socket\n");
        exit(1);
    }

    if (listen(server_socket, 5) == -1) {
        fprintf(stderr, "Error listening on socket\n");
        exit(1);
    }

    while (1) {
        addr_size = sizeof(client_addr);
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addr_size);
        if (client_socket == -1) {
            fprintf(stderr, "Error accepting connection\n");
            exit(1);
        }

        send(client_socket, "Welcome to the surreal world of TCP/IP programming!\n", 56, 0);

        while (1) {
            memset(buffer, 0, BUFFER_SIZE);
            if (recv(client_socket, buffer, BUFFER_SIZE, 0) <= 0) {
                fprintf(stderr, "Error receiving data\n");
                exit(1);
            }

            printf("Client: %s", buffer);

            if (strncmp(buffer, "exit", 5) == 0) {
                send(client_socket, "Goodbye, see you in another dimension!\n", 44, 0);
                close(client_socket);
                break;
            }
        }
    }

    close(server_socket);
    return 0;
}