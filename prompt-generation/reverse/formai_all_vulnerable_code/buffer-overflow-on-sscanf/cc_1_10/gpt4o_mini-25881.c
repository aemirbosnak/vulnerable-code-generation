//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> 
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 80
#define BUFFER_SIZE 4096
#define TIMEOUT 5

void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void create_request(char *request, const char *host, const char *endpoint) {
    snprintf(request, BUFFER_SIZE, "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", endpoint, host);
}

void paranoid_check(int status_code) {
    if (status_code >= 200 && status_code < 300) {
        printf("Success: Server responded with status code %d\n", status_code);
    } else if (status_code == 404) {
        fprintf(stderr, "Error: Resource not found (404)\n");
        exit(EXIT_FAILURE);
    } else if (status_code >= 500) {
        fprintf(stderr, "Error: Server side issue (status code %d)\n", status_code);
        exit(EXIT_FAILURE);
    } else {
        fprintf(stderr, "Error: Unexpected status code %d\n", status_code);
        exit(EXIT_FAILURE);
    }
}

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char request[BUFFER_SIZE];
    char response[BUFFER_SIZE];
    int received_bytes;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("Failed to create socket");
    }
    
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);

    if (inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr) <= 0) {
        error("Invalid address or address not supported");
    }
    
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("Connection to server failed");
    }

    create_request(request, SERVER_IP, "/");

    if (send(sockfd, request, strlen(request), 0) < 0) {
        error("Failed to send request");
    }

    // Set socket timeout
    struct timeval tv;
    tv.tv_sec = TIMEOUT;
    tv.tv_usec = 0;
    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof tv) < 0) {
        error("Error setting socket timeout");
    }

    received_bytes = recv(sockfd, response, BUFFER_SIZE - 1, 0);
    if (received_bytes < 0) {
        error("Failed to receive response");
    }
    response[received_bytes] = '\0';

    // Check HTTP response status
    int status_code;
    sscanf(response, "HTTP/1.1 %d", &status_code);
    paranoid_check(status_code);

    // Print the response
    printf("Received response:\n%s\n", response);

    close(sockfd);
    return 0;
}