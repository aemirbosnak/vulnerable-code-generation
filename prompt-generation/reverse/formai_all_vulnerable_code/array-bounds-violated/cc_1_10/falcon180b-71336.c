//Falcon-180B DATASET v1.0 Category: Socket programming ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define TRUE   1
#define FALSE  0
#define PORT   8080
#define BACKLOG 10

int main(int argc, char *argv[]) {
    int listen_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_size;
    char buffer[1024];
    int bytes_received;

    listen_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_socket == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(listen_socket, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        exit(1);
    }

    if (listen(listen_socket, BACKLOG) == -1) {
        printf("Error listening on socket\n");
        exit(1);
    }

    printf("Server is listening on port %d\n", PORT);

    while (TRUE) {
        addr_size = sizeof(client_addr);
        client_socket = accept(listen_socket, (struct sockaddr *) &client_addr, &addr_size);

        if (client_socket == -1) {
            printf("Error accepting connection\n");
            continue;
        }

        printf("Connection accepted from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while (TRUE) {
            bytes_received = recv(client_socket, buffer, 1024, 0);

            if (bytes_received == 0) {
                printf("Client disconnected\n");
                break;
            } else if (bytes_received == -1) {
                printf("Error receiving data\n");
                break;
            }

            buffer[bytes_received] = '\0';
            printf("Received: %s\n", buffer);

            if (send(client_socket, buffer, strlen(buffer), 0) == -1) {
                printf("Error sending data\n");
                break;
            }
        }

        close(client_socket);
    }

    close(listen_socket);
    return 0;
}