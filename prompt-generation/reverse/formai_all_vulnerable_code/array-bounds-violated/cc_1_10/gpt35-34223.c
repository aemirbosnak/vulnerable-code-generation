//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: high level of detail
// A Simple HTTP Proxy in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <errno.h>

#define HTTP_PORT 80

// Function to handle the connection to the remote server
void handle_server_connection(int client_socket, char* remote_host, int remote_port) {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(server_socket < 0) {
        perror("Unable to create socket");
        exit(-1);
    }

    // Get the IP address of the remote host
    struct hostent* host_info = gethostbyname(remote_host);
    if(host_info == NULL) {
        perror("Unable to get IP address");
        exit(-1);
    }

    // Build the remote server address
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr = *((struct in_addr*)host_info->h_addr);
    server_address.sin_port = htons(remote_port);

    // Connect to the remote server
    if(connect(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        perror("Unable to connect to server");
        exit(-1);
    }

    // Forward the HTTP request to the remote server
    char buffer[BUFSIZ];
    int bytes_received = recv(client_socket, buffer, BUFSIZ - 1, 0);
    if(bytes_received < 0) {
        perror("Error receiving from client");
        exit(-1);
    }

    buffer[bytes_received] = '\0';
    send(server_socket, buffer, strlen(buffer), 0);

    // Forward the response from the remote server to the client
    while(bytes_received = recv(server_socket, buffer, BUFSIZ - 1, 0)) {
        if(bytes_received < 0) {
            perror("Error receiving from server");
            exit(-1);
        }

        buffer[bytes_received] = '\0';
        send(client_socket, buffer, strlen(buffer), 0);
    }

    // Close the sockets
    close(client_socket);
    close(server_socket);
}

int main(int argc, char *argv[]) {
    if(argc != 4) {
        printf("Usage: %s <local port> <remote host> <remote port>\n", argv[0]);
        exit(-1);
    }

    // Parse the command line arguments
    int local_port = atoi(argv[1]);
    char* remote_host = argv[2];
    int remote_port = atoi(argv[3]);

    // Create the local socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if(server_socket < 0) {
        perror("Unable to create socket");
        exit(-1);
    }

    // Build the local address
    struct sockaddr_in local_address;
    memset(&local_address, 0, sizeof(local_address));
    local_address.sin_family = AF_INET;
    local_address.sin_addr.s_addr = INADDR_ANY;
    local_address.sin_port = htons(local_port);

    // Bind the local socket to the local address
    if(bind(server_socket, (struct sockaddr*)&local_address, sizeof(local_address)) < 0) {
        perror("Unable to bind to local address");
        exit(-1);
    }

    // Listen for incoming connections
    if(listen(server_socket, 10) < 0) {
        perror("Error listening for incoming connections");
        exit(-1);
    }

    // Handle incoming connections
    printf("Proxy server running on port %d\n", local_port);
    while(1) {
        struct sockaddr_in client_address;
        socklen_t client_address_length = sizeof(client_address);
        int client_socket = accept(server_socket, (struct sockaddr*)&client_address, &client_address_length);
        if(client_socket < 0) {
            perror("Error accepting connection");
            exit(-1);
        }

        // Handle the incoming request from the client
        handle_server_connection(client_socket, remote_host, remote_port);
    }

    // Close the socket
    close(server_socket);

    return 0;
}