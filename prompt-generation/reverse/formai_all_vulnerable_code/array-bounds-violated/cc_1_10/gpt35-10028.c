//FormAI DATASET v1.0 Category: Socket programming ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

// Function to handle incoming data from client
void handle_client_data(int client_socket) {
    char buffer[1024];
    int read_size;
    
    // Loop to continuously receive data from client
    while((read_size = recv(client_socket, buffer, 1024, 0)) > 0) {
        // Add terminating character to end of received data
        buffer[read_size] = '\0';
        
        // Print received data
        printf("Client message: %s\n", buffer);
        
        // Send response back to client
        char* response = "Data received successfully";
        int write_size = write(client_socket, response, strlen(response));
        
        if(write_size < 0) {
            perror("Error sending response back to client");
            break;
        }
    }
    
    // If client disconnects, close client socket
    if(read_size == 0) {
        printf("Client disconnected\n");
        close(client_socket);
    } else if(read_size < 0) {
        perror("Error receiving data from client");
    }
}

int main(int argc, char const *argv[]) {
    int server_socket, client_socket, c;
    struct sockaddr_in server_address, client_address;
    
    // Create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    
    if(server_socket < 0) {
        perror("Error creating socket");
        return 1;
    }
    
    // Set server address properties
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(8080);
    
    // Bind socket to server address
    if(bind(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        perror("Error binding socket to server address");
        return 1;
    }
    
    // Listen for incoming connections
    listen(server_socket, 3);
    
    printf("Server listening on port 8080...\n");
    
    // Accept incoming connections
    c = sizeof(struct sockaddr_in);
    
    while((client_socket = accept(server_socket, (struct sockaddr*)&client_address, (socklen_t*)&c))) {
        printf("Client connected: %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
        
        // Handle incoming data from client
        handle_client_data(client_socket);
    }
    
    if(client_socket < 0) {
        perror("Error accepting incoming connection");
        return 1;
    }
    
    return 0;
}