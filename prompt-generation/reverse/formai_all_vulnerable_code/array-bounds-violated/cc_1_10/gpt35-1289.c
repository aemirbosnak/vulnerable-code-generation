//FormAI DATASET v1.0 Category: Client Server Application ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BACKLOG 5
#define BUFFER_SIZE 1024

int main(int argc, char **argv) {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_len;
    char buffer[BUFFER_SIZE];
    
    // create server socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        perror("Failed to create server socket");
        exit(EXIT_FAILURE);
    }
    
    // initialize server address
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(8080);
    
    // bind server socket to address
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("Failed to bind server socket to address");
        exit(EXIT_FAILURE);
    }
    
    // listen for incoming connections
    if (listen(server_socket, BACKLOG) == -1) {
        perror("Failed to listen for incoming connections");
        exit(EXIT_FAILURE);
    }
    
    printf("Server listening on port %d...\n", ntohs(server_address.sin_port));
    
    while (1) {
        // accept incoming connection
        client_address_len = sizeof(client_address);
        client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_len);
        if (client_socket == -1) {
            perror("Failed to accept incoming connection");
            continue;
        }
        
        printf("Accepted a new client connection from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
        
        // receive data from client
        ssize_t bytes_received = recv(client_socket, buffer, BUFFER_SIZE - 1, 0);
        if (bytes_received == -1) {
            perror("Failed to receive data from client");
            close(client_socket);
            continue;
        }
        
        // null-terminate received data
        buffer[bytes_received] = '\0';
        
        printf("Received data from client (%d bytes): %s\n", (int)bytes_received, buffer);
        
        // convert received data to upper case
        for (int i = 0; i < bytes_received; i++) {
            buffer[i] = toupper(buffer[i]);
        }
        
        // send converted data back to client
        ssize_t bytes_sent = send(client_socket, buffer, bytes_received, 0);
        if (bytes_sent == -1) {
            perror("Failed to send data back to client");
            close(client_socket);
            continue;
        }
        
        printf("Sent data back to client (%d bytes): %s\n", (int)bytes_sent, buffer);
        
        // close connection with client
        close(client_socket);
    }
    
    return 0;
}