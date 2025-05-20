//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define TRUE 1
#define FALSE 0
#define PORT 8080
#define MAX 100
#define SA struct sockaddr

int main(int argc, char *argv[]) {
    int listen_socket, client_socket, bytes_received, client_len, opt = TRUE;
    char buffer[MAX];
    struct sockaddr_in server_addr, client_addr;

    listen_socket = socket(AF_INET, SOCK_STREAM, 0);

    if (listen_socket == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    if (setsockopt(listen_socket, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt))) {
        printf("Error setting socket option\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(listen_socket, (SA *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        exit(1);
    }

    if (listen(listen_socket, 5) == -1) {
        printf("Error listening on socket\n");
        exit(1);
    }

    while (TRUE) {
        client_len = sizeof(client_addr);
        client_socket = accept(listen_socket, (SA *)&client_addr, &client_len);

        if (client_socket == -1) {
            printf("Error accepting connection\n");
            exit(1);
        }

        printf("Connection accepted\n");

        while (TRUE) {
            bytes_received = recv(client_socket, buffer, MAX, 0);

            if (bytes_received <= 0) {
                printf("Client disconnected\n");
                break;
            }

            buffer[bytes_received] = '\0';
            printf("Received: %s\n", buffer);

            if (send(client_socket, buffer, strlen(buffer), 0) == -1) {
                printf("Error sending data\n");
                exit(1);
            }
        }

        close(client_socket);
    }

    close(listen_socket);
    return 0;
}