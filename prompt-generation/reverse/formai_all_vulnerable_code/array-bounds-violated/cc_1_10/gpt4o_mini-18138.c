//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 80
#define SERVER_IP "93.184.216.34" // Example: IP of example.com
#define MAX_BUFFER 1024

void handle_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int create_socket() {
    int sock;
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        handle_error("Socket creation failed");
    }
    return sock;
}

struct sockaddr_in setup_server_address() {
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    
    if (inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr) <= 0) {
        handle_error("Invalid address/Address not supported");
    }
    
    return server_addr;
}

void create_http_request(char *request_buffer, const char *path) {
    snprintf(request_buffer, MAX_BUFFER,
             "GET %s HTTP/1.1\r\n"
             "Host: %s\r\n"
             "Connection: close\r\n"
             "\r\n", path, SERVER_IP);
}

void send_request(int sock, const char *request) {
    if (send(sock, request, strlen(request), 0) < 0) {
        handle_error("Send failed");
    }
}

void receive_response(int sock) {
    char buffer[MAX_BUFFER];
    int bytes_received;

    while ((bytes_received = recv(sock, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[bytes_received] = '\0'; // Null-terminate the buffer
        printf("%s", buffer);
    }
}

void close_socket(int sock) {
    if (close(sock) < 0) {
        handle_error("Socket close failed");
    }
}

int main() {
    // Create a new socket
    int sock = create_socket();
    
    // Set up the server address structure
    struct sockaddr_in server_addr = setup_server_address();
    
    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        handle_error("Connection failed");
    }
    
    // Prepare HTTP GET request
    char request[MAX_BUFFER];
    const char *path = "/";
    create_http_request(request, path);
    
    // Send the HTTP request
    send_request(sock, request);
    
    // Receive the HTTP response
    receive_response(sock);
    
    // Close the socket
    close_socket(sock);
    
    return 0;
}