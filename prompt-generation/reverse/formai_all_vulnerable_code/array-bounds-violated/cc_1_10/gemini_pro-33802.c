//GEMINI-pro DATASET v1.0 Category: Basic Unix-like Shell ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <signal.h>

#define MAX_CLIENTS 10
#define MAX_COMMAND_LENGTH 100

struct client_info {
    int socket;
    struct sockaddr_in address;
    pid_t pid;
};

struct client_info clients[MAX_CLIENTS];
int num_clients = 0;

void handle_client(int client_socket) {
    char command[MAX_COMMAND_LENGTH];
    int n;
    
    while (1) {
        // Read the command from the client
        n = read(client_socket, command, MAX_COMMAND_LENGTH);
        if (n <= 0) {
            // Client has disconnected
            close(client_socket);
            return;
        }
        
        // Null-terminate the command
        command[n] = '\0';
        
        // Execute the command
        if (strcmp(command, "exit") == 0) {
            // Client has requested to exit
            close(client_socket);
            return;
        } else {
            // Create a child process to execute the command
            pid_t pid = fork();
            if (pid == 0) {
                // Child process
                execlp(command, command, NULL);
                perror("execlp");
                exit(1);
            } else {
                // Parent process
                int status;
                waitpid(pid, &status, 0);
                
                // Send the output of the command to the client
                char output[1024];
                snprintf(output, sizeof(output), "%s\n", command);
                write(client_socket, output, strlen(output));
            }
        }
    }
}

int main(int argc, char *argv[]) {
    int server_socket;
    struct sockaddr_in server_address;
    
    // Create the server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("socket");
        return 1;
    }
    
    // Set the server address
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(5000);
    
    // Bind the server socket to the server address
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("bind");
        return 1;
    }
    
    // Listen for incoming connections
    if (listen(server_socket, 5) < 0) {
        perror("listen");
        return 1;
    }
    
    // Accept incoming connections
    while (1) {
        struct sockaddr_in client_address;
        socklen_t client_address_len = sizeof(client_address);
        
        int client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_len);
        if (client_socket < 0) {
            perror("accept");
            continue;
        }
        
        // Add the client to the list of connected clients
        clients[num_clients].socket = client_socket;
        clients[num_clients].address = client_address;
        clients[num_clients].pid = 0;
        num_clients++;
        
        // Fork a child process to handle the client
        pid_t pid = fork();
        if (pid == 0) {
            // Child process
            handle_client(client_socket);
            exit(0);
        } else {
            // Parent process
            clients[num_clients - 1].pid = pid;
        }
    }
    
    // Close the server socket
    close(server_socket);
    
    return 0;
}