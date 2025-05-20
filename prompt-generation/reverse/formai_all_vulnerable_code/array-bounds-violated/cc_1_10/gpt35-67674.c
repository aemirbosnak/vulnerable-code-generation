//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: beginner-friendly
#include <stdio.h>  // for standard input/output operations
#include <stdlib.h> // for atoi() function
#include <string.h> // for string operations
#include <sys/socket.h> // for socket()
#include <netinet/in.h> // for struct sockaddr_in 
#include <arpa/inet.h> // for inet_pton()
#include <unistd.h> // for close()

// Buffer size for received data
#define BUFFER_SIZE 1024

// Function to print error and exit program
void perror_exit(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    
    // Check if command line argument is provided
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <IP Address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    // Convert IP address from string to network representation
    struct sockaddr_in sa;
    if (inet_pton(AF_INET, argv[1], &(sa.sin_addr)) != 1) {
        perror_exit("inet_pton");
    }
    
    // Create socket to connect to specified IP address
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror_exit("socket");
    }
    
    // Specify port and IP address to connect to
    sa.sin_port = htons(80);
    sa.sin_family = AF_INET;

    // Connect to socket
    if (connect(sockfd, (struct sockaddr *)&sa, sizeof(sa)) == -1) {
        perror_exit("connect");
    }

    // Build HTTP request
    char request[BUFFER_SIZE];
    snprintf(request, BUFFER_SIZE, "GET / HTTP/1.0\nHost: %s\n\n", argv[1]);

    // Send HTTP request
    ssize_t sent = send(sockfd, request, strlen(request), 0);
    if (sent == -1) {
        perror_exit("send");
    }

    // Receive response
    char response[BUFFER_SIZE];
    ssize_t received = 0;
    while ((received = recv(sockfd, response, BUFFER_SIZE - 1, 0)) > 0) {
        response[received] = '\0';
        printf("%s", response);
    }
    if (received == -1) {
        perror_exit("recv");
    }

    // Close socket
    if (close(sockfd) == -1) {
        perror_exit("close");
    }

    return EXIT_SUCCESS;
}