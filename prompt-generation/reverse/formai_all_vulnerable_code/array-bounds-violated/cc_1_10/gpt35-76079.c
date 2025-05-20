//FormAI DATASET v1.0 Category: Networking ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 8000
#define BUFFER_SIZE 1024

int main() {
    int sock_fd, new_fd, client_len;
    struct sockaddr_in server_addr, client_addr;
    // create socket
    if ((sock_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }
    // set server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;
    // bind socket to address
    if (bind(sock_fd, (struct sockaddr*) &server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }
    // listen on socket
    if (listen(sock_fd, 10) == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    printf("Waiting for client...\n");
    // accept incoming connection
    client_len = sizeof(client_addr);
    if ((new_fd = accept(sock_fd, (struct sockaddr*) &client_addr, &client_len)) == -1) {
        perror("accept");
        exit(EXIT_FAILURE);
    }
    printf("Client connected: %d\n", new_fd);
    while (1) {
        char buffer[BUFFER_SIZE];
        int num_bytes = recv(new_fd, buffer, BUFFER_SIZE, 0);
        if (num_bytes == -1) {
            perror("recv");
            exit(EXIT_FAILURE);
        }
        if (num_bytes == 0) {
            printf("Client disconnected: %d\n", new_fd);
            break;
        }
        buffer[num_bytes] = '\0';
        printf("Message received from client: %s\n", buffer);
        if (send(new_fd, buffer, strlen(buffer), 0) == -1) {
            perror("send");
            exit(EXIT_FAILURE);
        }
    }
    // close sockets
    close(new_fd);
    close(sock_fd);
    return 0;
}