//FormAI DATASET v1.0 Category: Client Server Application ; Style: intelligent
/* A chat application using client-server architecture */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT_NUMBER     5000
#define MAX_CONNECTIONS 100
#define BUFFER_SIZE     1024

int main(int argc, char **argv) {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_len;
    char buffer[BUFFER_SIZE];
    int max_sd, activity, new_socket, i, sd;
    int client_sockets[MAX_CONNECTIONS] = {0};

    // Create socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    // Set server address properties
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT_NUMBER);

    // Bind socket to server address
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Failed to bind socket to server address");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_socket, MAX_CONNECTIONS) < 0) {
        perror("Failed to listen for incoming connections");
        exit(EXIT_FAILURE);
    }

    // Accept incoming connections and add to client sockets array
    client_address_len = sizeof(client_address);
    puts("Waiting for connections...");
    while (1) {
        fd_set read_fds;

        // Clear set
        FD_ZERO(&read_fds);

        // Add server socket to set
        FD_SET(server_socket, &read_fds);
        max_sd = server_socket;

        // Add client sockets to set
        for (i = 0; i < MAX_CONNECTIONS; i++) {
            sd = client_sockets[i];

            // If valid socket descriptor then add to read list
            if (sd > 0) {
                FD_SET(sd, &read_fds);
            }

            // Determine highest file descriptor number
            if (sd > max_sd) {
                max_sd = sd;
            }
        }

        // Wait for activity on one of the sockets
        activity = select(max_sd + 1, &read_fds, NULL, NULL, NULL);

        if ((activity < 0) && (errno != EINTR)) {
            perror("Error selecting socket activity");
        }

        // If server socket has activity, it means new connection request has arrived
        if (FD_ISSET(server_socket, &read_fds)) {
            if ((new_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_len)) < 0) {
                perror("Error accepting new connection");
                exit(EXIT_FAILURE);
            }

            // Add new socket to list of sockets
            for (i = 0; i < MAX_CONNECTIONS; i++) {
                if (client_sockets[i] == 0) {
                    client_sockets[i] = new_socket;
                    printf("New connection: socket fd %d, IP %s, port %d\n", new_socket, inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
                    break;
                }
            }
        }

        // Handle client activity on sockets
        for (i = 0; i < MAX_CONNECTIONS; i++) {
            sd = client_sockets[i];

            if (FD_ISSET(sd, &read_fds)) {
                // If this was caused by a user input
                if (recv(sd, buffer, BUFFER_SIZE, 0) == 0) {
                    // To remove connection
                    getpeername(sd, (struct sockaddr *)&client_address, &client_address_len);
                    printf("Connection closed: socket fd %d, IP %s, port %d\n", sd, inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
                    close(sd);
                    client_sockets[i] = 0;
                }

                // Otherwise receive and send back messages
                else {
                    buffer[strlen(buffer) - 1] = '\0';
                    printf("Received message from socket %d: %s\n", sd, buffer);
                    send(sd, buffer, strlen(buffer), 0);
                }
            }
        }

        memset(buffer, 0, sizeof buffer);
    }

    return 0;
}