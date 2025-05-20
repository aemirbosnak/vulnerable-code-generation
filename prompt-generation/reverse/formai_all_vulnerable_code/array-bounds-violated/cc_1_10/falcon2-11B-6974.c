//Falcon2-11B DATASET v1.0 Category: Internet Speed Test Application ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAXLINE 1024

int main(void) {
    int sockfd, n;
    struct sockaddr_in servaddr;
    char buffer[MAXLINE];

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Specify the server address
    memset((char *)&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(80);
    servaddr.sin_addr.s_addr = inet_addr("www.google.com");

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    printf("Testing internet speed...\n");

    // Send a request to the server
    send(sockfd, "GET / HTTP/1.1\r\nHost: www.google.com\r\n\r\n", strlen("GET / HTTP/1.1\r\nHost: www.google.com\r\n\r\n"), 0);

    // Receive and print the server response
    while ((n = recv(sockfd, buffer, MAXLINE, 0)) > 0) {
        buffer[n] = '\0';
        printf("%s", buffer);
    }

    printf("\n");

    // Close the socket
    close(sockfd);

    return 0;
}