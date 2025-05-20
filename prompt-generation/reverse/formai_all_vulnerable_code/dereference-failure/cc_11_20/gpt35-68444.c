//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/wait.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

int main(int argc, char *argv[]) {
    int sockfd, new_sockfd, status, pid;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len;
    char request[1024];
    char *ip_addr;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Error creating socket: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Bind socket
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        fprintf(stderr, "Error binding socket: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(sockfd, 5) < 0) {
        fprintf(stderr, "Error listening on socket: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    printf("HTTP Proxy server listening on port %i...\n", PORT);

    while (1) {
        // Accept incoming connection
        client_len = sizeof(client_addr);
        new_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &client_len);
        if (new_sockfd < 0) {
            fprintf(stderr, "Error accepting connection: %s\n", strerror(errno));
            exit(EXIT_FAILURE);
        }

        ip_addr = inet_ntoa(client_addr.sin_addr);
        printf("Connection accepted from %s\n", ip_addr);

        pid = fork();
        if (pid < 0) {
            fprintf(stderr, "Error creating process: %s\n", strerror(errno));
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            // Process HTTP request
            memset(request, 0, sizeof(request));
            status = read(new_sockfd, request, sizeof(request) - 1);
            if (status < 0) {
                fprintf(stderr, "Error reading request: %s\n", strerror(errno));
                exit(EXIT_FAILURE);
            }

            printf("\nIncoming Request:\n%s\n", request);

            // Check for malicious content
            if (strstr(request, "User-Agent: curl/") != NULL ||
                strstr(request, "User-Agent: Wget/") != NULL ||
                strstr(request, "User-Agent: Mozilla/5.0 (Windows NT 10.0; Win64; x64)") != NULL) {
                printf("Malicious user agent detected from %s\n", ip_addr);
                exit(EXIT_FAILURE);
            }

            // Forward request to server
            status = write(new_sockfd, request, strlen(request));
            if (status < 0) {
                fprintf(stderr, "Error writing request: %s\n", strerror(errno));
                exit(EXIT_FAILURE);
            }

            // Read response from server
            memset(request, 0, sizeof(request));
            status = read(new_sockfd, request, sizeof(request) - 1);
            if (status < 0) {
                fprintf(stderr, "Error reading response: %s\n", strerror(errno));
                exit(EXIT_FAILURE);
            }

            printf("\nOutgoing Response:\n%s\n", request);

            // Forward response to client
            status = write(new_sockfd, request, strlen(request));
            if (status < 0) {
                fprintf(stderr, "Error writing response: %s\n", strerror(errno));
                exit(EXIT_FAILURE);
            }

            // Close socket and exit child process
            close(new_sockfd);
            exit(EXIT_SUCCESS);
        } else {
            // Wait for child process to exit
            wait(NULL);
            printf("Connection closed with %s\n", ip_addr);
            close(new_sockfd);
        }
    }

    close(sockfd);
    return 0;
}