//FormAI DATASET v1.0 Category: Networking ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int server_fd, new_socket, val_read, client_socket[30], max_clients = 30, activity, addrlen, sd;
    struct sockaddr_in address;
    char buffer[BUFFER_SIZE];
    fd_set read_fds;

    // create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // set server address
    memset(&address, 0, sizeof(address));
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // bind socket to address and port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // listen for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    // accept incoming connections
    addrlen = sizeof(address);
    puts("Waiting for connections...");
    while (1) {
        FD_ZERO(&read_fds);
        FD_SET(server_fd, &read_fds);

        for (int i = 0; i < max_clients; i++) {
            sd = client_socket[i];

            if (sd > 0) {
                FD_SET(sd, &read_fds);
            }
        }

        // wait for activity on sockets
        activity = select(max_clients + 1, &read_fds, NULL, NULL, NULL);

        // handle incoming connection request
        if (FD_ISSET(server_fd, &read_fds)) {
            if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t *)&addrlen)) < 0) {
                perror("accept failed");
                exit(EXIT_FAILURE);
            }

            // add new socket to list of sockets
            for (int i = 0; i < max_clients; i++) {
                if (client_socket[i] == 0) {
                    client_socket[i] = new_socket;
                    printf("New client connected, socket fd is %d, IP is %s, PORT is %d\n", new_socket, inet_ntoa(address.sin_addr), ntohs(address.sin_port));
                    break;
                }
            }
        }

        // handle incoming messages
        for (int i = 0; i < max_clients; i++) {
            sd = client_socket[i];

            if (FD_ISSET(sd, &read_fds)) {
                if ((val_read = read(sd, buffer, BUFFER_SIZE)) == 0) {
                    // client disconnected
                    getpeername(sd, (struct sockaddr *)&address, (socklen_t *)&addrlen);
                    printf("Client disconnected, IP is %s, PORT is %d\n", inet_ntoa(address.sin_addr), ntohs(address.sin_port));
                    close(sd);
                    client_socket[i] = 0;
                } else {
                    // process incoming message
                    buffer[val_read] = '\0';
                    printf("Message from client: %s\n", buffer);
                    send(sd, buffer, strlen(buffer), 0);
                }
            }
        }
    }

    return 0;
}