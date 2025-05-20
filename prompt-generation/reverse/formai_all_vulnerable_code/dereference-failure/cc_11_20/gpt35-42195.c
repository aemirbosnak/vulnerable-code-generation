//FormAI DATASET v1.0 Category: Chat server ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <netinet/in.h> // for sockaddr_in
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h> // for inet_pton

#define MAX_MSG_LENGTH 1024
#define BACKLOG 10

struct connection {
    int socket_fd;
    struct sockaddr_in addr;
};

// Function to handle incoming messages from clients
void handle_messages(struct connection* clients, int sock_fd, int num_clients) {
    char buffer[MAX_MSG_LENGTH];
    ssize_t num_bytes;
    
    for (int i = 0; i < num_clients; i++) {
        if (clients[i].socket_fd == sock_fd) {
            // Message is from this client
            num_bytes = recv(sock_fd, buffer, MAX_MSG_LENGTH, 0);
            if (num_bytes <= 0) {
                // Client has disconnected
                printf("Client %s:%d has disconnected\n", 
                       inet_ntoa(clients[i].addr.sin_addr),
                       ntohs(clients[i].addr.sin_port));
                close(sock_fd);
                clients[i].socket_fd = -1;
                return;
            }
            
            // Forward message to all other clients
            for (int j = 0; j < num_clients; j++) {
                if (clients[j].socket_fd != sock_fd && clients[j].socket_fd != -1) {
                    send(clients[j].socket_fd, buffer, num_bytes, 0);
                }
            }
        }
    }
}


int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: ./server <port_number>\n");
        exit(1);
    }
    
    int port_num = atoi(argv[1]);
    if (port_num < 1024 || port_num > 65535) {
        printf("Please enter a port number between 1024 and 65535\n");
        exit(1);
    }
    
    // Create socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        printf("Error creating socket\n");
        exit(1);
    }
    
    // Bind socket to port
    struct sockaddr_in server_addr = {0};
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(port_num);
    
    int status = bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr));
    if (status < 0) {
        printf("Error binding socket to port\n");
        exit(1);
    }
    
    // Listen for incoming connections
    status = listen(server_socket, BACKLOG);
    if (status < 0) {
        printf("Error listening for incoming connections\n");
        exit(1);
    }
    
    printf("Server listening on port %d\n", port_num);
    
    // Initialize array to store client connections
    struct connection clients[BACKLOG];
    for (int i = 0; i < BACKLOG; i++) {
        clients[i].socket_fd = -1;
        memset(&clients[i].addr, 0, sizeof(clients[i].addr));
    }
    
    // Main loop to accept incoming connections
    while (1) {
        // Check for incoming connections
        fd_set read_fds;
        FD_ZERO(&read_fds);
        FD_SET(server_socket, &read_fds);
        int max_fd = server_socket;
        for (int i = 0; i < BACKLOG; i++) {
            if (clients[i].socket_fd != -1) {
                FD_SET(clients[i].socket_fd, &read_fds);
                if (clients[i].socket_fd > max_fd) {
                    max_fd = clients[i].socket_fd;
                }
            }
        }
        
        if (select(max_fd + 1, &read_fds, NULL, NULL, NULL) < 0) {
            printf("Error in select()\n");
            continue;
        }
        
        if (FD_ISSET(server_socket, &read_fds)) {
            // Accept incoming connection
            struct sockaddr_in client_addr = {0};
            socklen_t addr_size = sizeof(client_addr);
            int client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &addr_size);
            if (client_socket < 0) {
                printf("Error accepting incoming connection\n");
                continue;
            }
            
            // Add new client to list of clients
            printf("New client %s:%d connected\n", 
                   inet_ntoa(client_addr.sin_addr),
                   ntohs(client_addr.sin_port));
            int added_client = 0;
            for (int i = 0; i < BACKLOG; i++) {
                if (clients[i].socket_fd == -1) {
                    clients[i].socket_fd = client_socket;
                    clients[i].addr = client_addr;
                    added_client = 1;
                    break;
                }
            }
            
            if (!added_client) {
                printf("Too many clients. Closing connection\n");
                close(client_socket);
                continue;
            }
        }
        
        // Check for incoming messages from clients
        for (int i = 0; i < BACKLOG; i++) {
            if (clients[i].socket_fd != -1 && FD_ISSET(clients[i].socket_fd, &read_fds)) {
                handle_messages(clients, clients[i].socket_fd, BACKLOG);
            }
        }
    }
    
    return 0;
}