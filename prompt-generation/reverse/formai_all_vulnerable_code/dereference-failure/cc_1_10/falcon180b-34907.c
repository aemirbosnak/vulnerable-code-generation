//Falcon-180B DATASET v1.0 Category: Firewall ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

char* get_ip(int sockfd) {
    struct sockaddr_in their_addr;
    socklen_t addr_size = sizeof(their_addr);
    getsockname(sockfd, (struct sockaddr*)&their_addr, &addr_size);
    char* ip = inet_ntoa(their_addr.sin_addr);
    return ip;
}

void handle_client(int client_socket) {
    char buffer[BUFFER_SIZE];
    while (1) {
        bzero(buffer, BUFFER_SIZE);
        int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            break;
        }
        printf("Client sent: %s\n", buffer);
    }
    close(client_socket);
}

int main() {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("socket");
        exit(errno);
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(8080);

    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(errno);
    }

    if (listen(server_socket, 5) == -1) {
        perror("listen");
        exit(errno);
    }

    printf("Server is running on port 8080\n");

    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);
        if (client_socket == -1) {
            perror("accept");
            exit(errno);
        }

        char* ip = get_ip(client_socket);
        printf("Client connected: %s\n", ip);

        pid_t pid = fork();
        if (pid == -1) {
            perror("fork");
            exit(errno);
        } else if (pid == 0) {
            handle_client(client_socket);
            exit(0);
        } else {
            close(client_socket);
        }
    }

    return 0;
}