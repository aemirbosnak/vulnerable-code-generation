//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define MAX_BUF 1024

void send_request(int sockfd, const char *hostname, const char *path) {
    char request[MAX_BUF];
    snprintf(request, sizeof(request),
             "GET %s HTTP/1.1\r\n"
             "Host: %s\r\n"
             "Connection: close\r\n"
             "\r\n", path, hostname);
    send(sockfd, request, strlen(request), 0);
}

void receive_response(int sockfd) {
    char buffer[MAX_BUF];
    int received_bytes;

    while ((received_bytes = recv(sockfd, buffer, sizeof(buffer) - 1, 0)) > 0) {
        buffer[received_bytes] = '\0'; // Null-terminate buffer for safe printing
        printf("%s", buffer);
    }
}

void http_client(const char *hostname, const char *path) {
    int sockfd;
    struct sockaddr_in server_addr;

    // Setting up the socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Failed to create socket, oh woe!");
        exit(EXIT_FAILURE);
    }

    // Preparing the sockaddr_in structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80); // HTTP port 80
    server_addr.sin_addr.s_addr = inet_addr("93.184.216.34"); // Example: example.com

    // Connecting to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed, alas!");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Sending the request
    send_request(sockfd, hostname, path);
    printf("Request sent for %s and %s, 'tis a tale of love and woe!\n", hostname, path);

    // Receiving and displaying the response
    printf("Receiving response from our dear server...\n");
    receive_response(sockfd);

    // Closing the socket
    close(sockfd);
    printf("The connection is severed, a tragic end...\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *hostname = argv[1];
    const char *path = argv[2];
    
    // We will embark upon this journey, dear friends
    printf("To connect or not to connect, that is the question...\n");
    
    http_client(hostname, path);

    // Final curtain falls on the stage of our program
    return EXIT_SUCCESS;
}