//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_LINE 1024

#define ERROR -1
#define SUCCESS 0

int main(int argc, char *argv[]) {
    int server_socket, client_socket, addrlen;
    struct sockaddr_in server_addr, client_addr;
    char buffer[MAX_LINE];

    if (argc!= 3) {
        printf("Usage: %s <server_address> <port>\n", argv[0]);
        exit(ERROR);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == ERROR) {
        printf("Error creating socket\n");
        exit(ERROR);
    }

    if (connect(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == ERROR) {
        printf("Error connecting to server\n");
        exit(ERROR);
    }

    printf("Connected to server\n");

    while (1) {
        addrlen = sizeof(client_addr);
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addrlen)) == ERROR) {
            printf("Error accepting connection\n");
            exit(ERROR);
        }

        printf("Connection accepted from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while (1) {
            memset(buffer, 0, MAX_LINE);
            if (recv(client_socket, buffer, MAX_LINE, 0) == 0) {
                printf("Client disconnected\n");
                close(client_socket);
                break;
            }

            if (send(server_socket, buffer, strlen(buffer), 0) == ERROR) {
                printf("Error sending data to server\n");
                exit(ERROR);
            }

            if (recv(server_socket, buffer, MAX_LINE, 0) == 0) {
                printf("Server disconnected\n");
                close(server_socket);
                close(client_socket);
                exit(SUCCESS);
            }

            if (send(client_socket, buffer, strlen(buffer), 0) == ERROR) {
                printf("Error sending data to client\n");
                exit(ERROR);
            }
        }
    }

    close(server_socket);
    exit(SUCCESS);
}