//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>

#define BUFFER_SIZE 4096

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void parse_url(const char *url, char *host, char *path) {
    char *start = strstr(url, "://");
    if (start) {
        start += 3; // Skip to the host
    } else {
        start = (char *)url; // No scheme, just host
    }
    
    char *slash = strchr(start, '/');
    
    if (slash) {
        strncpy(host, start, slash - start);
        host[slash - start] = '\0';
        strcpy(path, slash); // path starts from the first '/'
    } else {
        strcpy(host, start);
        path[0] = '\0'; // No path.
    }
}

void create_http_request(char *request, const char *host, const char *path) {
    sprintf(request, "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, host);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <URL>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    char host[256];
    char path[256];
    
    parse_url(argv[1], host, path);
    
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *server;
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Failed to create socket");
    }
    
    server = gethostbyname(host);
    if (server == NULL) {
        error("No such host");
    }
    
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy(&server_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    server_addr.sin_port = htons(80);
    
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Connection failed");
    }
    
    char request[BUFFER_SIZE];
    create_http_request(request, host, path);
    
    if (send(sockfd, request, strlen(request), 0) < 0) {
        error("Failed to send request");
    }
    
    char response[BUFFER_SIZE];
    int received;
    
    while ((received = recv(sockfd, response, BUFFER_SIZE - 1, 0)) > 0) {
        response[received] = '\0'; // Null-terminate the response
        printf("%s", response); // Print the response
    }
    
    if (received < 0) {
        error("Failed to receive data");
    }
    
    close(sockfd);
    return 0;
}