//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <errno.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 80 // HTTP port

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Please provide a URL as argument\n");
        exit(EXIT_FAILURE);
    }
    
    char *url = argv[1];
    char *hostname, *path;
    
    // Parse URL to get hostname and path
    if (strncmp(url, "http://", 7) == 0) {
        url += 7;
    }
    hostname = url;
    path = strchr(url, '/');
    if (path != NULL) {
        *path++ = '\0';
    }
    
    struct hostent *server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "Error: %s\n", hstrerror(h_errno));
        exit(EXIT_FAILURE);
    }
    
    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        exit(EXIT_FAILURE);
    }
    
    // Connect to server
    struct sockaddr_in serv_addr = {0};
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    if (connect(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting");
        exit(EXIT_FAILURE);
    }
    
    // Send HTTP request
    char request[256];
    snprintf(request, sizeof(request),
             "GET /%s HTTP/1.1\r\n"
             "Host: %s\r\n"
             "Connection: close\r\n"
             "\r\n",
             (path == NULL) ? "" : path, hostname);
    if (send(sockfd, request, strlen(request), 0) < 0) {
        perror("Error sending request");
        exit(EXIT_FAILURE);
    }
    
    // Receive response
    char buffer[1024];
    ssize_t nread;
    while ((nread = recv(sockfd, buffer, sizeof(buffer), 0)) > 0) {
        if (fwrite(buffer, sizeof(char), nread, stdout) != nread) {
            perror("Error writing to stdout");
            exit(EXIT_FAILURE);
        }
    }
    
    if (nread < 0) {
        perror("Error receiving response");
        exit(EXIT_FAILURE);
    }
    
    // Close socket
    close(sockfd);
    return 0;
}