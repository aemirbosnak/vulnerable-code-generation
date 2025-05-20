//FormAI DATASET v1.0 Category: Chat server ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_CLIENTS 10

// Thread function to handle client connections
void *connection_handler(void *);

int main(int argc, char *argv[])
{
    int server_fd, new_socket, client_fd[MAX_CLIENTS], opt = 1;
    struct sockaddr_in address;
    pthread_t threads[MAX_CLIENTS];
    int addrlen = sizeof(address);
     
    // Creating server socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Failed to create server socket\n");
        exit(EXIT_FAILURE);
    }
     
    // Attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT,
                                                  &opt, sizeof(opt))) {
        perror("Failed to setsockopt\n");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);
     
    // Binding to the specified port
    if (bind(server_fd, (struct sockaddr *) &address, 
                                 sizeof(address)) < 0) {
        perror("Failed to bind to port 8080\n");
        exit(EXIT_FAILURE);
    }
     
    // Start listening for incoming requests
    if (listen(server_fd, 3) < 0) {
        perror("Failed to listen\n");
        exit(EXIT_FAILURE);
    }
     
    // Message displayed on server console
    printf("Server listening on port 8080...\n");
    memset(client_fd, 0, sizeof(client_fd));  // initialize client file descriptors to 0
    
    // Handle incoming client connections
    while (1) {
        // Accept incoming connection
        if ((new_socket = accept(server_fd, 
                 (struct sockaddr *) &address, (socklen_t*) &addrlen)) < 0) {
            perror("Failed to accept connection\n");
            exit(EXIT_FAILURE);
        }
        
        // Find first available slot in file descriptor array
        int i = 0;
        while (i < MAX_CLIENTS && client_fd[i] != 0)
            i++;
        if (i == MAX_CLIENTS) {
            printf("Maximum clients reached. Connection rejected.\n");
            close(new_socket);
        }
        else {
            client_fd[i] = new_socket;
            printf("New client connected. Client #%d\n", i);
            
            // Create separate thread to handle client connection
            if (pthread_create(&threads[i], NULL, connection_handler, 
                                   (void *) &client_fd[i]) < 0) {
                perror("Failed to create thread\n");
                exit(EXIT_FAILURE);
            }
        }
    }
    return 0;
}

// Function to handle client connection
void *connection_handler(void *socket_desc)
{
    int client_socket = *(int *) socket_desc;
    char buffer[1024];
    int read_size;

    while ((read_size = recv(client_socket, buffer, sizeof(buffer), 0)) > 0) {
        buffer[read_size] = '\0';
        printf("From client #%d: %s", client_socket, buffer);
        write(client_socket, buffer, strlen(buffer));
        if (strncmp(buffer, "bye", 3) == 0)
            break;
    }
    close(client_socket);
    *(int *) socket_desc = 0;
    printf("Client #%d disconnected\n", client_socket);
    pthread_exit(NULL);
}