//Falcon-180B DATASET v1.0 Category: Client Server Application ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define TRUE 1
#define FALSE 0
#define BUFFSIZE 1024

// Function for handling client connections
void *handle_client(void *socket_desc) {
    char buffer[BUFFSIZE];
    int bytes_received;
    while(TRUE) {
        bytes_received = recv(socket_desc, buffer, BUFFSIZE, 0);
        if(bytes_received <= 0) {
            break;
        }
        buffer[bytes_received] = '\0';
        printf("Client message: %s\n", buffer);
    }
    close(socket_desc);
    return NULL;
}

// Function for creating a socket and binding it to a port
int create_socket(int port) {
    int sockfd;
    int opt = 1;
    struct sockaddr_in server_addr;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd == -1) {
        printf("Error creating socket\n");
        return -1;
    }
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(port);
    if(bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        return -1;
    }
    listen(sockfd, 5);
    return sockfd;
}

// Function for accepting client connections
void accept_clients(int sockfd) {
    while(TRUE) {
        int client_sockfd;
        struct sockaddr_in client_addr;
        socklen_t addr_size = sizeof(client_addr);
        client_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &addr_size);
        if(client_sockfd == -1) {
            printf("Error accepting client connection\n");
            continue;
        }
        printf("Client connected\n");
        pthread_t thread_id;
        pthread_create(&thread_id, NULL, handle_client, (void *)client_sockfd);
    }
}

int main() {
    int port = 8080;
    int sockfd = create_socket(port);
    if(sockfd == -1) {
        return -1;
    }
    printf("Server started on port %d\n", port);
    accept_clients(sockfd);
    close(sockfd);
    return 0;
}