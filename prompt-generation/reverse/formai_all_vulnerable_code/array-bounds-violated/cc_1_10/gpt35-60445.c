//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

// function to handle incoming client connections
void handle_client(int client_socket, struct sockaddr_in client_address) {
    char buffer[256];
    int bytes_received;
    
    printf("Client connected: %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
    
    // receive data from client
    while ((bytes_received = recv(client_socket, buffer, sizeof(buffer), 0)) > 0) {
        // add null terminator to buffer
        buffer[bytes_received] = '\0';
        
        // print received data
        printf("Received data from client %s:%d: %s\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port), buffer);
        
        // send data back to client
        if (send(client_socket, buffer, bytes_received, 0) == -1) {
            perror("send");
        }
    }
    
    // close client socket
    close(client_socket);
    printf("Client disconnected: %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
}

int main() {
    int server_socket, client_socket;
    struct sockaddr_in server_address, client_address;
    socklen_t client_address_size = sizeof(client_address);
    pid_t pid;
    
    // create socket
    if ((server_socket = socket(AF_INET , SOCK_STREAM , 0)) == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }
    
    // prepare server address struct
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(8080);
    
    // bind socket to address
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }
    
    // listen for client connections
    if (listen(server_socket, 10) == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    
    printf("Server started on port 8080\n");
    
    // wait for client connections
    while (1) {
        if ((client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_size)) == -1) {
            perror("accept");
            continue;
        }
        
        // create new process to handle client connection
        if ((pid = fork()) == -1) {
            perror("fork");
        }
        
        if (pid == 0) {
            // child process, handle client connection
            handle_client(client_socket, client_address);
            exit(EXIT_SUCCESS);
        } else {
            // parent process, close client socket
            close(client_socket);
            continue;
        }
    }
    
    // close server socket
    close(server_socket);
    
    return 0;
}