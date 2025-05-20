//FormAI DATASET v1.0 Category: Socket programming ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int server_socket, client_socket, server_port;
    struct sockaddr_in server_address;
    int address_length = sizeof(server_address);
    char buffer[BUFFER_SIZE] = {0};

    if(argc < 2) {
        fprintf(stderr, "Usage: %s [PORT]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    server_port = atoi(argv[1]);

    if((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation error.");
        exit(EXIT_FAILURE);
    }

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(server_port);

    if(bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Bind failed.");
        exit(EXIT_FAILURE);
    }

    if(listen(server_socket, 3) < 0) {
        perror("Listen failed.");
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d\n", server_port);

    while(1) {
        if((client_socket = accept(server_socket, (struct sockaddr *)&server_address, (socklen_t *)&address_length)) < 0) {
            perror("Accept failed.");
            exit(EXIT_FAILURE);
        }

        printf("New client connected: %s:%d\n", inet_ntoa(server_address.sin_addr), ntohs(server_address.sin_port));

        while(1) {
            memset(buffer, 0, BUFFER_SIZE);

            if(recv(client_socket, buffer, BUFFER_SIZE, 0) <= 0) {
                perror("Receive failed.");
                exit(EXIT_FAILURE);
            }

            if(strncmp(buffer, "exit", 4) == 0) {
                printf("Client disconnected: %s:%d\n", inet_ntoa(server_address.sin_addr), ntohs(server_address.sin_port));
                break;
            }

            printf("Received message from %s:%d: %s", inet_ntoa(server_address.sin_addr), ntohs(server_address.sin_port), buffer);

            if(send(client_socket, buffer, strlen(buffer), 0) < 0) {
                perror("Send failed.");
                exit(EXIT_FAILURE);
            }
        }
    }

    return 0;
}