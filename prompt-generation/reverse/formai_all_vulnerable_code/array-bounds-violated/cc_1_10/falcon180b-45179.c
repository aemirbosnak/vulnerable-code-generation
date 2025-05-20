//Falcon-180B DATASET v1.0 Category: Simple Web Server ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <errno.h>

#define BUFFERSIZE 1024

int main(int argc, char *argv[]) {
    int listen_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFERSIZE];

    listen_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_socket == -1) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);

    if (bind(listen_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(listen_socket, 5) == -1) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port 8080\n");

    while (1) {
        memset(buffer, 0, BUFFERSIZE);
        socklen_t client_size = sizeof(client_addr);
        client_socket = accept(listen_socket, (struct sockaddr *)&client_addr, &client_size);

        if (client_socket == -1) {
            perror("accept failed");
            continue;
        }

        printf("New connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while (1) {
            bzero(buffer, BUFFERSIZE);
            int bytes_received = recv(client_socket, buffer, BUFFERSIZE, 0);

            if (bytes_received <= 0) {
                if (bytes_received == 0) {
                    printf("Client disconnected\n");
                } else {
                    perror("recv failed");
                }
                break;
            }

            buffer[bytes_received] = '\0';
            printf("Received message: %s\n", buffer);

            send(client_socket, buffer, strlen(buffer), 0);
        }

        close(client_socket);
    }

    close(listen_socket);
    return 0;
}