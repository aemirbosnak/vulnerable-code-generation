//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <time.h>
#include <unistd.h>

#define DEFAULT_SERVER_PORT 80
#define DEFAULT_SERVER_NAME "www.google.com"
#define DEFAULT_TIMEOUT_SECS 1

int main(int argc, char *argv[]) {
    // Parse command line arguments
    char *server_name = DEFAULT_SERVER_NAME;
    int server_port = DEFAULT_SERVER_PORT;
    int timeout_secs = DEFAULT_TIMEOUT_SECS;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-n") == 0) {
            if (i + 1 < argc) {
                server_name = argv[i + 1];
            }
        } else if (strcmp(argv[i], "-p") == 0) {
            if (i + 1 < argc) {
                server_port = atoi(argv[i + 1]);
            }
        } else if (strcmp(argv[i], "-t") == 0) {
            if (i + 1 < argc) {
                timeout_secs = atoi(argv[i + 1]);
            }
        } else {
            printf("Usage: %s [-n server_name] [-p server_port] [-t timeout_secs]\n", argv[0]);
            return 1;
        }
    }

    // Resolve server name to IP address
    struct addrinfo hints, *result;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    int rc = getaddrinfo(server_name, NULL, &hints, &result);
    if (rc != 0) {
        fprintf(stderr, "getaddrinfo failed: %s\n", gai_strerror(rc));
        return 1;
    }

    // Create a socket
    int sockfd = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
    if (sockfd == -1) {
        perror("socket failed");
        freeaddrinfo(result);
        return 1;
    }

    // Set socket timeout
    struct timeval timeout;
    timeout.tv_sec = timeout_secs;
    timeout.tv_usec = 0;
    rc = setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout));
    if (rc == -1) {
        perror("setsockopt failed");
        close(sockfd);
        freeaddrinfo(result);
        return 1;
    }

    // Connect to server
    rc = connect(sockfd, result->ai_addr, result->ai_addrlen);
    freeaddrinfo(result);
    if (rc == -1) {
        perror("connect failed");
        close(sockfd);
        return 1;
    }

    // Send a request to the server
    char request[] = "GET / HTTP/1.1\r\nHost: www.google.com\r\n\r\n";
    rc = send(sockfd, request, strlen(request), 0);
    if (rc == -1) {
        perror("send failed");
        close(sockfd);
        return 1;
    }

    // Receive a response from the server
    char response[1024];
    rc = recv(sockfd, response, sizeof(response), 0);
    if (rc == -1) {
        perror("recv failed");
        close(sockfd);
        return 1;
    }

    // Close the socket
    close(sockfd);

    // Parse the response
    char *status_line = strtok(response, "\r\n");
    if (status_line == NULL) {
        printf("Invalid response from server\n");
        return 1;
    }

    // Print the response
    printf("%s\n", response);

    return 0;
}