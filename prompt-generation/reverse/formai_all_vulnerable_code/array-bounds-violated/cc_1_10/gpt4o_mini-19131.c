//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define SERVER_PORT 80
#define BUFFER_SIZE 1024

void die(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

char *create_get_request(const char *hostname, const char *resource) {
    char *request = malloc(BUFFER_SIZE);
    if (request == NULL) {
        die("Malloc failed");
    }
    
    snprintf(request, BUFFER_SIZE,
             "GET %s HTTP/1.1\r\n"
             "Host: %s\r\n"
             "Connection: close\r\n"
             "\r\n", resource, hostname);
    
    return request;
}

void send_request(const char *hostname, const char *resource) {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        die("Socket creation failed");
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = inet_addr(hostname);
    
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        close(sockfd);
        die("Connection to server failed");
    }

    char *request = create_get_request(hostname, resource);
    
    if (send(sockfd, request, strlen(request), 0) < 0) {
        free(request);
        close(sockfd);
        die("Failed to send request");
    }
    
    free(request);

    // Reading the response
    printf("Response:\n");
    while (1) {
        ssize_t n = recv(sockfd, buffer, sizeof(buffer) - 1, 0);
        if (n <= 0) {
            break;
        }
        buffer[n] = '\0'; // Null terminate buffer
        printf("%s", buffer);
    }
    
    close(sockfd);
}

void display_help() {
    printf("Usage: http_client <hostname> <resource>\n");
    printf("Example: http_client www.example.com /index.html\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        display_help();
        return EXIT_FAILURE;
    }

    const char *hostname = argv[1];
    const char *resource = argv[2];

    send_request(hostname, resource);
    
    return EXIT_SUCCESS;
}