//FormAI DATASET v1.0 Category: Simple Web Server ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

// Define the maximum request size to avoid buffer overflow
#define MAX_REQ_SIZE 1024

int main(int argc, char *argv[]) {
    int listen_socket, connection_socket;
    struct sockaddr_in server_address, client_address;
    char request[MAX_REQ_SIZE], response[MAX_REQ_SIZE];
    
    // Create a socket to listen for incoming connections
    listen_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (listen_socket == -1) {
        printf("Error creating socket\n");
        exit(1);
    }
    
    // Set up the server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = htonl(INADDR_ANY);
    server_address.sin_port = htons(8080);
    
    // Bind the socket to the server address
    if (bind(listen_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        printf("Error binding socket\n");
        exit(1);
    }
    
    // Listen for incoming connections
    if (listen(listen_socket, 10) == -1) {
        printf("Error listening on socket\n");
        exit(1);
    }
    
    // Loop to handle incoming connections
    while (1) {
        socklen_t client_address_size = sizeof(client_address);
        
        // Accept a new connection from a client
        connection_socket = accept(listen_socket, (struct sockaddr *)&client_address, &client_address_size);
        
        if (connection_socket == -1) {
            printf("Error accepting connection\n");
            continue;
        }
        
        printf("Connection accepted from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
        
        // Receive the client's request
        int request_size = recv(connection_socket, request, MAX_REQ_SIZE, 0);
        
        if (request_size == -1) {
            printf("Error receiving request\n");
            close(connection_socket);
            continue;
        }
        
        request[request_size] = '\0'; // Null-terminate the request string
        
        printf("Received request:\n%s\n", request);
        
        // Generate the response
        sprintf(response, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n<html><body><h1>Hello, world!</h1></body></html>");
        
        // Send the response back to the client
        int response_size = send(connection_socket, response, strlen(response), 0);
        
        if (response_size == -1) {
            printf("Error sending response\n");
            close(connection_socket);
            continue;
        }
        
        printf("Sent response:\n%s\n", response);
        
        // Close the connection
        close(connection_socket);
    }
    
    // Close the listening socket
    close(listen_socket);
    
    return 0;
}