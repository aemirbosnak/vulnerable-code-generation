//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Define constants for HTTP method types
#define HTTP_GET "GET"
#define HTTP_POST "POST"
#define HTTP_PUT "PUT"
#define HTTP_DELETE "DELETE"

// Define HTTP response codes we are interested in
#define HTTP_OK 200
#define HTTP_CREATED 201
#define HTTP_NOT_FOUND 404
#define HTTP_SERVER_ERROR 500

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Please provide a hostname\n");
        exit(EXIT_FAILURE);
    }
    
    char *hostname = argv[1];
    int port = 80; // default port for HTTP
    
    char buffer[1000];
    memset(buffer, 0, sizeof(buffer));
    
    // Establish a TCP connection with the server
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }
    
    struct hostent *host = gethostbyname(hostname);
    if (!host) {
        printf("Invalid hostname\n");
        exit(EXIT_FAILURE);
    }
    
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr)); // zero out the struct
    
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    memcpy(&server_addr.sin_addr.s_addr, host->h_addr_list[0], host->h_length);
    
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }
    
    printf("Connected to server %s\n", hostname);
    
    // Prepare the HTTP request
    char *request = "GET / HTTP/1.1\r\n"
                    "Host: %s\r\n"
                    "Connection: close\r\n"
                    "\r\n";
    sprintf(buffer, request, hostname);
    int req_len = strlen(buffer);
    
    // Send the request to the server
    int sent = send(sock, buffer, req_len, 0);
    if (sent < 0) {
        perror("Error sending request");
        exit(EXIT_FAILURE);
    }
    
    // Receive the response from the server
    int total = 0;
    int received = 0;
    
    while (1) {
        memset(buffer, 0, sizeof(buffer));
        received = recv(sock, buffer, sizeof(buffer), 0);
        
        if (received < 0) {
            perror("Error receiving response");
            exit(EXIT_FAILURE);
        } else if (received == 0) {
            break; // connection closed by server
        } else {
            total += received;
            printf("%s", buffer);
        }
    }
    
    // Check the status code of the response
    char *status_code = strstr(buffer, "HTTP/1.1");
    if (!status_code) {
        printf("Invalid response from server\n");
        exit(EXIT_FAILURE);
    }
    
    int code = atoi(status_code + 9); // add 9 to skip "HTTP/1.1 "
    
    switch (code) {
        case HTTP_OK:
            printf("Request successful (200 OK)\n");
            break;
        case HTTP_CREATED:
            printf("Request successful (201 Created)\n");
            break;
        case HTTP_NOT_FOUND:
            printf("Request failed (404 Not Found)\n");
            break;
        case HTTP_SERVER_ERROR:
            printf("Request failed (500 Internal Server Error)\n");
            break;
        default:
            printf("Request failed (%d)\n", code);
            break;
    }
    
    // Clean up and exit
    close(sock);
    printf("Connection closed\n");
    exit(EXIT_SUCCESS);
}