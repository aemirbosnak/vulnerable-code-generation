//FormAI DATASET v1.0 Category: Socket programming ; Style: retro
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080
#define MAX_CONNECTIONS 5

int main(int argc, char const *argv[]) {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Error in creating socket\n");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    server_address.sin_addr.s_addr = INADDR_ANY;

    int bind_status = bind(server_socket, (struct sockaddr *)&server_address , sizeof(server_address));
    if (bind_status == -1) {
        perror("Error in binding socket\n");
        exit(EXIT_FAILURE);
    }

    listen(server_socket, MAX_CONNECTIONS);

    fd_set reader_set;
    FD_ZERO(&reader_set);
    FD_SET(server_socket, &reader_set);

    while (true) {
        fd_set active_set = reader_set;
        if (select(FD_SETSIZE, &active_set, NULL, NULL, NULL) < 0) {
            perror("Error in selecting\n");
            exit(EXIT_FAILURE);
        }

        for (int i = 0; i < FD_SETSIZE; i++) {
            if (FD_ISSET(i, &active_set)) {
                if (i == server_socket) {
                    struct sockaddr_in client_address;
                    socklen_t address_length = sizeof(client_address);
                    int client_socket = accept(server_socket, (struct sockaddr *)&client_address, &address_length);
                    if (client_socket == -1) {
                        perror("Error in accepting client\n");
                        exit(EXIT_FAILURE);
                    }
                    printf("New client connected\n");
                    FD_SET(client_socket, &reader_set);
                } else {
                    char buffer[1024];
                    int read_status = read(i, buffer, 1024);
                    if (read_status == -1) {
                        perror("Error in reading client message\n");
                        exit(EXIT_FAILURE);
                    } else if (read_status == 0) {
                        close(i);
                        FD_CLR(i, &reader_set);
                        printf("Client disconnected\n");
                    } else {
                        buffer[read_status] = '\0';
                        printf("Received message: %s\n", buffer);
                        write(i, buffer, strlen(buffer));
                    }
                }
            }
        }
    }

    close(server_socket);
    return 0;
}