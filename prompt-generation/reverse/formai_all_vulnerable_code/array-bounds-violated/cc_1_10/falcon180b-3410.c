//Falcon-180B DATASET v1.0 Category: Chat server ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define TRUE 1
#define FALSE 0
#define PORT 8080
#define BACKLOG 10

int main(int argc, char *argv[]) {
    int listen_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    int addrlen = sizeof(client_addr);
    char buffer[1024];
    int bytes_received;

    if ((listen_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT);

    if (bind(listen_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error binding socket\n");
        exit(2);
    }

    if (listen(listen_socket, BACKLOG) < 0) {
        printf("Error listening on socket\n");
        exit(3);
    }

    printf("Server is listening on port %d\n", PORT);

    while (TRUE) {
        if ((client_socket = accept(listen_socket, (struct sockaddr *)&client_addr, &addrlen)) < 0) {
            printf("Error accepting connection\n");
            exit(4);
        }

        printf("Client connected with IP address %s and port %d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while (TRUE) {
            if ((bytes_received = recv(client_socket, buffer, sizeof(buffer), 0)) <= 0) {
                printf("Error receiving data or client disconnected\n");
                close(client_socket);
                break;
            }

            buffer[bytes_received] = '\0';
            printf("Received message: %s\n", buffer);

            if (send(client_socket, buffer, strlen(buffer), 0) < 0) {
                printf("Error sending data\n");
                close(client_socket);
                break;
            }
        }
    }

    close(listen_socket);
    return 0;
}