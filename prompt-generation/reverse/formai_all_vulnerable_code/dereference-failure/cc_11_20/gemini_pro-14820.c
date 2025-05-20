//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define DEFAULT_SERVER "www.google.com"
#define DEFAULT_PORT 80
#define DEFAULT_BUFFER_SIZE 1024
#define DEFAULT_ITERATIONS 10
#define DEFAULT_TIMEOUT 5

int main(int argc, char **argv) {
    // Parse arguments
    char *server = DEFAULT_SERVER;
    int port = DEFAULT_PORT;
    int buffer_size = DEFAULT_BUFFER_SIZE;
    int iterations = DEFAULT_ITERATIONS;
    int timeout = DEFAULT_TIMEOUT;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-s") == 0) {
            server = argv[++i];
        } else if (strcmp(argv[i], "-p") == 0) {
            port = atoi(argv[++i]);
        } else if (strcmp(argv[i], "-b") == 0) {
            buffer_size = atoi(argv[++i]);
        } else if (strcmp(argv[i], "-i") == 0) {
            iterations = atoi(argv[++i]);
        } else if (strcmp(argv[i], "-t") == 0) {
            timeout = atoi(argv[++i]);
        } else {
            fprintf(stderr, "Usage: %s [-s server] [-p port] [-b buffer size] [-i iterations] [-t timeout]\n", argv[0]);
            return EXIT_FAILURE;
        }
    }

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Set timeout
    struct timeval tv;
    tv.tv_sec = timeout;
    tv.tv_usec = 0;
    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv)) == -1) {
        perror("setsockopt");
        return EXIT_FAILURE;
    }

    // Connect to server
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    if (inet_pton(AF_INET, server, &servaddr.sin_addr) <= 0) {
        perror("inet_pton");
        return EXIT_FAILURE;
    }
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Send request
    char request[] = "GET / HTTP/1.1\r\nHost: www.google.com\r\n\r\n";
    if (send(sockfd, request, strlen(request), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive response
    char buffer[buffer_size];
    int total_bytes_received = 0;
    while (1) {
        int bytes_received = recv(sockfd, buffer, buffer_size, 0);
        if (bytes_received == -1) {
            perror("recv");
            return EXIT_FAILURE;
        } else if (bytes_received == 0) {
            break;
        }
        total_bytes_received += bytes_received;
    }

    // Calculate speed
    double speed = (double)total_bytes_received / timeout;
    printf("Speed: %.2f KB/s\n", speed);

    // Close socket
    close(sockfd);

    return EXIT_SUCCESS;
}