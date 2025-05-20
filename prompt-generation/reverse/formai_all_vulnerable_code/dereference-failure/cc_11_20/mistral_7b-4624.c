//MISTRAL-7B DATASET v1.0 Category: Chat server ; Style: real-life
#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define MAX_CLIENTS 10

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};

    // Initialize server socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set options on server socket
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt,
                   sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    // Configure server address
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind server socket to address
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server started on port %d\n", PORT);

    fd_set master_fds, read_fds;
    FD_ZERO(&master_fds);
    FD_ZERO(&read_fds);

    FD_SET(server_fd, &master_fds);

    while (true) {
        read_fds = master_fds;

        if (select(FD_SETSIZE, &read_fds, NULL, NULL, NULL) < 0) {
            perror("select");
            exit(EXIT_FAILURE);
        }

        for (int i = 0; i < FD_SETSIZE; ++i) {
            if (FD_ISSET(i, &read_fds)) {
                if (i == server_fd) {
                    // Accept new connection
                    if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
                                            &addrlen)) < 0) {
                        perror("accept");
                        exit(EXIT_FAILURE);
                    }

                    printf("New connection from %s:%d\n",
                           inet_ntoa(address.sin_addr), ntohs(address.sin_port));

                    FD_SET(new_socket, &master_fds);
                    printf("Added new socket %d to master set\n", new_socket);
                } else {
                    // Handle data from client
                    int client_fd = i;
                    memset(buffer, 0, BUFFER_SIZE);

                    int bytes_received = recv(client_fd, buffer, BUFFER_SIZE, 0);
                    if (bytes_received <= 0) {
                        // Connection closed or error
                        close(client_fd);
                        FD_CLR(client_fd, &master_fds);
                        printf("Connection %d closed\n", client_fd);
                    } else {
                        // Send message to all clients except the sender
                        for (int j = 0; j < FD_SETSIZE; ++j) {
                            if (FD_ISSET(j, &master_fds) && j != client_fd) {
                                send(j, buffer, bytes_received, 0);
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}