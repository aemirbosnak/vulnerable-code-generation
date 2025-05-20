//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 4096

void error(const char *msg) {
    perror(msg);
    exit(1);
}

void http_client(const char *hostname, const char *path) {
    int sockfd;
    struct sockaddr_in server;
    struct hostent *host;
    char request[BUFFER_SIZE], response[BUFFER_SIZE];
    int bytes_received;

    // Get host by name
    host = gethostbyname(hostname);
    if (host == NULL) {
        error("ERROR, no such host");
    }

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    // Setup server struct
    bzero((char *)&server, sizeof(server));
    server.sin_family = AF_INET;
    bcopy((char *)host->h_addr, (char *)&server.sin_addr.s_addr, host->h_length);
    server.sin_port = htons(80);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        error("ERROR connecting");
    }

    // Format HTTP GET request
    snprintf(request, sizeof(request), "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", path, hostname);

    // Send the request to the server
    int bytes_sent = send(sockfd, request, strlen(request), 0);
    if (bytes_sent < 0) {
        error("ERROR sending request");
    }
    
    // Receive response
    printf("Response from server:\n");
    while ((bytes_received = recv(sockfd, response, sizeof(response) - 1, 0)) > 0) {
        response[bytes_received] = '\0';  // Null terminate the response
        printf("%s", response);
    }

    // Check for reception errors
    if (bytes_received < 0) {
        error("ERROR reading response");
    }

    // Close the socket
    close(sockfd);
}

int main(int argc, char *argv[]) {
    // Ensure that the program is started with correct arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <path>\n", argv[0]);
        exit(1);
    }

    const char *hostname = argv[1];
    const char *path = argv[2];

    // Call the HTTP client function
    http_client(hostname, path);

    return 0;
}