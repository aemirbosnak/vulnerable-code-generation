//FormAI DATASET v1.0 Category: Networking ; Style: introspective
// This program demonstrates how to implement a simple chat server using C networking. 
// I create a socket for the server to wait for incoming connections. Once a client connects, the server listens to the messages sent by the client and broadcasts them to all clients connected to the server.
// I use the select function to wait for input from the sockets without blocking the main thread.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/select.h>
#include <errno.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

// array of client sockets
int client_sockets[MAX_CLIENTS];

// function to update the client_sockets array
void remove_client(int socket_fd) {
    int i;
    for (i = 0; i < MAX_CLIENTS; i++) {
        if (client_sockets[i] == socket_fd) {
            client_sockets[i] = -1;
            break;
        }
    }
}

// main function
int main(int argc, char *argv[]) {
    int server_fd, client_fd, max_fd, i, j, activity, addrlen, sd;
    struct sockaddr_in server_addr, client_addr;
    char buffer[BUFFER_SIZE];
    
    // initialize client_sockets array
    for (i = 0; i < MAX_CLIENTS; i++) {
        client_sockets[i] = -1;
    }
    
    // create server socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    
    // set server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons( atoi(argv[1]) );
    
    // bind socket to address
    if (bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    
    // listen for incoming connections
    if (listen(server_fd, MAX_CLIENTS) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }
    
    printf("Waiting for incoming connections...\n");
    
    addrlen = sizeof(server_addr);
    
    while (1) {
        fd_set read_fds;
        
        // clear the socket set
        FD_ZERO(&read_fds);
        
        // add the server socket to the socket set
        FD_SET(server_fd, &read_fds);
        max_fd = server_fd;
        
        // add connected client sockets to the socket set
        for (i = 0; i < MAX_CLIENTS; i++) {
            sd = client_sockets[i];
            
            // if socket descriptor is valid add to read list
            if (sd > 0) {
                FD_SET(sd, &read_fds);
            }
            
            // highest file descriptor number, need it for the select function
            if (sd > max_fd) {
                max_fd = sd;
            }
        }
        
        // wait for activity on any socket
        activity = select(max_fd + 1, &read_fds, NULL, NULL, NULL);
        
        if ((activity < 0) && (errno!=EINTR)) {
            printf("select error");
        }
        
        // if activity on server socket then a new client has connected
        if (FD_ISSET(server_fd, &read_fds)) {
            if ((client_fd = accept(server_fd, (struct sockaddr *)&server_addr, (socklen_t*)&addrlen))<0) {
                perror("accept failed");
                exit(EXIT_FAILURE);
            }
            
            printf("New connection, socket fd: %d, ip: %s, port: %d\n", client_fd,inet_ntoa(server_addr.sin_addr), ntohs(server_addr.sin_port));
            
            // add new client to client_sockets array
            for (i = 0; i < MAX_CLIENTS; i++) {
                if (client_sockets[i] == -1) {
                    client_sockets[i] = client_fd;
                    break;
                }
            }
        }
        
        // loop through all connected clients and read incoming messages
        for (i = 0; i < MAX_CLIENTS; i++) {
            sd = client_sockets[i];
            
            if (FD_ISSET(sd, &read_fds)) {
                if ((read(sd, buffer, BUFFER_SIZE)) == 0) {
                    // client disconnected
                    getpeername(sd, (struct sockaddr*)&client_addr, (socklen_t*)&addrlen);
                    printf("Host disconnected, ip %s, port %d \n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));
                    close(sd);
                    remove_client(sd);
                } else {
                    // broadcast message to all connected clients
                    for (j = 0; j < MAX_CLIENTS; j++) {
                        if (client_sockets[j] != -1 && client_sockets[j] != sd) {
                            if (write(client_sockets[j], buffer, strlen(buffer)) < 0) {
                                printf("Write failed");
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
    
    return 0;
}