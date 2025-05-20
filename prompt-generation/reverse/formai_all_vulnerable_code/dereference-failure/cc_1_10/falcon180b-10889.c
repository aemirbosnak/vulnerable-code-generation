//Falcon-180B DATASET v1.0 Category: Simple HTTP Proxy ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define BUFFER_SIZE 1024

// Function to send data over the socket
void send_response(int client_socket) {
    char *response = "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\nConnection: close\r\n\r\n";
    send(client_socket, response, strlen(response), 0);
}

// Function to receive data from the socket
void receive_request(int client_socket) {
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    int bytes_received = recv(client_socket, buffer, BUFFER_SIZE, 0);
    printf("Received request: %s\n", buffer);
}

// Function to handle client requests
void handle_client(int client_socket) {
    receive_request(client_socket);
    send_response(client_socket);
    close(client_socket);
}

// Function to start the server
void start_server(int port) {
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    if (bind(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error binding socket\n");
        exit(1);
    }

    if (listen(server_socket, 5) == -1) {
        printf("Error listening on socket\n");
        exit(1);
    }

    while (1) {
        int client_socket = accept(server_socket, NULL, NULL);
        if (client_socket == -1) {
            printf("Error accepting connection\n");
            exit(1);
        }

        printf("New client connected\n");
        handle_client(client_socket);
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage:./proxy <port>\n");
        exit(1);
    }

    int port = atoi(argv[1]);
    start_server(port);
    return 0;
}