//FormAI DATASET v1.0 Category: Networking ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <port>\n", argv[0]);
        exit(1);
    }
    int port = atoi(argv[1]);
    
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Failed to create socket");
        exit(1);
    }
    
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(port);
    
    if (bind(server_socket, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("Failed to bind socket");
        exit(1);
    }

    if (listen(server_socket, MAX_CLIENTS) < 0) {
        perror("Failed to listen to socket");
        exit(1);
    }
    
    printf("Server running on port %d...\n", port);

    fd_set active_fds, read_fds;
    FD_ZERO(&active_fds);
    FD_SET(server_socket, &active_fds);

    char buffer[BUFFER_SIZE];
    int client_sockets[MAX_CLIENTS] = {0};

    while (1) {
        read_fds = active_fds;
        
        if (select(FD_SETSIZE, &read_fds, NULL, NULL, NULL) < 0) {
            perror("Failed to select sockets");
            exit(1);
        }

        for (int i = 0; i < FD_SETSIZE; i++) {
            if (FD_ISSET(i, &read_fds)) {
                if (i == server_socket) {
                    int client_socket = accept(server_socket, NULL, NULL);
                    
                    if (client_socket < 0) {
                        perror("Failed to accept client connection");
                        exit(1);
                    }
                    
                    printf("New client connected: %d\n", client_socket);
                    
                    for (int j = 0; j < MAX_CLIENTS; j++) {
                        if (client_sockets[j] == 0) {
                            client_sockets[j] = client_socket;
                            break;
                        }
                    }
                    
                    FD_SET(client_socket, &active_fds);
                } else {
                    memset(buffer, 0, BUFFER_SIZE);
                    int bytes_received = recv(i, buffer, BUFFER_SIZE, 0);

                    if (bytes_received <= 0) {
                        printf("Client disconnected: %d\n", i);
                        FD_CLR(i, &active_fds);
                        close(i);
                        
                        for (int j = 0; j < MAX_CLIENTS; j++) {
                            if (client_sockets[j] == i) {
                                client_sockets[j] = 0;
                                break;
                            }
                        }
                    } else {
                        printf("Message from client %d: %s", i, buffer);
                        
                        for (int j = 0; j < MAX_CLIENTS; j++) {
                            if (i != client_sockets[j] && client_sockets[j] != 0) {
                                printf("Sending message to client %d\n", client_sockets[j]);
                                send(client_sockets[j], buffer, bytes_received, 0);
                            }
                        }
                    }
                }
            }
        }
    }

    return 0;
}