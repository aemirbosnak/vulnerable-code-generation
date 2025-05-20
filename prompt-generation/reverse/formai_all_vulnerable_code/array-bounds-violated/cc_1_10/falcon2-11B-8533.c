//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>

#define MAX_PACKET 65507
#define BUFFER_SIZE 1024
#define PORT 80

int main(int argc, char *argv[])
{
    char buffer[BUFFER_SIZE];
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    // Validate input arguments
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <host>\n", argv[0]);
        return 1;
    }

    // Parse hostname or IP address from command line argument
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Host not found\n");
        return 1;
    }

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Failed to create socket\n");
        return 1;
    }

    // Set up server address
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(PORT);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        fprintf(stderr, "Failed to connect\n");
        return 1;
    }

    // Send ping request
    sprintf(buffer, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", argv[1]);
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        fprintf(stderr, "Failed to send ping request\n");
        return 1;
    }

    // Receive server response
    bzero(buffer, BUFFER_SIZE);
    n = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
    if (n < 0) {
        fprintf(stderr, "Failed to receive server response\n");
        return 1;
    }

    // Check server response code
    if (buffer[n-1]!= '\r') {
        fprintf(stderr, "Invalid server response\n");
        return 1;
    }
    buffer[n-1] = '\0';

    // Print server response
    printf("Server response: %s\n", buffer);

    // Close socket
    close(sockfd);

    return 0;
}