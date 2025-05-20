//Code Llama-13B DATASET v1.0 Category: Chat server ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/select.h>

#define BUFSIZE 1024
#define MAX_CLIENTS 10

int main(int argc, char *argv[]) {
    int server_sock, client_sock;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    char buf[BUFSIZE];
    fd_set read_fds;
    int fdmax, max_clients;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Create socket
    if ((server_sock = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Setup address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(atoi(argv[1]));

    // Bind socket to address
    if (bind(server_sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_sock, 3) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    // Initialize fd set
    FD_ZERO(&read_fds);
    FD_SET(server_sock, &read_fds);
    fdmax = server_sock;
    max_clients = 0;

    // Loop for accepting incoming connections
    while (1) {
        // Select activity on sockets
        if (select(fdmax + 1, &read_fds, NULL, NULL, NULL) < 0) {
            perror("select failed");
            exit(EXIT_FAILURE);
        }

        // Check for incoming connection
        if (FD_ISSET(server_sock, &read_fds)) {
            // Accept incoming connection
            if ((client_sock = accept(server_sock, (struct sockaddr *)&client_addr, &client_len)) < 0) {
                perror("accept failed");
                exit(EXIT_FAILURE);
            }

            // Add client socket to fd set
            FD_SET(client_sock, &read_fds);
            if (client_sock > fdmax) {
                fdmax = client_sock;
            }

            // Increment number of clients
            max_clients++;

            // Send welcome message to client
            sprintf(buf, "Welcome to the chat server!\n");
            if (send(client_sock, buf, strlen(buf), 0) < 0) {
                perror("send failed");
                exit(EXIT_FAILURE);
            }
        }

        // Check for incoming message from client
        for (int i = 0; i < max_clients; i++) {
            if (FD_ISSET(i, &read_fds)) {
                // Receive message from client
                if ((recv(i, buf, BUFSIZE, 0)) <= 0) {
                    perror("recv failed");
                    exit(EXIT_FAILURE);
                }

                // Broadcast message to all clients
                for (int j = 0; j < max_clients; j++) {
                    if (j != i) {
                        if (send(j, buf, strlen(buf), 0) < 0) {
                            perror("send failed");
                            exit(EXIT_FAILURE);
                        }
                    }
                }
            }
        }
    }

    // Close socket
    close(server_sock);

    return 0;
}