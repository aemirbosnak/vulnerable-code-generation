//FormAI DATASET v1.0 Category: Networking ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <sys/types.h>
#include <time.h>

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 8888
#define MAX_CLIENTS 5
#define BUFFER_SIZE 1024

int main() {
    int sockfd; // Socket file descriptor
    struct sockaddr_in serv_addr, cli_addr; // Server and client address structures
    fd_set active_fd_set, read_fd_set; // File descriptor sets for select()
    char buffer[BUFFER_SIZE]; // Buffer for incoming data
    time_t current_time; // Current time for logging
    
    // Creating socket file descriptor
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }
    
    // Initializing server address structure
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(SERVER_IP);
    serv_addr.sin_port = htons(SERVER_PORT);
    
    // Binding socket to server address
    if (bind(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) == -1) {
        perror("Failed to bind socket to address");
        exit(EXIT_FAILURE);
    }
    
    // Listening for incoming connections
    if (listen(sockfd, MAX_CLIENTS) == -1) {
        perror("Failed to listen for connections");
        exit(EXIT_FAILURE);
    }
    
    // Initializing file descriptor sets
    FD_ZERO(&active_fd_set);
    FD_SET(sockfd, &active_fd_set);
    printf("Server successfully started. Waiting for incoming connections...\n");
    
    while (1) {
        read_fd_set = active_fd_set;
        if (select(FD_SETSIZE, &read_fd_set, NULL, NULL, NULL) == -1) {
            perror("Select failed");
            exit(EXIT_FAILURE);
        }
        
        // Handling incoming connections and data
        for (int i = 0; i < FD_SETSIZE; i++) {
            if (FD_ISSET(i, &read_fd_set)) {
                // Handling incoming connection
                if (i == sockfd) {
                    socklen_t client_size = sizeof(cli_addr);
                    int client_fd = accept(sockfd, (struct sockaddr*)&cli_addr, &client_size);
                    if (client_fd == -1) {
                        perror("Failed to accept incoming connection");
                        continue;
                    }
                    FD_SET(client_fd, &active_fd_set);
                    printf("New client connected: %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));
                    
                    // Sending welcome message to client
                    char welcome_msg[] = "Welcome to the server!";
                    if (send(client_fd, welcome_msg, strlen(welcome_msg), 0) == -1) {
                        perror("Failed to send welcome message to client");
                        close(client_fd);
                        FD_CLR(client_fd, &active_fd_set);
                        continue;
                    }
                }
                // Handling incoming data from client
                else {
                    memset(buffer, 0, BUFFER_SIZE);
                    
                    // Receiving data from client
                    int recv_len = recv(i, buffer, BUFFER_SIZE, 0);
                    if (recv_len == -1) {
                        perror("Failed to receive data from client");
                        close(i);
                        FD_CLR(i, &active_fd_set);
                        continue;
                    }
                    else if (recv_len == 0) { // Client disconnected
                        printf("Client disconnected: %s:%d\n", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port));
                        close(i);
                        FD_CLR(i, &active_fd_set);
                        continue;
                    }
                    
                    // Logging incoming data from client with timestamp
                    current_time = time(NULL);
                    printf("Incoming data from client [%s:%d] at %s: %s", inet_ntoa(cli_addr.sin_addr), ntohs(cli_addr.sin_port), ctime(&current_time), buffer);
                    
                    // Echoing data back to client
                    if (send(i, buffer, strlen(buffer), 0) == -1) {
                        perror("Failed to echo data back to client");
                        close(i);
                        FD_CLR(i, &active_fd_set);
                        continue;
                    }
                }
            }
        }
    }
    
    // Closing socket file descriptor
    close(sockfd);
    
    return 0;
}