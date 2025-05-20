//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {

    int client_socket, server_socket;
    struct sockaddr_in client_address, server_address;
    int client_len, server_len;
    int read_size, sent_size;
    char buffer[BUFFER_SIZE];
    
    // Create client socket
    client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket < 0) {
        perror("Error creating client socket");
        exit(EXIT_FAILURE);
    }
    
    // Set up client socket address
    memset(&client_address, 0, sizeof(client_address));
    client_address.sin_family = AF_INET;
    client_address.sin_addr.s_addr = htonl(INADDR_ANY);
    client_address.sin_port = htons(atoi(argv[1]));
    
    // Bind client socket to address
    if (bind(client_socket, (struct sockaddr *) &client_address, sizeof(client_address)) < 0) {
        perror("Error binding client socket");
        exit(EXIT_FAILURE);
    }
    
    // Listen for incoming connections
    if (listen(client_socket, 1) < 0) {
        perror("Error listening for incoming connections");
        exit(EXIT_FAILURE);
    }
    
    printf("Simple HTTP Proxy up and running...\n");
    
    while (1) {
        
        // Accept incoming connection
        client_len = sizeof(client_address);
        server_len = sizeof(server_address);
        server_socket = accept(client_socket, (struct sockaddr *) &server_address, &server_len);
        if (server_socket < 0) {
            perror("Error accepting incoming connection");
            exit(EXIT_FAILURE);
        }
        
        // Fork process to handle incoming request
        pid_t pid = fork();
        if (pid == -1) {
            perror("Error when forking process");
            exit(EXIT_FAILURE);
        }
        if (pid == 0) { // Process child
            
            // Connect to remote server
            client_socket = socket(AF_INET, SOCK_STREAM, 0);
            if (client_socket < 0) {
                perror("Error creating client socket");
                exit(EXIT_FAILURE);
            }
            
            if (connect(client_socket, (struct sockaddr *) &server_address, server_len) < 0) {
                perror("Error connecting to remote server");
                exit(EXIT_FAILURE);
            }
            
            // Receive data from client and send to server
            while ((read_size = recv(server_socket, buffer, BUFFER_SIZE, 0)) > 0) {
                if (send(client_socket, buffer, read_size, 0) < 0) {
                    perror("Error sending data to remote server");
                }
            }
            
            // Receive response from server and send to client
            while ((read_size = recv(client_socket, buffer, BUFFER_SIZE, 0)) > 0) {
                if (send(server_socket, buffer, read_size, 0) < 0) {
                    perror("Error sending data to client");
                }
            }
            
            // Close sockets and exit child process
            close(client_socket);
            close(server_socket);
            exit(EXIT_SUCCESS);
        }
    }
    
    // Close client socket before exiting parent process
    close(client_socket);
    return 0;
}