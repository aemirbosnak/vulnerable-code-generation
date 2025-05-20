//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define POP3_PORT 110

int main(int argc, char **argv)
{
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *hostname = argv[1];
    char *username = argv[2];
    char *password = argv[3];

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(POP3_PORT);
    if (inet_pton(AF_INET, hostname, &servaddr.sin_addr) <= 0) {
        perror("inet_pton");
        return EXIT_FAILURE;
    }

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        perror("connect");
        return EXIT_FAILURE;
    }

    char buf[1024];
    int n;

    // Read the welcome message
    n = read(sockfd, buf, sizeof(buf));
    if (n == -1) {
        perror("read");
        return EXIT_FAILURE;
    }

    // Send the USER command
    snprintf(buf, sizeof(buf), "USER %s\r\n", username);
    n = write(sockfd, buf, strlen(buf));
    if (n == -1) {
        perror("write");
        return EXIT_FAILURE;
    }

    // Read the response
    n = read(sockfd, buf, sizeof(buf));
    if (n == -1) {
        perror("read");
        return EXIT_FAILURE;
    }

    // Check the response
    if (strncmp(buf, "+OK", 3) != 0) {
        fprintf(stderr, "Error: %s", buf);
        return EXIT_FAILURE;
    }

    // Send the PASS command
    snprintf(buf, sizeof(buf), "PASS %s\r\n", password);
    n = write(sockfd, buf, strlen(buf));
    if (n == -1) {
        perror("write");
        return EXIT_FAILURE;
    }

    // Read the response
    n = read(sockfd, buf, sizeof(buf));
    if (n == -1) {
        perror("read");
        return EXIT_FAILURE;
    }

    // Check the response
    if (strncmp(buf, "+OK", 3) != 0) {
        fprintf(stderr, "Error: %s", buf);
        return EXIT_FAILURE;
    }

    // Send the LIST command
    snprintf(buf, sizeof(buf), "LIST\r\n");
    n = write(sockfd, buf, strlen(buf));
    if (n == -1) {
        perror("write");
        return EXIT_FAILURE;
    }

    // Read the response
    n = read(sockfd, buf, sizeof(buf));
    if (n == -1) {
        perror("read");
        return EXIT_FAILURE;
    }

    // Print the response
    printf("%s", buf);

    // Send the QUIT command
    snprintf(buf, sizeof(buf), "QUIT\r\n");
    n = write(sockfd, buf, strlen(buf));
    if (n == -1) {
        perror("write");
        return EXIT_FAILURE;
    }

    // Close the socket
    close(sockfd);

    return EXIT_SUCCESS;
}