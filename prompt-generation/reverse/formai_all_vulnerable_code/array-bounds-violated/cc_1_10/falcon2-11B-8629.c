//Falcon2-11B DATASET v1.0 Category: Client Server Application ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

#define PORT 5000

void handle_client(int client_socket) {
    char buf[1024];
    while (1) {
        bzero(buf, sizeof(buf));
        ssize_t n = recv(client_socket, buf, sizeof(buf) - 1, 0);
        if (n <= 0) {
            printf("Client disconnected.\n");
            break;
        }
        buf[n] = '\0';
        printf("Received: %s\n", buf);
        send(client_socket, buf, strlen(buf), 0);
    }
}

int main(int argc, char *argv[]) {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    int addrlen = sizeof(client_addr);

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Server socket error");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind error");
        exit(1);
    }

    if (listen(server_socket, 3) < 0) {
        perror("Listen error");
        exit(1);
    }

    if ((client_socket = accept(server_socket, (struct sockaddr *)&client_addr, &addrlen)) < 0) {
        perror("Accept error");
        exit(1);
    }

    handle_client(client_socket);

    close(client_socket);

    return 0;
}