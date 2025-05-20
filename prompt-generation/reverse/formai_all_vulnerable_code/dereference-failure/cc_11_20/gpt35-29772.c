//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

int main(int argc, char *argv[]) {
    int server_fd, client_fd;
    struct sockaddr_in server_address, client_address;
    char buffer[BUFFER_SIZE];

    if(argc != 4) {
        fprintf(stderr, "Usage: %s <host> <port> <proxy port>\n", argv[0]);
        exit(1);
    }

    // Create server socket
    server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if(server_fd < 0) {
        perror("socket");
        exit(1);
    }

    // Set server address
    bzero(&server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(argv[1]);
    server_address.sin_port = htons(atoi(argv[2]));

    // Bind server socket to server address and port
    if(bind(server_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("bind");
        exit(1);
    }

    // Listen for incoming connections
    if(listen(server_fd, 0) < 0) {
        perror("listen");
        exit(1);
    }

    // Accept incoming connections and handle them
    while(1) {
        socklen_t client_length = sizeof(client_address);
        client_fd = accept(server_fd, (struct sockaddr *)&client_address, &client_length);
        if(client_fd < 0) {
            perror("accept");
            continue;
        }

        // Connect to remote server
        int srv_fd = socket(AF_INET, SOCK_STREAM, 0);
        struct hostent *host = gethostbyname(argv[1]);
        struct sockaddr_in server_info;
        bzero(&server_info,sizeof(server_info));
        server_info.sin_family = AF_INET;
        server_info.sin_port = htons(atoi(argv[2]));
        server_info.sin_addr = *((struct in_addr*)host->h_addr);
        if (connect(srv_fd, (struct sockaddr *)&server_info, sizeof(server_info)) < 0) {
            perror("connect");
            close(srv_fd);
            close(client_fd);
            continue;
        }

        // Send client request to server
        if(send(srv_fd, buffer, sizeof(buffer), 0) < 0) {
            perror("send");
            close(srv_fd);
            close(client_fd);
            continue;
        }

        // Receive response from server
        char response[BUFFER_SIZE];
        if(recv(srv_fd, response, BUFFER_SIZE, 0) < 0) {
            perror("recv");
            close(srv_fd);
            close(client_fd);
            continue;
        }

        // Send server response to client
        if(send(client_fd, response, sizeof(response), 0) < 0) {
            perror("send");
            close(srv_fd);
            close(client_fd);
            continue;
        }
        
        // Close connections
        close(srv_fd);
        close(client_fd);
    }
    
    return 0;
}