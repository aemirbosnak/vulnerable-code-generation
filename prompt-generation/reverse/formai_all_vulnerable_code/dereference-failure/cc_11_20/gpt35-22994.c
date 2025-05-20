//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdbool.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }

    int port = atoi(argv[1]);

    int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(socket_fd < 0) {
        perror("socket failed");
        exit(1);
    }

    int enable = 1;
    if(setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int)) < 0) {
        perror("setsockopt failed");
        exit(1);
    }

    struct sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_port = htons(port);
    address.sin_addr.s_addr = INADDR_ANY;

    if(bind(socket_fd, (struct sockaddr *) &address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(1);
    }

    if(listen(socket_fd, 128) < 0) {
        perror("listen failed");
        exit(1);
    }

    bool running = true;
    while(running) {
        int client_fd = accept(socket_fd, NULL, NULL);
        if(client_fd < 0) {
            perror("accept failed");
            continue;
        }

        printf("Client connected.\n");

        char buffer[BUFFER_SIZE];
        ssize_t bytes_received;
        ssize_t total_received = 0;
        while((bytes_received = recv(client_fd, buffer + total_received, BUFFER_SIZE - total_received, 0)) > 0) {
            total_received += bytes_received;
            if(total_received >= BUFFER_SIZE) {
                buffer[BUFFER_SIZE - 1] = '\0';
                printf("%s\n", buffer);
                total_received = 0;
            }
        }

        if(bytes_received < 0) {
            perror("recv failed");
            running = false;
        } else {
            buffer[total_received] = '\0';
            printf("%s\n", buffer);
        }

        close(client_fd);
        printf("Client disconnected.\n");
    }

    close(socket_fd);
    printf("Server closed.\n");

    return 0;
}