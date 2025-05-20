//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 4096
#define MAX_CLIENTS 5

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    // Check command line arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <port> <target ip:port>\n", argv[0]);
        exit(1);
    }

    // Parse port number
    int portno = atoi(argv[1]);

    // Parse target IP address and port number
    char *target_ip;
    int target_port;
    char *token = strtok(argv[2], ":");
    target_ip = token;
    token = strtok(NULL, ":");
    if (token == NULL) {
        fprintf(stderr, "Error: Invalid target IP address and port number.\n");
        exit(1);
    }
    target_port = atoi(token);

    // Create socket for incoming connections
    int server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_sockfd < 0) {
        error("Error opening server socket.");
    }

    // Set up server address
    struct sockaddr_in server_address;
    bzero((char *) &server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(portno);

    // Bind socket to server address
    if (bind(server_sockfd, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        error("Error binding server socket to server address.");
    }

    // Listen for incoming connections
    listen(server_sockfd, MAX_CLIENTS);

    // Accept incoming connections and create new socket for each one
    struct sockaddr_in client_address;
    socklen_t client_address_size = sizeof(client_address);
    int client_sockfd[MAX_CLIENTS];
    int n_clients = 0;
    while (n_clients < MAX_CLIENTS) {
        client_sockfd[n_clients] = accept(server_sockfd, (struct sockaddr *) &client_address, &client_address_size);
        if (client_sockfd[n_clients] < 0) {
            error("Error accepting incoming connection.");
        }
        n_clients++;
    }

    // Create socket for outgoing connection
    int target_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (target_sockfd < 0) {
        error("Error creating target socket.");
    }

    // Set up target address
    struct sockaddr_in target_address;
    bzero((char *) &target_address, sizeof(target_address));
    target_address.sin_family = AF_INET;
    target_address.sin_addr.s_addr = inet_addr(target_ip);
    target_address.sin_port = htons(target_port);

    // Connect to target server
    if (connect(target_sockfd, (struct sockaddr *) &target_address, sizeof(target_address)) < 0) {
        error("Error connecting to target server.");
    }

    // Set up file descriptor sets for select() function
    fd_set readfds, writefds;
    FD_ZERO(&readfds);
    FD_ZERO(&writefds);
    for (int i = 0; i < MAX_CLIENTS; i++) {
        FD_SET(client_sockfd[i], &readfds);
    }
    FD_SET(target_sockfd, &readfds);

    // Main loop
    char buffer[BUFFER_SIZE];
    int retval;
    int maxfd = target_sockfd;
    while (1) {
        // Check for activity on file descriptors using select() function
        writefds = readfds;
        retval = select(maxfd+1, &readfds, &writefds, NULL, NULL);
        if (retval < 0) {
            error("Error in select() function.");
        }

        // Handle incoming connections
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (FD_ISSET(client_sockfd[i], &readfds)) {
                // Read data from client
                bzero(buffer, BUFFER_SIZE);
                int n = read(client_sockfd[i], buffer, BUFFER_SIZE-1);
                if (n < 0) {
                    error("Error reading data from client.");
                }

                // Forward data to target server
                n = write(target_sockfd, buffer, strlen(buffer));
                if (n < 0) {
                    error("Error writing data to target server.");
                }
            }
        }

        // Handle data from target server
        if (FD_ISSET(target_sockfd, &readfds)) {
            // Read data from target server
            bzero(buffer, BUFFER_SIZE);
            int n = read(target_sockfd, buffer, BUFFER_SIZE-1);
            if (n < 0) {
                error("Error reading data from target server.");
            }

            // Forward data to all connected clients
            for (int i = 0; i < MAX_CLIENTS; i++) {
                if (FD_ISSET(client_sockfd[i], &writefds)) {
                    n = write(client_sockfd[i], buffer, strlen(buffer));
                    if (n < 0) {
                        error("Error writing data to client.");
                    }
                }
            }
        }

        // Update file descriptor sets for select() function
        FD_ZERO(&readfds);
        FD_ZERO(&writefds);
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (client_sockfd[i] > 0) {
                FD_SET(client_sockfd[i], &readfds);
                FD_SET(client_sockfd[i], &writefds);
                if (client_sockfd[i] > maxfd) {
                    maxfd = client_sockfd[i];
                }
            }
        }
        if (target_sockfd > 0) {
            FD_SET(target_sockfd, &readfds);
            if (target_sockfd > maxfd) {
                maxfd = target_sockfd;
            }
        }
    }

    // Close sockets
    for (int i = 0; i < MAX_CLIENTS; i++) {
        close(client_sockfd[i]);
    }
    close(target_sockfd);
    close(server_sockfd);

    return 0;
}