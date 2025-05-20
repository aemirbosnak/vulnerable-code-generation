//Falcon-180B DATASET v1.0 Category: Chat server ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

#define PORT 8080
#define BACKLOG 10
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int opt = 1;
    int server_socket;
    struct sockaddr_in server_addr;
    int addrlen = sizeof(server_addr);
    char buffer[BUFFER_SIZE];
    int client_socket;
    int clientlen = sizeof(struct sockaddr_in);
    int count = 0;

    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, BACKLOG) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d\n", PORT);

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        if ((client_socket = accept(server_socket, (struct sockaddr *)&server_addr, (socklen_t*)&addrlen)) < 0) {
            perror("accept");
            exit(EXIT_FAILURE);
        }
        printf("Client connected\n");

        while (1) {
            count = recv(client_socket, buffer, BUFFER_SIZE, 0);
            if (count <= 0) {
                printf("Client disconnected\n");
                close(client_socket);
                break;
            }
            buffer[count] = '\0';
            printf("Message received: %s\n", buffer);

            send(client_socket, buffer, strlen(buffer), 0);
        }
    }

    close(server_socket);
    return 0;
}