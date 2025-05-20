//FormAI DATASET v1.0 Category: Client Server Application ; Style: complete
// This is a Chat Application which connects multiple clients to a server.
// It allows clients to connect to the server and send messages to each other.
// The server acts as the intermediate between the clients and manages the connections.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>

#define MAX_CLIENTS 10
#define MAX_MSG_LEN 100

int main(int argc, char **argv)
{
    if (argc < 2) {
        printf("Usage: %s <port_number>\n", argv[0]);
        return -1;
    }

    int port_num = atoi(argv[1]);
    int server_fd, new_socket, valread;
    int opt = 1;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char msg[MAX_MSG_LEN] = {0};
    char buffer[MAX_MSG_LEN] = {0};
    fd_set readfds;
    int max_sd;
    int clients[MAX_CLIENTS] = {0};

    // Create server socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        return -1;
    }

    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(opt))) {
        perror("setsockopt failed");
        return -1;
    }

    // Set server socket address
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(port_num);

    // Bind server socket with address
    if (bind(server_fd, (struct sockaddr*) &address, sizeof(address)) < 0) {
        perror("bind failed");
        return -1;
    }

    // Listen for incoming connections
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("listen failed");
        return -1;
    }

    printf("Server listening on port %d\n", port_num);

    while (1) {
        // Clear file descriptor set
        FD_ZERO(&readfds);

        // Add server socket to file descriptor set
        FD_SET(server_fd, &readfds);
        max_sd = server_fd;

        // Add active client sockets to file descriptor set
        for (int i = 0; i < MAX_CLIENTS; i++) {
            int sd = clients[i];

            if (sd > 0) {
                FD_SET(sd, &readfds);
            }

            if (sd > max_sd) {
                max_sd = sd;
            }
        }

        // Wait for activity on any socket
        select(max_sd + 1, &readfds, NULL, NULL, NULL);

        // Check for incoming connection
        if (FD_ISSET(server_fd, &readfds)) {
            if ((new_socket = accept(server_fd, (struct sockaddr*) &address, (socklen_t*) &addrlen)) < 0) {
                perror("accept failed");
                return -1;
            }

            // Add new client to clients array
            for (int i = 0; i < MAX_CLIENTS; i++) {
                if (clients[i] == 0) {
                    clients[i] = new_socket;
                    break;
                }
            }

            printf("New client connected with socket fd: %d\n", new_socket);
        }

        // Check for active client socket
        for (int i = 0; i < MAX_CLIENTS; i++) {
            int sd = clients[i];

            if (FD_ISSET(sd, &readfds)) {
                // Check if client disconnected
                if ((valread = read(sd, buffer, MAX_MSG_LEN)) == 0) {
                    // Close client socket and remove from clients array
                    close(sd);
                    clients[i] = 0;
                    printf("Client disconnected with socket fd: %d\n", sd);
                } else {
                    // Forward message to all other clients
                    for (int j = 0; j < MAX_CLIENTS; j++) {
                        int dest_sd = clients[j];

                        if (dest_sd > 0 && dest_sd != sd) {
                            send(dest_sd, buffer, strlen(buffer), 0);
                        }
                    }
                }
            }
        }
    }

    return 0;
}