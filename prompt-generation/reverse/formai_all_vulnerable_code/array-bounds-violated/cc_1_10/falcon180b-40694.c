//Falcon-180B DATASET v1.0 Category: Chat server ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define BUFFER_SIZE 1024

int main() {
    int server_socket, new_socket;
    struct sockaddr_in server_addr, client_addr;
    int addrlen;
    char buffer[BUFFER_SIZE];
    int bytes_received;

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(5000);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        exit(1);
    }

    if (listen(server_socket, 5) == -1) {
        printf("Error listening on socket\n");
        exit(1);
    }

    printf("Server is listening on port 5000\n");

    while (1) {
        addrlen = sizeof(client_addr);
        new_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addrlen);
        if (new_socket == -1) {
            printf("Error accepting connection\n");
            exit(1);
        }

        printf("New client connected with IP: %s and port: %d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while (1) {
            bytes_received = recv(new_socket, buffer, BUFFER_SIZE, 0);
            if (bytes_received <= 0) {
                printf("Client disconnected\n");
                close(new_socket);
                break;
            }

            buffer[bytes_received] = '\0';
            printf("Message received: %s\n", buffer);

            send(new_socket, buffer, strlen(buffer), 0);
        }
    }

    close(server_socket);
    return 0;
}