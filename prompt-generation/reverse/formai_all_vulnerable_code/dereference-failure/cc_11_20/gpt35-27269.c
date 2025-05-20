//FormAI DATASET v1.0 Category: Chat server ; Style: Claude Shannon
/*
 * This program is a simple chat server in C language, inspired by principles of Claude Shannon's information theory.
 * The server receives and sends messages between clients, sending only meaningful information and minimizing redundancy.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdbool.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

// Information-theoretic function for computing the entropy of a message
int entropy(char *message) {
    int len = strlen(message);
    int count = 0;
    bool found[256] = { false };
    for (int i = 0; i < len; i++) {
        if (!found[message[i]]) {
            found[message[i]] = true;
            count++;
        }
    }
    return count * (int) (log2(len) + 1);
}

int main(int argc, char **argv) {
    // Parse command-line arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    int port = atoi(argv[1]);

    // Set up sockets and address information
    int server_socket = socket(PF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }
    struct sockaddr_in server_address = { 0 };
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }
    if (listen(server_socket, MAX_CLIENTS) == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    // Set up client information
    int client_sockets[MAX_CLIENTS] = { 0 };
    int num_clients = 0;

    // Handle incoming connections and messages
    while (true) {
        // Check for new connections
        fd_set read_fds;
        FD_ZERO(&read_fds);
        FD_SET(server_socket, &read_fds);
        int max_fd = server_socket;
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (client_sockets[i] > 0) {
                FD_SET(client_sockets[i], &read_fds);
                if (client_sockets[i] > max_fd) {
                    max_fd = client_sockets[i];
                }
            }
        }
        int activity = select(max_fd + 1, &read_fds, NULL, NULL, NULL);
        if (activity == -1) {
            perror("select");
            exit(EXIT_FAILURE);
        }

        // Handle new connections
        if (FD_ISSET(server_socket, &read_fds)) {
            int client_socket = accept(server_socket, NULL, NULL);
            if (client_socket == -1) {
                perror("accept");
                exit(EXIT_FAILURE);
            }
            if (num_clients == MAX_CLIENTS) {
                const char *message = "Server full. Try again later.\n";
                send(client_socket, message, strlen(message), 0);
                close(client_socket);
            } else {
                client_sockets[num_clients] = client_socket;
                num_clients++;
            }
        }

        // Handle incoming messages
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (FD_ISSET(client_sockets[i], &read_fds)) {
                char buffer[BUFFER_SIZE];
                ssize_t bytes_received = recv(client_sockets[i], buffer, BUFFER_SIZE, 0);
                if (bytes_received < 0) {
                    perror("recv");
                    exit(EXIT_FAILURE);
                } else if (bytes_received == 0) {
                    printf("Client %d disconnected.\n", i);
                    close(client_sockets[i]);
                    client_sockets[i] = 0;
                    num_clients--;
                } else {
                    buffer[bytes_received] = '\0';
                    int message_entropy = entropy(buffer);
                    if (message_entropy <= 8 || message_entropy % 8 == 0) {
                        // Send only if entropy is low or divisible by 8 (to reduce redundancy)
                        for (int j = 0; j < MAX_CLIENTS; j++) {
                            if (j != i && client_sockets[j] > 0) {
                                ssize_t bytes_sent = send(client_sockets[j], buffer, strlen(buffer), 0);
                                if (bytes_sent < 0) {
                                    perror("send");
                                    exit(EXIT_FAILURE);
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}