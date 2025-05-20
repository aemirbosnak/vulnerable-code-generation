//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 4096

void die(const char *msg) {
    perror(msg);
    exit(1);
}

void http_get(const char *host, const char *path) {
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *host_info;
    char request[BUFFER_SIZE];
    char response[BUFFER_SIZE];
    
    // Resolve the host name
    if ((host_info = gethostbyname(host)) == NULL) {
        die("gethostbyname");
    }
    
    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        die("socket");
    }

    // Set up server address struct
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80); // HTTP port
    memcpy(&server_addr.sin_addr, host_info->h_addr, host_info->h_length);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        die("connect");
    }

    // Create HTTP GET request
    snprintf(request, sizeof(request), "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, host);

    // Send request
    if (send(sockfd, request, strlen(request), 0) == -1) {
        die("send");
    }

    // Receive response
    while (1) {
        ssize_t length = recv(sockfd, response, sizeof(response) - 1, 0);
        if (length < 0) {
            die("recv");
        } else if (length == 0) {
            break; // Connection closed
        }
        response[length] = '\0'; // Null terminate the response
        printf("%s", response);
    }

    // Close socket
    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <URL>\n", argv[0]);
        exit(1);
    }

    char *url = argv[1];
    char *host = strtok(url, "/"); // Extract the host
    char *path = strchr(url, '/'); // Extract the path

    if (path == NULL) {
        path = "/";
    } else {
        // Advance path to the next character after the '/'
        path++;
    }

    http_get(host, path);
    return 0;
}