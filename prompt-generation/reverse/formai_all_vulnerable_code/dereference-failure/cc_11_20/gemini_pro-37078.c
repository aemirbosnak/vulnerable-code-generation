//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define POP3_PORT 110
#define MAX_LINE_LENGTH 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in servaddr;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Set up the server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        perror("inet_pton");
        return EXIT_FAILURE;
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Receive the welcome message
    char buf[MAX_LINE_LENGTH];
    if (recv(sockfd, buf, MAX_LINE_LENGTH, 0) < 0) {
        perror("recv");
        return EXIT_FAILURE;
    }
    printf("%s", buf);

    // Send the USER command
    sprintf(buf, "USER username\r\n");
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the USER response
    if (recv(sockfd, buf, MAX_LINE_LENGTH, 0) < 0) {
        perror("recv");
        return EXIT_FAILURE;
    }
    printf("%s", buf);

    // Send the PASS command
    sprintf(buf, "PASS password\r\n");
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the PASS response
    if (recv(sockfd, buf, MAX_LINE_LENGTH, 0) < 0) {
        perror("recv");
        return EXIT_FAILURE;
    }
    printf("%s", buf);

    // Send the LIST command
    sprintf(buf, "LIST\r\n");
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the LIST response
    while (recv(sockfd, buf, MAX_LINE_LENGTH, 0) > 0) {
        printf("%s", buf);
    }

    // Send the QUIT command
    sprintf(buf, "QUIT\r\n");
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Close the socket
    close(sockfd);

    return EXIT_SUCCESS;
}