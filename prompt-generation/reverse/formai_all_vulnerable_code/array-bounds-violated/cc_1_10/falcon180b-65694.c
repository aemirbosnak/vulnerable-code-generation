//Falcon-180B DATASET v1.0 Category: System administration ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/wait.h>

#define MAX_CLIENTS 10
#define PORT 8080

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        exit(1);
    }

    if (listen(server_socket, MAX_CLIENTS) == -1) {
        printf("Error listening on socket\n");
        exit(1);
    }

    printf("Server listening on port %d\n", PORT);

    int client_socket;
    struct sockaddr_in client_addr;
    socklen_t client_addr_size = sizeof(client_addr);

    while (1) {
        client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &client_addr_size);
        if (client_socket == -1) {
            printf("Error accepting connection\n");
            continue;
        }

        pid_t pid = fork();
        if (pid == -1) {
            printf("Error forking process\n");
            close(client_socket);
            continue;
        } else if (pid == 0) {
            close(server_socket);
            char buffer[1024];
            while (recv(client_socket, buffer, sizeof(buffer), 0) > 0) {
                buffer[recv(client_socket, buffer, sizeof(buffer), 0)] = '\0';
                printf("Client: %s", buffer);
            }
            close(client_socket);
            exit(0);
        } else {
            close(client_socket);
        }
    }

    return 0;
}