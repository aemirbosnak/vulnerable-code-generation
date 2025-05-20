//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT "8080"
#define BACKLOG 10
#define TRUE 1
#define FALSE 0
#define MAX_CLIENTS 5
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int socket_fd, new_socket_fd, addrlen;
    struct sockaddr_in server_addr, client_addr;
    int opt = TRUE;
    int addrlen_client = sizeof(client_addr);
    char buffer[BUFFER_SIZE];
    int max_clients = 0;
    int client_sockets[MAX_CLIENTS];
    char *message = "Welcome to the surrealist TCP/IP server!";

    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(errno);
    }

    if (setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR, (char *)&opt, sizeof(opt))) {
        perror("setsockopt");
        exit(errno);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(atoi(PORT));

    if (bind(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(errno);
    }

    if (listen(socket_fd, BACKLOG) < 0) {
        perror("listen");
        exit(errno);
    }

    printf("Surrealist TCP/IP server is listening on port %s\n", PORT);

    while (TRUE) {
        addrlen = sizeof(client_addr);
        if ((new_socket_fd = accept(socket_fd, (struct sockaddr *)&client_addr, (socklen_t*)&addrlen_client)) < 0) {
            perror("accept");
            exit(errno);
        }

        for (int i = 0; i < max_clients; i++) {
            if (client_sockets[i] == 0) {
                client_sockets[i] = new_socket_fd;
                max_clients++;
                break;
            }
        }

        if (max_clients >= MAX_CLIENTS) {
            send(new_socket_fd, "Server is full. Please try again later.", strlen("Server is full. Please try again later."), 0);
            close(new_socket_fd);
        } else {
            send(new_socket_fd, message, strlen(message), 0);
        }
    }

    return 0;
}