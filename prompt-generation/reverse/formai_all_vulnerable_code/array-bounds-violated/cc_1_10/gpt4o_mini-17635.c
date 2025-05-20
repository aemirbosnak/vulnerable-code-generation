//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define MAX_BUFFER 1024
#define PORT 80

void print_header(const char *header) {
    printf("\n=== HTTP Response Header ===\n");
    printf("%s\n", header);
    printf("============================\n");
}

void print_body(const char *body) {
    printf("\n=== HTTP Response Body ===\n");
    printf("%s\n", body);
    printf("============================\n");
}

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server;
    char buffer[MAX_BUFFER];
    char request[MAX_BUFFER];
    
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <http://example.com>\n", argv[0]);
        exit(1);
    }

    char *url = argv[1];
    char *host = NULL;
    char *path = "/";

    // Find the host and path
    if (strncmp(url, "http://", 7) == 0) {
        host = url + 7;  // Skip "http://"
    }

    char *path_start = strchr(host, '/');
    if (path_start) {
        *path_start = '\0';
        path = path_start;  // Keep the path
    }

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        error("Failed to create socket");
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = inet_addr("93.184.216.34"); // Example IP (example.com)

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        error("Connection failed");
    }

    // Create HTTP GET request
    snprintf(request, sizeof(request),
             "GET %s HTTP/1.1\r\n"
             "Host: %s\r\n"
             "Connection: close\r\n\r\n",
             path, host);

    // Send request
    if (send(sock, request, strlen(request), 0) < 0) {
        error("Send failed");
    }

    // Receive response
    int received_length;
    char response[MAX_BUFFER];
    char header[MAX_BUFFER];
    char body[MAX_BUFFER];
    int is_header = 1;
    int header_length = 0;

    while ((received_length = recv(sock, response, sizeof(response) - 1, 0)) > 0) {
        response[received_length] = '\0'; // Null-terminate the buffer
        if (is_header) {
            // Find the header end
            char *body_start = strstr(response, "\r\n\r\n");
            if (body_start) {
                int header_size = body_start - response + 4;
                memcpy(header, response, header_size);
                header[header_size] = '\0';
                print_header(header);
                
                // Process body
                strcpy(body, body_start + 4); // Skip over "\r\n\r\n"
                is_header = 0;
            } else {
                memcpy(header + header_length, response, received_length);
                header_length += received_length;
                header[header_length] = '\0';
            }
        } else {
            strcat(body, response);
        }
    }

    if (!is_header) {
        print_body(body);
    }

    // Close socket
    close(sock);
    return 0;
}