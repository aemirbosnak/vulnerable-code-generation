//FormAI DATASET v1.0 Category: Chat server ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/select.h>
#define MAX_BUFFER_SIZE 1024

int main(int argc, char **argv) {
    printf("Hi! Welcome to my happy chat server program!\n");
    printf("Let's spread some happiness through chatting and connecting with each other!\n");
    printf("Starting up the server...\n");

    // Create the initial socket
    int server_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket_fd == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        return 1;
    }

    // Bind the socket to the local address and port
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(9000);
    server_address.sin_addr.s_addr = INADDR_ANY;
    int bind_result = bind(server_socket_fd, (struct sockaddr *) &server_address, sizeof(server_address));
    if (bind_result == -1) {
        printf("Error binding socket: %s\n", strerror(errno));
        close(server_socket_fd);
        return 1;
    }

    // Start listening for incoming connections
    const int BACKLOG = 5;
    int listen_result = listen(server_socket_fd, BACKLOG);
    if (listen_result == -1) {
        printf("Error listening for incoming connections: %s\n", strerror(errno));
        close(server_socket_fd);
        return 1;
    }

    // Set up a set of file descriptors to monitor with select()
    fd_set active_fd_set, read_fd_set;
    FD_ZERO(&active_fd_set);
    FD_SET(server_socket_fd, &active_fd_set);
    printf("Ready to receive connections!\n");

    while (1) {
        read_fd_set = active_fd_set;
        if (select(FD_SETSIZE, &read_fd_set, NULL, NULL, NULL) < 0) {
            printf("Error with select(): %s\n", strerror(errno));
            break;
        }

        // Service all the sockets with incoming messages
        for (int i = 0; i < FD_SETSIZE; i++) {
            if (!FD_ISSET(i, &read_fd_set)) {
                continue;
            }

            if (i == server_socket_fd) {
                // New client connection
                struct sockaddr_in client_address;
                socklen_t client_address_len = sizeof(client_address);
                int new_client_socket = accept(server_socket_fd, (struct sockaddr *) &client_address, &client_address_len);
                if (new_client_socket < 0) {
                    printf("Error with accept(): %s\n", strerror(errno));
                    continue;
                }

                FD_SET(new_client_socket, &active_fd_set);
                printf("New connection from %s:%d on socket %d\n", inet_ntoa(client_address.sin_addr),
                    ntohs(client_address.sin_port), new_client_socket);
            } else {
                // Incoming message from an existing client socket
                char buffer[MAX_BUFFER_SIZE];
                ssize_t recv_result = recv(i, buffer, MAX_BUFFER_SIZE, 0);
                if (recv_result == 0) {
                    // Client disconnected
                    printf("Client on socket %d disconnected.\n", i);
                    close(i);
                    FD_CLR(i, &active_fd_set);
                } else if (recv_result < 0) {
                    // Error receiving message from client
                    printf("Error receiving message from client on socket %d: %s\n", i, strerror(errno));
                } else {
                    // Echo the incoming message to all connected clients
                    for (int j = 0; j < FD_SETSIZE; j++) {
                        if (FD_ISSET(j, &active_fd_set) && j != server_socket_fd && j != i) {
                            ssize_t send_result = send(j, buffer, recv_result, 0);
                            if (send_result == -1) {
                                printf("Error sending message to client on socket %d: %s\n", j, strerror(errno));
                            }
                        }
                    }
                }
            }
        }
    }

    printf("Shutting down the server...\n");
    close(server_socket_fd);
    return 0;
}