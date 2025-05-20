//FormAI DATASET v1.0 Category: Chat server ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_CLIENTS 5
#define BUFFER_SIZE 1024
#define PORT 8080

int main() {
    int server_socket, valread, client_socket[MAX_CLIENTS];
    struct sockaddr_in address;
    char buffer[BUFFER_SIZE] = {0};
    char *message = "Welcome to the chat room!\n";
    int opt = 1;
    int addrlen = sizeof(address);
    
    // create server socket
    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
    
    // set socket options
    if (setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    
    // set address parameters
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
    
    // bind socket to port
    if (bind(server_socket, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    
    // listen for connections
    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    
    // accept incoming connections and handle communication
    while (1) {
        fd_set readfds;
        int max_sd;
        
        FD_ZERO(&readfds);
        FD_SET(server_socket, &readfds);
        max_sd = server_socket;
        
        // add client sockets to select descriptor set
        for (int i = 0; i < MAX_CLIENTS; i++) {
            int sd = client_socket[i];
            if (sd > 0) {
                FD_SET(sd, &readfds);
            }
            if (sd > max_sd) {
                max_sd = sd;
            }
        }
        
        // block until activity is detected on one of the sockets
        int activity = select(max_sd + 1, &readfds, NULL, NULL, NULL);
        
        if (activity < 0) {
            perror("select error");
            exit(EXIT_FAILURE);
        }
        
        // handle incoming connection
        if (FD_ISSET(server_socket, &readfds)) {
            int new_client;
            if ((new_client = accept(server_socket, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
                perror("accept");
                exit(EXIT_FAILURE);
            }
            
            // add new client to socket list
            for (int i = 0; i < MAX_CLIENTS; i++) {
                if (client_socket[i] == 0) {
                    client_socket[i] = new_client;
                    break;
                }
            }
            
            // send welcome message
            send(new_client, message, strlen(message), 0);
        }
        
        // handle client activity
        for (int i = 0; i < MAX_CLIENTS; i++) {
            int sd = client_socket[i];
            
            if (FD_ISSET(sd, &readfds)) {
                if ((valread = read(sd, buffer, BUFFER_SIZE)) == 0) {
                    // client disconnected
                    close(sd);
                    client_socket[i] = 0;
                } else {
                    // broadcast message to all clients
                    for (int j = 0; j < MAX_CLIENTS; j++) {
                        int sd = client_socket[j];
                        if (sd > 0 && sd != client_socket[i]) {
                            send(sd, buffer, strlen(buffer), 0);
                        }
                    }
                }
            }
        }
    }
    
    // close server socket
    close(server_socket);
    
    return 0;
}