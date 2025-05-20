//FormAI DATASET v1.0 Category: Networking ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>

#define MAX 1024

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: ./cryptic [port]\n");
        exit(1);
    }

    int port = atoi(argv[1]);

    int server_fd = socket(AF_INET, SOCK_STREAM, 0); // create socket 
    if (server_fd == -1) {
        perror("socket");
        exit(1);
    }

    struct sockaddr_in server_address = {
        .sin_family = AF_INET,
        .sin_addr.s_addr = INADDR_ANY,
        .sin_port = htons(port)
    };

    if (bind(server_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("bind");
        exit(1);
    }

    if (listen(server_fd, 5) < 0) {
        perror("listen");
        exit(1);
    }

    printf("Server listening on port %d...\n", port);

    while (1) {
        struct sockaddr_in address;
        int addrlen = sizeof(address);

        int client_fd = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen);
        if (client_fd < 0) {
            perror("accept");
            exit(1);
        }

        char *remote_address = inet_ntoa(address.sin_addr);
        printf("New client connected from %s:%d\n", remote_address, ntohs(address.sin_port));

        char buffer[MAX] = {0};
        int num_bytes = read(client_fd, buffer, MAX);

        if (num_bytes > 0) {
            printf("Received: %s\n", buffer);

            // perform encryption here
            for (int i = 0; i < strlen(buffer); i++) {
                buffer[i] ^= (i+1); // XOR encryption
            }

            printf("Encrypted: %s\n", buffer);

            // send encrypted message back to client
            if (write(client_fd, buffer, strlen(buffer)) < 0) {
                perror("write");
                close(client_fd);
                continue;
            }

        } else if (num_bytes == 0) {
            printf("Client disconnected.\n");
        } else {
            perror("read");
        }

        close(client_fd);
        printf("Connection closed.\n");
    }

    close(server_fd);
    return 0;
}