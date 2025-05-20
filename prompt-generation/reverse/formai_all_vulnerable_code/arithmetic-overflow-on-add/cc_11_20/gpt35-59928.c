//FormAI DATASET v1.0 Category: Chat server ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define SERVER_PORT 8080
#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

typedef struct {
    int socket;
    char name[20];
} client;

int main() {
    int socket_fd, client_socket_fd, max_fd, activity, i, valread, sd;
    int opt = 1;
    struct sockaddr_in server_address;
    fd_set read_fds;
    char buffer[BUFFER_SIZE];
    client clients[MAX_CLIENTS] = {0};

    // create server socket
    socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (socket_fd == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // set socket options
    if (setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt)) == -1) {
        perror("Setsockopt failed");
        exit(EXIT_FAILURE);
    }

    // set server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(SERVER_PORT);

    // bind socket to server address
    if (bind(socket_fd, (struct sockaddr*)&server_address, sizeof(server_address)) == -1) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // listen for incoming connections
    if (listen(socket_fd, MAX_CLIENTS) == -1) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    // initialize file descriptor set
    FD_ZERO(&read_fds);
    FD_SET(socket_fd, &read_fds);
    max_fd = socket_fd;

    while (1) {
        // select active file descriptors
        activity = select(max_fd + 1, &read_fds, NULL, NULL, NULL);
        if (activity < 0) {
            perror("Select failed");
            exit(EXIT_FAILURE);
        }

        // handle new incoming connection
        if (FD_ISSET(socket_fd, &read_fds)) {
            client_socket_fd = accept(socket_fd, (struct sockaddr*)NULL, NULL);
            if (client_socket_fd == -1) {
                perror("Accept failed");
                exit(EXIT_FAILURE);
            }

            // add new client to list of clients
            for (i = 0; i < MAX_CLIENTS; i++) {
                if (clients[i].socket == 0) {
                    clients[i].socket = client_socket_fd;
                    printf("New client connected\n");
                    break;
                }
            }

            // add new client socket to file descriptor set
            FD_SET(client_socket_fd, &read_fds);

            // update maximum file descriptor
            if (client_socket_fd > max_fd) {
                max_fd = client_socket_fd;
            }
        }

        // handle incoming data from clients
        for (i = 0; i < MAX_CLIENTS; i++) {
            sd = clients[i].socket;
            if (FD_ISSET(sd, &read_fds)) {
                valread = read(sd, buffer, BUFFER_SIZE);
                if (valread == 0) {
                    // client disconnected
                    close(sd);
                    FD_CLR(sd, &read_fds);
                    clients[i].socket = 0;
                    printf("Client disconnected\n");
                } else {
                    // broadcast message to all other clients
                    for (int j = 0; j < MAX_CLIENTS; j++) {
                        if (clients[j].socket != 0 && clients[j].socket != sd) {
                            char message[BUFFER_SIZE];
                            sprintf(message, "%s: %s", clients[i].name, buffer);
                            send(clients[j].socket, message, strlen(message), 0);
                        }
                    }

                    // save client name if it's the first message received
                    if (strlen(clients[i].name) == 0) {
                        strncpy(clients[i].name, buffer, sizeof(clients[i].name));
                        printf("New client name: %s\n", clients[i].name);
                    }
                }
            }
        }
    }

    return 0;
}