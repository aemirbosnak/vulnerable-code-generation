//Code Llama-13B DATASET v1.0 Category: Network Ping Test ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in servaddr;
    char *host;
    char *port;
    char *message;
    char recvbuf[1024];
    int n;

    // check the number of arguments
    if (argc != 4) {
        printf("Usage: %s <host> <port> <message>\n", argv[0]);
        exit(1);
    }

    // get the host and port
    host = argv[1];
    port = argv[2];
    message = argv[3];

    // create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    // initialize the server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(port));
    if (inet_pton(AF_INET, host, &servaddr.sin_addr) <= 0) {
        printf("Error: invalid host or port\n");
        exit(1);
    }

    // connect to the server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    // send the message
    n = send(sockfd, message, strlen(message), 0);
    if (n < 0) {
        printf("Error sending message\n");
        exit(1);
    }

    // receive the response
    n = recv(sockfd, recvbuf, 1024, 0);
    if (n < 0) {
        printf("Error receiving response\n");
        exit(1);
    }

    // print the response
    printf("Response: %s\n", recvbuf);

    // close the socket
    close(sockfd);

    return 0;
}