//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 143
#define MAX_BUF 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server> <username>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int sockfd;
    struct sockaddr_in servaddr;
    char buf[MAX_BUF];
    int n;

    // Create a TCP socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Set up the server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        perror("inet_pton");
        return EXIT_FAILURE;
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Send the login command
    snprintf(buf, MAX_BUF, "A001 LOGIN %s\r\n", argv[2]);
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the login response
    if ((n = recv(sockfd, buf, MAX_BUF, 0)) < 0) {
        perror("recv");
        return EXIT_FAILURE;
    }
    buf[n] = '\0';
    printf("%s", buf);

    // Close the socket
    close(sockfd);

    return EXIT_SUCCESS;
}