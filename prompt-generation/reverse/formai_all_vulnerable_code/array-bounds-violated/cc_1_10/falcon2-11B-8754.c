//Falcon2-11B DATASET v1.0 Category: Internet Speed Test Application ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main() {
    // Create a socket
    int sockfd;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(EXIT_FAILURE);
    }

    // Set up the sockaddr_in structure
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(8080);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("ERROR connecting");
        exit(EXIT_FAILURE);
    }

    // Send a request
    char request[100];
    sprintf(request, "GET / HTTP/1.1\r\nHost: 127.0.0.1:8080\r\n\r\n");
    if (send(sockfd, request, strlen(request), 0) < 0) {
        perror("ERROR sending request");
        exit(EXIT_FAILURE);
    }

    // Receive the response
    char response[1000];
    int response_length = recv(sockfd, response, sizeof(response) - 1, 0);
    response[response_length] = '\0';
    if (response_length <= 0) {
        perror("ERROR receiving response");
        exit(EXIT_FAILURE);
    }

    // Print the response
    printf("%s\n", response);

    // Close the socket
    close(sockfd);

    return 0;
}