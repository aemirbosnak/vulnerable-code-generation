//Falcon-180B DATASET v1.0 Category: Building a HTTP Client ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <host> <port>\n", argv[0]);
        return 1;
    }

    char *host = argv[1];
    char *port = argv[2];
    int sockfd;
    struct sockaddr_in servaddr;
    int err;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    // Set up server address structure
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(port));
    err = inet_pton(AF_INET, host, &servaddr.sin_addr);
    if (err!= 0) {
        printf("Error parsing IP address\n");
        close(sockfd);
        return 1;
    }

    // Connect to server
    err = connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
    if (err == -1) {
        printf("Error connecting to server\n");
        close(sockfd);
        return 1;
    }

    printf("Connected to server\n");

    // Send request
    char request[BUFFER_SIZE];
    sprintf(request, "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", host);
    send(sockfd, request, strlen(request), 0);

    // Receive response
    char buffer[BUFFER_SIZE];
    int bytes_received = 0;
    while ((bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("%s", buffer);
    }

    close(sockfd);
    return 0;
}