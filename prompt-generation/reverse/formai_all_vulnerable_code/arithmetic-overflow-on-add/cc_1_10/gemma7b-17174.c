//Gemma-7B DATASET v1.0 Category: Port Scanner ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>

#define LISTEN_PORT 8888
#define BUFFER_SIZE 1024

int main() {
    int sockfd, newsockfd, port, clientlen, i, buflen, recvlen;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in serv_addr, client_addr;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(LISTEN_PORT));
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Bind the socket to a port
    serv_addr.sin_port = htons(LISTEN_PORT);
    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error binding socket");
        exit(1);
    }

    // Listen for clients
    listen(sockfd, &clientlen);

    // Accept a client connection
    newsockfd = accept(sockfd, (struct sockaddr *)&client_addr, &clientlen);
    if (newsockfd < 0) {
        perror("Error accepting client connection");
        exit(1);
    }

    // Receive data from the client
    buflen = recvlen = 0;
    while ((recvlen = recv(newsockfd, buffer, BUFFER_SIZE, 0)) > 0) {
        buflen += recvlen;
        printf("Received %d bytes of data: %s\n", recvlen, buffer);
    }

    // Send data to the client
    printf("Sent a total of %d bytes of data: ", buflen);
    send(newsockfd, buffer, buflen, 0);

    // Close the client connection
    close(newsockfd);

    return 0;
}