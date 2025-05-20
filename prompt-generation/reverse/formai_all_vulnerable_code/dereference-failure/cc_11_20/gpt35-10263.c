//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_CONN 1000
#define BUFFER_SIZE 4096

struct Request {
    char method[16];
    char url[256];
    char version[16];
    char* headers;
    char* body;
};

struct Response {
    char version[16];
    int status;
    char* reason;
    char* headers;
    char* body;
};

int main(int argc, char **argv) {
    int port = 8080; // default port number
    char* address = "0.0.0.0"; // default IP address
    
    // parsing command line arguments
    if (argc > 1) {
        address = argv[1];
    }
    if (argc > 2) {
        port = atoi(argv[2]);
    }
    
    // creating a socket
    int server_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (server_socket < 0) {
        perror("socket() failed");
        exit(EXIT_FAILURE);
    }
    
    // bind the socket to IP address and port number
    struct sockaddr_in server_address = {0};
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    if (inet_pton(AF_INET, address, &server_address.sin_addr) <= 0) {
        perror("inet_pton() failed");
        exit(EXIT_FAILURE);
    }
    if (bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address)) < 0) {
        perror("bind() failed");
        exit(EXIT_FAILURE);
    }
    
    // listen for incoming connections
    if (listen(server_socket, MAX_CONN) < 0) {
        perror("listen() failed");
        exit(EXIT_FAILURE);
    }
    
    printf("Proxy server started on %s:%d\n", address, port);
    
    while (true) {
        struct sockaddr_in client_address = {0};
        socklen_t client_length = sizeof(client_address);
        
        // accept incoming connection
        int client_socket = accept(server_socket, (struct sockaddr*) &client_address, &client_length);
        if (client_socket < 0) {
            perror("accept() failed");
            continue;
        }
        
        // read request from client
        char buffer[BUFFER_SIZE] = {0};
        ssize_t num_read = recv(client_socket, buffer, BUFFER_SIZE, 0);
        if (num_read < 0) {
            perror("recv() failed");
            close(client_socket);
            continue;
        }
        buffer[num_read] = '\0';
        
        // parse request
        struct Request request = {0};
        sscanf(buffer, "%s %s %s", request.method, request.url, request.version);
        
        // forward request to server
        struct hostent* server = gethostbyname(request.url);
        if (!server) {
            perror("gethostbyname() failed");
            close(client_socket);
            continue;
        }
        
        int server_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        if (server_socket < 0) {
            perror("socket() failed");
            close(client_socket);
            continue;
        }
        
        struct sockaddr_in server_address = {0};
        server_address.sin_family = AF_INET;
        server_address.sin_port = htons(80);
        server_address.sin_addr = *((struct in_addr*) server->h_addr);
        if (connect(server_socket, (struct sockaddr*) &server_address, sizeof(server_address)) < 0) {
            perror("connect() failed");
            close(client_socket);
            continue;
        }
        
        if (send(server_socket, buffer, num_read, 0) < 0) {
            perror("send() failed");
            close(client_socket);
            close(server_socket);
            continue;
        }
        
        // read response from server
        num_read = recv(server_socket, buffer, BUFFER_SIZE, 0);
        if (num_read < 0) {
            perror("recv() failed");
            close(client_socket);
            close(server_socket);
            continue;
        }
        buffer[num_read] = '\0';
        
        // parse response
        struct Response response = {0};
        sscanf(buffer, "%s %d %s", response.version, &response.status, response.reason);
        char* headers_end = strstr(buffer, "\r\n\r\n");
        if (headers_end) {
            response.headers = strndup(buffer, headers_end - buffer + 4);
            response.body = strdup(headers_end + 4);
        } else {
            response.headers = strdup(buffer);
        }
        
        // send response to client
        if (send(client_socket, buffer, num_read, 0) < 0) {
            perror("send() failed");
            close(client_socket);
            close(server_socket);
            continue;
        }
        
        close(client_socket);
        close(server_socket);
    }
    
    close(server_socket);
    
    return 0;
}