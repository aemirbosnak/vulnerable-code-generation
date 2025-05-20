//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 8192
#define DEFAULT_PORT 80

void die(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

void parse_url(const char *url, char *host, char *path) {
    // Extract host and path from URL
    const char *http_prefix = "http://";
    const char *pos = strstr(url, http_prefix);
    if (pos) {
        pos += strlen(http_prefix);
    } else {
        pos = url;
    }

    char *slash = strchr(pos, '/');
    if (slash) {
        strncpy(host, pos, slash - pos);
        host[slash - pos] = '\0';
        strcpy(path, slash);
    } else {
        strcpy(host, pos);
        strcpy(path, "/");
    }
}

void http_get(const char *url) {
    char host[256];
    char path[256];
    parse_url(url, host, path);

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        die("socket creation failed");
    }

    // Resolve host
    struct hostent *server = gethostbyname(host);
    if (server == NULL) {
        die("no such host");
    }

    // Prepare server address structure
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    serv_addr.sin_port = htons(DEFAULT_PORT);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        die("connection failed");
    }

    // Create HTTP request
    char request[BUFFER_SIZE];
    snprintf(request, sizeof(request),
             "GET %s HTTP/1.1\r\n"
             "Host: %s\r\n"
             "Connection: close\r\n\r\n", 
             path, host);
    
    // Send request
    if (send(sockfd, request, strlen(request), 0) < 0) {
        die("failed to send request");
    }

    // Read response
    char response[BUFFER_SIZE];
    while (1) {
        ssize_t bytes_received = recv(sockfd, response, sizeof(response) - 1, 0);
        if (bytes_received < 0) {
            die("recv failed");
        }
        if (bytes_received == 0) {
            break; // Connection closed
        }

        response[bytes_received] = '\0'; // Null-terminate the response
        printf("%s", response); // Print response
    }

    // Clean up
    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <URL>\n", argv[0]);
        return EXIT_FAILURE;
    }

    http_get(argv[1]);

    return EXIT_SUCCESS;
}