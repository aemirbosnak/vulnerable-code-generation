//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 4096

// Function to create and send an HTTP GET request
void http_get(const char* host, const char* path) {
    int sockfd;
    struct sockaddr_in server_address;
    struct hostent *host_info;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Could not create socket");
        exit(EXIT_FAILURE);
    }

    // Get host information
    host_info = gethostbyname(host);
    if (host_info == NULL) {
        fprintf(stderr, "Could not resolve host: %s\n", host);
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Prepare the server address structure
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(80);
    memcpy(&server_address.sin_addr, host_info->h_addr_list[0], host_info->h_length);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        perror("Connection to the server failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Prepare the GET request
    char request[BUFFER_SIZE];
    snprintf(request, sizeof(request),
             "GET %s HTTP/1.1\r\n"
             "Host: %s\r\n"
             "Connection: close\r\n\r\n",
             path, host);

    // Send the request
    if (send(sockfd, request, strlen(request), 0) < 0) {
        perror("Failed to send request");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Read the response
    char response[BUFFER_SIZE];
    int bytes_received;
    printf("Response from %s:\n", host);
    while ((bytes_received = recv(sockfd, response, sizeof(response) - 1, 0)) > 0) {
        response[bytes_received] = '\0'; // Null-terminate the response
        printf("%s", response);
    }

    if (bytes_received < 0) {
        perror("Failed to receive response");
    }

    // Cleanup
    close(sockfd);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <host> <path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char* host = argv[1];
    const char* path = argv[2];

    http_get(host, path);

    return 0;
}