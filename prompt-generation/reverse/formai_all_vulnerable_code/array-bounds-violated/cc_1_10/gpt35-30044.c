//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: introspective
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1000

int main(int argc, char *argv[]) {
    int sockfd, num_bytes;
    char buffer[MAX_BUFFER_SIZE];
    struct addrinfo hints, *result;

    if (argc != 3) {
        printf("Usage: %s <hostname> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Set up hints for getaddrinfo
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    // Get IP address of the server
    if (getaddrinfo(argv[1], argv[2], &hints, &result) != 0) {
        printf("Could not get IP address of server.\n");
        exit(EXIT_FAILURE);
    }

    // Create socket
    sockfd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (sockfd == -1) {
        printf("Could not create socket.\n");
        freeaddrinfo(result);
        exit(EXIT_FAILURE);
    }

    // Connect to server
    if (connect(sockfd, result->ai_addr, result->ai_addrlen) == -1) {
        printf("Could not connect to server.\n");
        freeaddrinfo(result);
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Receive response from server
    while ((num_bytes = recv(sockfd, buffer, MAX_BUFFER_SIZE, 0)) > 0) {
        buffer[num_bytes] = '\0'; // Append null terminator to buffer
        printf("%s", buffer);
    }

    // Clean up
    freeaddrinfo(result);
    close(sockfd);

    return 0;
}