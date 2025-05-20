//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_BUFFER_SIZE 4096

int main(int argc, char *argv[]) {
    int server_socket_fd, client_socket_fd;
    struct sockaddr_in server_addr, client_addr;

    if (argc != 4) {
        printf("Usage: %s <server_port> <proxy_port> <server_name>\n", argv[0]);
        return 1;
    }

    char* server_port = argv[1];
    int proxy_port = atoi(argv[2]);
    char* server_name = argv[3];

    // create server socket
    if ((server_socket_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Failed to create server socket");
        return 1;
    }

    // bind server socket to port
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    server_addr.sin_port = htons(proxy_port);

    if (bind(server_socket_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Failed to bind server socket to port");
        return 1;
    }

    // listen for incoming connections
    if (listen(server_socket_fd, SOMAXCONN) < 0) {
        perror("Failed to listen for incoming connections");
        return 1;
    }

    printf("Listening on port %d...\n", proxy_port);

    while (1) {
        socklen_t client_addr_len = sizeof(client_addr);

        // accept incoming connection
        if ((client_socket_fd = accept(server_socket_fd, (struct sockaddr*)&client_addr, &client_addr_len)) < 0) {
            perror("Failed to accept incoming connection");
            continue;
        }

        printf("Accepted incoming connection from %s:%d\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port));

        // create buffer for receiving data from client
        char buffer[MAX_BUFFER_SIZE];
        memset(buffer, 0, MAX_BUFFER_SIZE);

        // receive data from client
        if (recv(client_socket_fd, buffer, MAX_BUFFER_SIZE, 0) < 0) {
            perror("Failed to receive data from client");
            continue;
        }

        printf("Received data:\n%s\n", buffer);

        // create socket for connection to server
        int server_socket_fd;

        if ((server_socket_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
            perror("Failed to create socket for connection to server");
            continue;
        }

        // get server host information
        struct hostent* server_info;

        if ((server_info = gethostbyname(server_name)) == NULL) {
            perror("Failed to get server host information");
            continue;
        }

        // connect to server
        struct sockaddr_in server_addr;
        memset(&server_addr, 0, sizeof(server_addr));
        server_addr.sin_family = AF_INET;
        server_addr.sin_port = htons(atoi(server_port));
        memcpy(&server_addr.sin_addr.s_addr, server_info->h_addr, server_info->h_length);

        if (connect(server_socket_fd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
            perror("Failed to connect to server");
            continue;
        }

        printf("Connected to server at %s:%s\n", server_name, server_port);

        // send data to server
        if (send(server_socket_fd, buffer, strlen(buffer), 0) < 0) {
            perror("Failed to send data to server");
            continue;
        }

        printf("Sent data to server:\n%s\n", buffer);

        // create buffer for receiving data from server
        memset(buffer, 0, MAX_BUFFER_SIZE);

        // receive data from server
        if (recv(server_socket_fd, buffer, MAX_BUFFER_SIZE, 0) < 0) {
            perror("Failed to receive data from server");
            continue;
        }

        printf("Received data from server:\n%s\n", buffer);

        // send data to client
        if (send(client_socket_fd, buffer, strlen(buffer), 0) < 0) {
            perror("Failed to send data to client");
            continue;
        }

        printf("Sent data to client:\n%s\n", buffer);

        // close client socket and server socket
        close(client_socket_fd);
        close(server_socket_fd);
    }

    // close server socket
    close(server_socket_fd);
    return 0;
}