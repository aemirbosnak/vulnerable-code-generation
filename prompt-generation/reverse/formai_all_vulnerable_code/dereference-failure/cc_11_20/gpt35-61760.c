//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define ERROR -1
#define MAX_CLIENTS 5

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s [PORT] [SERVER ADDRESS]\n", argv[0]);
        exit(ERROR);
    }

    // create proxy socket
    int proxy_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (proxy_socket == ERROR) {
        perror("Error: Failed to create socket.\n");
        exit(ERROR);
    }

    // set up the proxy server
    struct sockaddr_in proxy_address;
    proxy_address.sin_family = AF_INET;
    proxy_address.sin_port = htons(atoi(argv[1]));
    proxy_address.sin_addr.s_addr = inet_addr("127.0.0.1");

    // bind the socket to the address
    if (bind(proxy_socket, (struct sockaddr*)&proxy_address, sizeof(proxy_address)) == ERROR) {
        perror("Error: Failed to bind to address.\n");
        exit(ERROR);
    }

    // listen for incoming connections
    if (listen(proxy_socket, MAX_CLIENTS) == ERROR) {
        perror("Error: Failed to listen for connections.\n");
        exit(ERROR);
    }

    // accept incoming connections
    int client_socket = accept(proxy_socket, NULL, NULL);
    if (client_socket == ERROR) {
        perror("Error: Failed to accept connection.\n");
        exit(ERROR);
    }

    // connect to the server
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == ERROR) {
        perror("Error: Failed to create socket.\n");
        exit(ERROR);
    }

    // set up the server address
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(80);
    server_address.sin_addr.s_addr = inet_addr(argv[2]);

    // connect to the server
    if (connect(server_socket, (struct sockaddr*)&server_address, sizeof(server_address)) == ERROR) {
        perror("Error: Failed to connect to server.\n");
        exit(ERROR);
    }

    // start forwarding data between the client and the server
    char request[4096];
    int request_length;
    char response[4096];
    int response_length;
    int error = 0;
    while (!error) {
        // clear buffers
        memset(request, 0, sizeof(request));
        memset(response, 0, sizeof(response));

        // read data from the client
        request_length = read(client_socket, request, sizeof(request));
        if (request_length == ERROR) {
            perror("Error: Failed to read from client.\n");
            error = 1;
            break;
        }

        // forward the request to the server
        if (write(server_socket, request, request_length) == ERROR) {
            perror("Error: Failed to write to server.\n");
            error = 1;
            break;
        }

        // read data from the server
        response_length = read(server_socket, response, sizeof(response));
        if (response_length == ERROR) {
            perror("Error: Failed to read from server.\n");
            error = 1;
            break;
        }

        // forward the response to the client
        if (write(client_socket, response, response_length) == ERROR) {
            perror("Error: Failed to write to client.\n");
            error = 1;
            break;
        }
    }

    // close sockets
    close(client_socket);
    close(server_socket);
    close(proxy_socket);

    return 0;
}