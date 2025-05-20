//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: future-proof
/*
 * A simple TCP/IP server program that can handle multiple client connections using epoll
 *
 * Author: John Doe
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <sys/epoll.h>

#define MAX_EVENTS 10
#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int server_fd, client_fd, epoll_fd, event_count;
    struct epoll_event event, events[MAX_EVENTS];
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_len = sizeof(client_address);
    char buffer[MAX_BUFFER_SIZE];

    // Create the server socket
    server_fd = socket(AF_INET, SOCK_STREAM | SOCK_NONBLOCK, 0);
    if (server_fd == -1) {
        perror("Unable to create server socket");
        exit(EXIT_FAILURE);
    }

    // Bind the socket to a specific IP address and port
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(8080);
    if (bind(server_fd, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("Unable to bind server socket");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, SOMAXCONN) == -1) {
        perror("Unable to listen for incoming connections");
        exit(EXIT_FAILURE);
    }

    // Create the epoll file descriptor
    epoll_fd = epoll_create1(0);
    if (epoll_fd == -1) {
        perror("Unable to create epoll file descriptor");
        exit(EXIT_FAILURE);
    }

    // Add the server socket to the epoll event list
    event.data.fd = server_fd;
    event.events = EPOLLIN | EPOLLET;
    if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, server_fd, &event) == -1) {
        perror("Unable to add server socket to epoll event list");
        exit(EXIT_FAILURE);
    }

    // Handle incoming client connections
    while (1) {
        event_count = epoll_wait(epoll_fd, events, MAX_EVENTS, -1);
        if (event_count == -1) {
            perror("Error waiting for epoll events");
            exit(EXIT_FAILURE);
        }

        for (int i = 0; i < event_count; i++) {
            if (events[i].data.fd == server_fd) {
                // Accept incoming client connection
                client_fd = accept4(server_fd, (struct sockaddr *)&client_address, &client_address_len, SOCK_NONBLOCK);
                if (client_fd == -1) {
                    if (errno != EAGAIN && errno != EWOULDBLOCK) {
                        perror("Unable to accept incoming client connection");
                        exit(EXIT_FAILURE);
                    }
                } else {
                    // Add the client socket to the epoll event list
                    event.data.fd = client_fd;
                    event.events = EPOLLIN | EPOLLET;
                    if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, client_fd, &event) == -1) {
                        perror("Unable to add client socket to epoll event list");
                        exit(EXIT_FAILURE);
                    }
                }
            } else {
                // Handle incoming data from connected client
                int bytes_received = recv(events[i].data.fd, buffer, MAX_BUFFER_SIZE, 0);
                if (bytes_received == -1) {
                    if (errno != EAGAIN && errno != EWOULDBLOCK) {
                        perror("Error receiving data from client");
                        exit(EXIT_FAILURE);
                    }
                } else if (bytes_received == 0) {
                    // Client has disconnected
                    if (epoll_ctl(epoll_fd, EPOLL_CTL_DEL, events[i].data.fd, NULL) == -1) {
                        perror("Unable to delete client socket from epoll event list");
                        exit(EXIT_FAILURE);
                    }
                    close(events[i].data.fd);
                    printf("Client disconnected\n");
                } else {
                    buffer[bytes_received] = '\0';
                    printf("Received from client: %s\n", buffer);
                    // Echo data back to client
                    if (send(events[i].data.fd, buffer, bytes_received, 0) == -1) {
                        perror("Error sending data to client");
                        exit(EXIT_FAILURE);
                    }
                }
            }
        }
    }

    close(server_fd);
    return EXIT_SUCCESS;
}