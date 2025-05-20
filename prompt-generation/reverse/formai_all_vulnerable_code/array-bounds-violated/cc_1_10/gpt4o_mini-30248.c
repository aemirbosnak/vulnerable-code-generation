//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define BUFFER_SIZE 4096
#define PORT 80

void http_get_request(const char *hostname, const char *path) {
    int sockfd;
    struct sockaddr_in server_addr;
    char request[BUFFER_SIZE];
    char response[BUFFER_SIZE];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr(hostname);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Failed to connect to the server");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    snprintf(request, sizeof(request),
             "GET %s HTTP/1.1\r\n"
             "Host: %s\r\n"
             "Connection: close\r\n\r\n", 
             path, hostname);

    if (send(sockfd, request, strlen(request), 0) < 0) {
        perror("Failed to send request");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    printf("Request sent:\n%s\n", request);
    printf("Waiting for response...\n");

    int received_bytes;
    while ((received_bytes = recv(sockfd, response, sizeof(response) - 1, 0)) > 0) {
        response[received_bytes] = '\0'; // Null terminate the response
        printf("%s", response); // Display the response
    }

    if (received_bytes < 0) {
        perror("Failed to receive response");
    }

    close(sockfd);
    printf("\nResponse received. Connection closed peacefully.\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *hostname = argv[1];
    const char *path = argv[2];

    printf("A peaceful HTTP client is starting...\n");
    http_get_request(hostname, path);
    printf("The journey has ended. Thank you for using our HTTP client.\n");

    return EXIT_SUCCESS;
}