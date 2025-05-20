//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define BUFFER_SIZE 4096

typedef struct {
    char *host;
    int port;
    char *path;
    char *method;
} HttpRequest;

void config_http_request(HttpRequest *request, char *host, int port, char *path, char *method) {
    request->host = host;
    request->port = port;
    request->path = path;
    request->method = method;
}

void print_http_response(const char *response) {
    printf("HTTP Response:\n%s\n", response);
}

int send_http_request(HttpRequest *request) {
    int sock;
    struct sockaddr_in server_addr;
    char *request_str;
    char buffer[BUFFER_SIZE];

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        return -1;
    }
    
    // Set up server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(request->port);
    
    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, request->host, &server_addr.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported");
        return -1;
    }

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        return -1;
    }

    // Prepare HTTP request
    asprintf(&request_str, "%s %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", 
             request->method, request->path, request->host);

    // Send request
    send(sock, request_str, strlen(request_str), 0);
    free(request_str);

    // Read response
    memset(buffer, 0, BUFFER_SIZE);
    int bytes_received = recv(sock, buffer, BUFFER_SIZE - 1, 0);
    if (bytes_received > 0) {
        buffer[bytes_received] = '\0'; // Null-terminate the received data
    } else {
        perror("Failed to receive response");
    }

    // Close socket
    close(sock);

    // Print response
    print_http_response(buffer);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <host> <port> <path> <method>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    HttpRequest request;
    config_http_request(&request, argv[1], atoi(argv[2]), argv[3], argv[4]);

    if (send_http_request(&request) != 0) {
        exit(EXIT_FAILURE);
    }

    return 0;
}