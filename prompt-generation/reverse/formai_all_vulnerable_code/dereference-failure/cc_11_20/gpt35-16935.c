//FormAI DATASET v1.0 Category: Networking ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER_PORT 8888
#define MAX_CLIENTS 10 // maximum number of clients that can be connected simultaneously
#define MAX_BUFFER_SIZE 1024

int main() {
    int server_fd, client_fds[MAX_CLIENTS];
    struct sockaddr_in server_addr, client_addr[MAX_CLIENTS];
    char buffer[MAX_BUFFER_SIZE];

    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Bind socket to IP address and port
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(SERVER_PORT);
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Binding failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("Listening failed");
        exit(EXIT_FAILURE);
    }

    fd_set read_fds;
    int num_clients = 0;
    while (1) {
        // Set up file descriptor sets
        FD_ZERO(&read_fds);
        FD_SET(server_fd, &read_fds);
        int max_fd = server_fd;
        for (int i = 0; i < num_clients; i++) {
            FD_SET(client_fds[i], &read_fds);
            if (client_fds[i] > max_fd) {
                max_fd = client_fds[i];
            }
        }

        // Wait for any activity on file descriptors
        if (select(max_fd + 1, &read_fds, NULL, NULL, NULL) < 0) {
            perror("Select failed");
            exit(EXIT_FAILURE);
        }

        // Handle incoming connection request
        if (FD_ISSET(server_fd, &read_fds)) {
            int client_fd;
            unsigned int size = sizeof(client_addr[num_clients]);
            if ((client_fd = accept(server_fd, (struct sockaddr *)&client_addr[num_clients], &size)) < 0) {
                perror("Accept failed");
                continue;
            }
            printf("New connection from %s:%d, socket fd: %d\n", inet_ntoa(client_addr[num_clients].sin_addr), ntohs(client_addr[num_clients].sin_port), client_fd);
            if (send(client_fd, "Welcome to the server", strlen("Welcome to the server"), 0) < 0) {
                perror("Send failed");
                close(client_fd);
                continue;
            }
            client_fds[num_clients] = client_fd;
            num_clients++;
        }

        // Handle client messages
        for (int i = 0; i < num_clients; i++) {
            if (FD_ISSET(client_fds[i], &read_fds)) {
                int valread = read(client_fds[i], buffer, MAX_BUFFER_SIZE);
                if (valread == 0) { // Connection closed by client
                    printf("Connection closed by %s:%d, socket fd: %d\n", inet_ntoa(client_addr[i].sin_addr), ntohs(client_addr[i].sin_port), client_fds[i]);
                    close(client_fds[i]);
                    // Shift the remaining clients in the array
                    for (int j = i+1; j < num_clients; j++) {
                        client_fds[j-1] = client_fds[j];
                        client_addr[j-1] = client_addr[j];
                    }
                    num_clients--;
                } else if (valread < 0) { // Error in reading from client
                    perror("Read failed");
                    continue;
                } else { // Message received from client
                    buffer[valread] = '\0';
                    printf("Received message from %s:%d, socket fd: %d: %s", inet_ntoa(client_addr[i].sin_addr), ntohs(client_addr[i].sin_port), client_fds[i], buffer);
                    if (send(client_fds[i], buffer, strlen(buffer), 0) < 0) {
                        perror("Send failed");
                        close(client_fds[i]);
                        continue;
                    }
                }
            }
        }
    }
    return 0;
}