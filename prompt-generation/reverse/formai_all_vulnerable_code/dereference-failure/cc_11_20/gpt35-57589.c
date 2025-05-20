//FormAI DATASET v1.0 Category: Client Server Application ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int server_socket, client_socket[MAX_CLIENTS], activity, valread;
    struct sockaddr_in server_address, client_address;
    char buffer[BUFFER_SIZE];
    
    // Creating server socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }
    
    // Setting up server address
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(atoi(argv[1]));
    
    // Binding server socket to the address
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }
    
    // Listening for incoming connections
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }
    
    printf("Server started listening on port %s\n", argv[1]);
    
    // Accepting incoming connections and handling multiple clients
    while (1) {
        fd_set readfds;
        int max_socket = server_socket;
        
        // Clearing the FD set
        FD_ZERO(&readfds);
        
        // Adding server socket to the FD set
        FD_SET(server_socket, &readfds);
        
        // Adding all client sockets to the FD set
        for (int i = 0; i < MAX_CLIENTS; i++) {
            int client_fd = client_socket[i];
            
            // If the socket is valid, add it to the FD set
            if (client_fd > 0) {
                FD_SET(client_fd, &readfds);
            }
            
            // Updating maximum socket value
            if (client_fd > max_socket) {
                max_socket = client_fd;
            }
        }
        
        // Waiting for an activity on any of the sockets
        activity = select(max_socket + 1, &readfds, NULL, NULL, NULL);
        
        if (activity < 0 && errno != EINTR) {
            perror("Select error");
        }
        
        // If activity is detected on server socket, it means a new client is trying to connect
        if (FD_ISSET(server_socket, &readfds)) {
            int new_socket;
            int address_length = sizeof(client_address);
            
            if ((new_socket = accept(server_socket, (struct sockaddr *)&client_address, (socklen_t *)&address_length)) < 0) {
                perror("Accept error");
                exit(EXIT_FAILURE);
            }
            
            printf("A new client connected with socket fd: %d, ip address: %s, port: %d\n", new_socket, inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
            
            // Adding new client socket to the client sockets array
            for (int i = 0; i < MAX_CLIENTS; i++) {
                if (client_socket[i] == 0) {
                    client_socket[i] = new_socket;
                    break;
                }
            }
        }
        
        // If activity is detected on any of the client sockets, receive and send messages
        for (int i = 0; i < MAX_CLIENTS; i++) {
            int client_fd = client_socket[i];
            
            if (FD_ISSET(client_fd, &readfds)) {
                // Receive message
                valread = recv(client_fd, buffer, BUFFER_SIZE, 0);
                
                if (valread <= 0) {
                    // If client disconnects, remove it from the client sockets array and close the socket
                    close(client_fd);
                    client_socket[i] = 0;
                    printf("Client disconnected with socket fd: %d\n", client_fd);
                } else {
                    buffer[valread] = '\0';
                    
                    // Print received message
                    printf("Received message from client with socket fd: %d\n%s\n", client_fd, buffer);
                    
                    // Send message back to the client
                    send(client_fd, buffer, strlen(buffer), 0);
                }
            }
        }
    }
    
    return 0;
}