//FormAI DATASET v1.0 Category: Client Server Application ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define PORT 8080
#define BUFFER_SIZE 1024

void *connection_handler(void *);

int main(int argc, char const *argv[])
{
    int server_fd, new_socket, c;
    struct sockaddr_in server_address, client_address;
    char *message;
    
    // Create socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }
    
    // Set socket options
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &(int){1}, sizeof(int)))
    {
        perror("Set socket options failed");
        exit(EXIT_FAILURE);
    }
    
    // Prepare server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);
    
    // Bind socket to address
    if (bind(server_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0)
    {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }
    
    // Listen for connections
    if (listen(server_fd, 3) < 0)
    {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }
    
    // Accept incoming connections
    c = sizeof(struct sockaddr_in);
    while ((new_socket = accept(server_fd, (struct sockaddr *)&client_address, (socklen_t *)&c)))
    {
        printf("Client connected: %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
        
        // Allocate message and spawn connection handler thread
        message = "Connected to server!";
        pthread_t thread_id;
        if (pthread_create(&thread_id, NULL, connection_handler, (void *)&new_socket) < 0)
        {
            perror("Thread creation failed");
            exit(EXIT_FAILURE);
        }
        
        // Send initial message to client
        if (send(new_socket, message, strlen(message), 0) != strlen(message))
        {
            perror("Send failed");
        }
    }
    
    // Clean up
    close(server_fd);
    return 0;
}

void *connection_handler(void *socket_desc)
{
    int socket = *(int *)socket_desc;
    char buffer[BUFFER_SIZE];
    int message_len;

    while ((message_len = recv(socket, buffer, BUFFER_SIZE, 0)) > 0)
    {
        buffer[message_len] = '\0';
        printf("Client message: %s\n", buffer);
        
        // Echo received message back to client
        if (send(socket, buffer, strlen(buffer), 0) != strlen(buffer))
        {
            perror("Send failed");
        }
    }
    
    // Close socket and terminate thread
    if (message_len == 0)
    {
        printf("Client disconnected\n");
    }
    else
    {
        perror("Receive failed");
    }
    close(socket);
    pthread_exit(NULL);
}