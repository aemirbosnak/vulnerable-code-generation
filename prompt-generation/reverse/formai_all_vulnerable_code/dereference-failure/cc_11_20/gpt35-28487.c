//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: innovative
/*
 * This program is an innovative example of C TCP/IP programming
 * It creates a server that accepts multiple client connections
 * and sends messages between them in a chatroom-like fashion
 * 
 * To run the program, the user must provide a port number as argument
 * 
 * Author: Chatbot
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/select.h>

#define MAX_CLIENTS 10
#define BUFFER_SIZE 1024

int main(int argc, char* argv[]) {
    int server_fd, client_fds[MAX_CLIENTS], num_clients = 0;
    struct sockaddr_in server_addr, client_addr;
    int addrlen = sizeof(client_addr);
    char buffer[BUFFER_SIZE];
    
    if(argc < 2) {
        printf("Usage: %s [port]\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    // create socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(server_fd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }
    
    // setup server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(atoi(argv[1]));
    
    // bind socket to address
    if(bind(server_fd, (struct sockaddr*) &server_addr, sizeof(server_addr)) == -1) {
        perror("bind");
        exit(EXIT_FAILURE);
    }
    
    // listen for clients
    if(listen(server_fd, MAX_CLIENTS) == -1) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    
    while(1) {
        // reset file descriptor set and add server socket
        fd_set fds;
        FD_ZERO(&fds);
        FD_SET(server_fd, &fds);
        int max_fd = server_fd;
        
        // add all connected clients to the set
        for(int i=0; i<num_clients; i++) {
            FD_SET(client_fds[i], &fds);
            if(client_fds[i] > max_fd)
                max_fd = client_fds[i];
        }
        
        // wait for activity on any file descriptor
        if(select(max_fd+1, &fds, NULL, NULL, NULL) == -1) {
            perror("select");
            exit(EXIT_FAILURE);
        }
        
        // handle activity on server socket
        if(FD_ISSET(server_fd, &fds)) {
            int client_fd = accept(server_fd, (struct sockaddr*) &client_addr, (socklen_t*) &addrlen);
            if(client_fd == -1) {
                perror("accept");
                exit(EXIT_FAILURE);
            }
            
            // add new client to array
            if(num_clients < MAX_CLIENTS)
                client_fds[num_clients++] = client_fd;
            else {
                printf("Max clients reached. Connection refused.\n");
                close(client_fd);
            }
        }
        
        // handle activity on client sockets
        for(int i=0; i<num_clients; i++) {
            if(FD_ISSET(client_fds[i], &fds)) {
                int num_bytes = recv(client_fds[i], buffer, BUFFER_SIZE, 0);
                if(num_bytes == -1) {
                    perror("recv");
                    exit(EXIT_FAILURE);
                }
                else if(num_bytes == 0) {
                    close(client_fds[i]);
                    for(int j=i; j<num_clients-1; j++)
                        client_fds[j] = client_fds[j+1];
                    num_clients--;
                }
                else {
                    for(int j=0; j<num_clients; j++) {
                        if(j != i)
                            send(client_fds[j], buffer, num_bytes, 0);
                    }
                }
            }
        }
        
    }
    
    return 0;
}