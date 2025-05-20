//FormAI DATASET v1.0 Category: Networking ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080
#define MAX_CLIENTS 10

int main() {
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[1024] = {0};
    fd_set active_fd_set, read_fd_set;
    int client_socket[MAX_CLIENTS] = {0};
    int max_clients = MAX_CLIENTS;

    // initialize active file descriptor set
    FD_ZERO(&active_fd_set);

    // create a socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE); 
    }

    // set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("Failed to set socket options");
        exit(EXIT_FAILURE);
    }

    // initialize server address
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // bind socket to address and port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Failed to bind socket");
        exit(EXIT_FAILURE);
    }

    // start listening for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("Failed to start listening");
        exit(EXIT_FAILURE);
    }

    // add server socket to active file descriptor set
    FD_SET(server_fd, &active_fd_set);

    while (1) {
        // copy active file descriptor set to read file descriptor set
        read_fd_set = active_fd_set;

        // wait for activity on any of the sockets
        if (select(FD_SETSIZE, &read_fd_set, NULL, NULL, NULL) < 0) {
            perror("Error in select");
            exit(EXIT_FAILURE);
        }

        // loop through all possible file descriptors
        for (int fd = 0; fd < FD_SETSIZE; fd++) {
            // check if current file descriptor is active
            if (FD_ISSET(fd, &read_fd_set)) {
                if (fd == server_fd) {
                    // new client connection
                    if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
                        perror("Error in accept");
                        exit(EXIT_FAILURE);
                    }

                    // add new client socket to active file descriptor set
                    FD_SET(new_socket, &active_fd_set);

                    // display new connection information
                    printf("New connection from %s:%d, socket fd is %d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port), new_socket);
                } else {
                    // existing client message
                    valread = read(fd, buffer, 1024);

                    if (valread <= 0) {
                        // client disconnected
                        close(fd);
                        FD_CLR(fd, &active_fd_set);
                        client_socket[fd] = 0;
                        printf("Client %d disconnected\n", fd);
                    } else {
                        // display received message
                        printf("Message from client %d: %s\n", fd, buffer);

                        // broadcast message to all connected clients
                        for (int i = 0; i < max_clients; i++) {
                            if (fd != i && client_socket[i] > 0) {
                                send(i, buffer, strlen(buffer), 0);
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}