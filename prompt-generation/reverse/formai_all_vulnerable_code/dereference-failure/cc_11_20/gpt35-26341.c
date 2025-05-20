//FormAI DATASET v1.0 Category: Networking ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CLIENTS 10
#define PORT 8080

int main(){
    int sockfd, connfd, len;
    struct sockaddr_in servaddr, cli[MAX_CLIENTS];
    char buffer[1024];
    int max_fd, max_index, num_clients = 0;
    fd_set readfds, allfds;
    
    // create the socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Socket creation failed...\n");
        exit(0);
    }
    else {
        printf("Socket successfully created..\n");
    }
    
    // clear address and assign IP, PORT
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);
    
    // bind the socket with the server address
    if ((bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr))) != 0) {
        printf("Socket bind failed...\n");
        exit(0);
    }
    else {
        printf("Socket successfully binded..\n");
    }
    
    // listen for connections
    if ((listen(sockfd, MAX_CLIENTS)) != 0) {
        printf("Listening failed...\n");
        exit(0);
    }
    else {
        printf("Server listening..\n");
    }
    
    // set up initial file descriptor set
    FD_ZERO(&allfds);
    FD_SET(sockfd, &allfds);
    max_fd = sockfd;
    max_index = -1;
    
    while (1) {
        // copy allfds to readfds, since select() modifies the fd_set
        readfds = allfds;
        
        // wait for activity on any socket
        select(max_fd+1, &readfds, NULL, NULL, NULL);
        
        // socket for new connection
        if (FD_ISSET(sockfd, &readfds)) {
            len = sizeof(cli[num_clients]);
            connfd = accept(sockfd, (struct sockaddr *)&cli[num_clients], &len);
            
            // add new connection to allfds
            FD_SET(connfd, &allfds);
            
            // update max_fd and max_index
            if (connfd > max_fd) {
                max_fd = connfd;
            }
            if (num_clients > max_index) {
                max_index = num_clients;
            }
            
            // send welcome message to new client
            char welcome[] = "Welcome to the chat server! You are client #";
            char client_num[2];
            sprintf(client_num, "%d", num_clients);
            strcat(welcome, client_num);
            write(connfd, welcome, sizeof(welcome));
            
            num_clients++;
        }
        
        // handle input from clients
        for (int i=0; i<=max_index; i++) {
            if (FD_ISSET(cli[i].sin_port, &readfds)) {
                // read input from client
                int n = read(cli[i].sin_port, buffer, sizeof(buffer));
                
                // if client disconnected
                if (n == 0) {
                    close(cli[i].sin_port);
                    FD_CLR(cli[i].sin_port, &allfds);
                    num_clients--;
                }
                // print input from client
                else {
                    printf("Client %d: %s", i, buffer);
                }
            }
        }
    }
    
    close(sockfd);
    return 0;
}