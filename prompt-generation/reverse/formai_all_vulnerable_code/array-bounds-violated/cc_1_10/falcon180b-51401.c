//Falcon-180B DATASET v1.0 Category: Networking ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024
#define SERVER_PORT 8080

int main() {
    int client_socket;
    int server_socket;
    int bytes_received;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in server_addr;
    struct sockaddr_in client_addr;

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(2);
    }

    if (listen(server_socket, 5) == -1) {
        perror("listen");
        exit(3);
    }

    while (1) {
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, NULL)) == -1) {
            perror("accept");
            exit(4);
        }

        printf("Connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        while ((bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0)) > 0) {
            buffer[bytes_received] = '\0';
            printf("Received message: %s\n", buffer);

            if (send(client_socket, buffer, strlen(buffer), 0) == -1) {
                perror("send");
                exit(5);
            }
        }

        close(client_socket);
    }

    close(server_socket);
    return 0;
}