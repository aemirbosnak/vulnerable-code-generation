//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int client_fd, server_fd, max_fd;
    int client_port, server_port;
    char *server_ip, client_request[MAX_BUF_SIZE], server_response[MAX_BUF_SIZE];
    fd_set readfds;
    struct sockaddr_in client_addr, server_addr;
    
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <client_port> <server_ip> <server_port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    client_port = atoi(argv[1]);
    server_ip = argv[2];
    server_port = atoi(argv[3]);
    
    memset(&client_addr, 0, sizeof(client_addr));
    client_addr.sin_family = AF_INET;
    client_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    client_addr.sin_port = htons(client_port);
    
    if ((client_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Error: failed to create client socket");
        exit(EXIT_FAILURE);
    }
    
    if (bind(client_fd, (struct sockaddr *)&client_addr, sizeof(client_addr)) == -1) {
        perror("Error: failed to bind client socket");
        exit(EXIT_FAILURE);
    }
    
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(server_ip);
    server_addr.sin_port = htons(server_port);
    
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Error: failed to create server socket");
        exit(EXIT_FAILURE);
    }
    
    if (connect(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Error: failed to connect to server");
        exit(EXIT_FAILURE);
    }
    
    printf("HTTP proxy started on port %d\n", client_port);

    while (1) {
        FD_ZERO(&readfds);
        FD_SET(client_fd, &readfds);
        FD_SET(server_fd, &readfds);
        max_fd = (client_fd > server_fd) ? client_fd : server_fd;
        
        if (select(max_fd+1, &readfds, NULL, NULL, NULL) == -1) {
            perror("Error: failed to select socket");
            exit(EXIT_FAILURE);
        }
        
        if (FD_ISSET(client_fd, &readfds)) {
            memset(client_request, 0, sizeof(client_request));
            if (recv(client_fd, client_request, MAX_BUF_SIZE, 0) <= 0)
                break;
            printf("Received from client:\n%s", client_request);
            if (send(server_fd, client_request, strlen(client_request), 0) == -1) {
                perror("Error: failed to send client request to server");
                exit(EXIT_FAILURE);
            }
        }
        
        if (FD_ISSET(server_fd, &readfds)) {
            memset(server_response, 0, sizeof(server_response));
            if (recv(server_fd, server_response, MAX_BUF_SIZE, 0) <= 0)
                break;
            printf("Received from server:\n%s", server_response);
            if (send(client_fd, server_response, strlen(server_response), 0) == -1) {
                perror("Error: failed to send server response to client");
                exit(EXIT_FAILURE);
            }
        }
    }
    
    close(client_fd);
    close(server_fd);
    printf("HTTP proxy stopped.\n");
    
    return 0;
}