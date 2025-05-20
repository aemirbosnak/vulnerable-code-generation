//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>

#define BUFFER_SIZE 4096

void die(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void parse_response(char *response) {
    char *headers_end = strstr(response, "\r\n\r\n");
    if (headers_end) {
        *headers_end = '\0'; // Terminate headers
        printf("HTTP Response Headers:\n%s\n", response);
        printf("HTTP Response Body:\n%s\n", headers_end + 4); // Skip past "\r\n\r\n"
    } else {
        printf("Invalid Response Format\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *hostname = argv[1];
    const char *port = argv[2];
    int sock;
    struct sockaddr_in server_addr;
    struct hostent *he;

    // Create a socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        die("Socket creation failed");
    }

    // Get the host information
    if ((he = gethostbyname(hostname)) == NULL) {
        die("gethostbyname failed");
    }

    // Fill in the server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    memcpy(&server_addr.sin_addr, he->h_addr, he->h_length);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(port));

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        die("Connection failed");
    }

    // Prepare the HTTP GET request
    char request[BUFFER_SIZE];
    snprintf(request, sizeof(request),
             "GET / HTTP/1.1\r\n"
             "Host: %s\r\n"
             "Connection: close\r\n\r\n", hostname);

    // Send the request
    if (send(sock, request, strlen(request), 0) == -1) {
        die("Send failed");
    }
    
    // Receive the response
    char response[BUFFER_SIZE];
    int bytes_received;
    printf("Receiving response...\n");

    while ((bytes_received = recv(sock, response, sizeof(response) - 1, 0)) > 0) {
        response[bytes_received] = '\0'; // Null-terminate the string
        parse_response(response); // Parse and display the response
    }
    
    if (bytes_received == -1) {
        die("Receive failed");
    }

    printf("Connection closed.\n");
    close(sock);
    return 0;
}