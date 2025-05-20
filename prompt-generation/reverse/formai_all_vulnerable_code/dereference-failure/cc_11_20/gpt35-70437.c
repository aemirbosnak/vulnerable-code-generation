//FormAI DATASET v1.0 Category: Chat server ; Style: accurate
// Chat Server Example Program

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/select.h>
#include <sys/time.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    // Create server socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(server_socket == -1) {
        perror("Error creating server socket");
        exit(EXIT_FAILURE);
    }
    
    // Bind the socket to an address and port
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(8080);
    
    if(bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address)) == -1) {
        perror("Error binding server socket");
        exit(EXIT_FAILURE);
    }
    
    // Listen for incoming connections
    if(listen(server_socket, MAX_CLIENTS) == -1) {
        perror("Error listening on server socket");
        exit(EXIT_FAILURE);
    }
    
    fd_set read_fds; // Set of file descriptors to monitor for read
    FD_ZERO(&read_fds);
    FD_SET(server_socket, &read_fds);
    
    while(1) {
        fd_set copy_fds = read_fds;
        
        // Select the file descriptor with incoming data to read
        if(select(FD_SETSIZE, &copy_fds, NULL, NULL, NULL) == -1) {
            perror("Error in select system call");
            exit(EXIT_FAILURE);
        }
        
        // Check for new incoming connection requests
        if(FD_ISSET(server_socket, &copy_fds)) {
            struct sockaddr_in client_address;
            int client_address_len = sizeof(client_address);
            int client_socket = accept(server_socket, (struct sockaddr*) &client_address, &client_address_len);
            
            if(client_socket == -1) {
                perror("Error accepting incoming connection");
                exit(EXIT_FAILURE);
            }
            
            // Add new client socket to read_fds
            FD_SET(client_socket, &read_fds);
            printf("New client connected from %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
        }
        
        // Check for incoming data from clients
        for(int i=0; i<FD_SETSIZE; i++) {
            if(i == server_socket) {
                continue;
            }
            
            if(FD_ISSET(i, &copy_fds)) { // Check if file descriptor has incoming data
                char buffer[BUFFER_SIZE];
                memset(buffer, '\0', BUFFER_SIZE);
                
                ssize_t bytes_received = recv(i, buffer, BUFFER_SIZE, 0);
                
                if(bytes_received <= 0) { // Client has disconnected
                    printf("Client %d has disconnected\n", i);
                    close(i);
                    FD_CLR(i, &read_fds); // Remove client socket from read_fds
                } else { // Broadcast message to all other clients
                    for(int j=0; j<FD_SETSIZE; j++) {
                        if(j == server_socket || j == i) { // Skip server and sender client sockets
                            continue;
                        }
                        
                        if(FD_ISSET(j, &read_fds)) { // Check if file descriptor is active
                            if(send(j, buffer, bytes_received, 0) == -1) {
                                perror("Error sending message to client");
                            }
                        }
                    }
                }
            }
        }
    }

    close(server_socket);
    return 0;
}