//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main() {
    int sockfd, newsockfd, portno, addrlen;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in serv_addr, cli_addr;
    struct hostent *server;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Set server address
    portno = 8080;
    server = gethostbyname("localhost");
    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }

    // Receive data from server
    while (1) {
        bzero(buffer, BUFFER_SIZE);
        if (recv(sockfd, buffer, BUFFER_SIZE, 0) < 0) {
            perror("Error receiving data from server");
            exit(EXIT_FAILURE);
        }
        printf("%s", buffer);
    }

    // Close socket
    close(sockfd);

    return 0;
}