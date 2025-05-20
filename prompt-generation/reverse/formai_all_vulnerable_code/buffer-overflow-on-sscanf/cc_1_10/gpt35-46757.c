//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFSIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[BUFSIZE];
    char hostname[BUFSIZE];
    char path[BUFSIZE];
    char request[BUFSIZE];
    char response[BUFSIZE];
    
    // Retrieve command line arguments
    if (argc < 2) {
        printf("Usage: %s <URL>\n", argv[0]);
        exit(1);
    }

    // Parse URL to get hostname and path
    sscanf(argv[1], "http://%[^/]/%s", hostname, path);

    // Set up socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }
    
    // Set up server address
    portno = 80;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    if (inet_pton(AF_INET, hostname, &serv_addr.sin_addr) <= 0) {
        perror("ERROR invalid hostname");
        exit(1);
    }

    // Connect to server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }
    
    // Construct HTTP request
    sprintf(request, "GET /%s HTTP/1.1\r\nHost: %s\r\n\r\n", path, hostname);

    // Send HTTP request to server
    n = send(sockfd, request, strlen(request), 0);
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    // Receive and print HTTP response from server
    memset(response, 0, sizeof(response));
    while ((n = recv(sockfd, buffer, BUFSIZE - 1, 0)) > 0) {
        buffer[n] = '\0';
        strcat(response, buffer);
    }
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    printf("%s\n", response);

    // Close socket
    close(sockfd);
    
    return 0;
}