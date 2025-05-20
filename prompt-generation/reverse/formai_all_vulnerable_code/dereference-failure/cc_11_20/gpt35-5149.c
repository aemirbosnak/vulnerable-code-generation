//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    char *host = "localhost";
    char *user = "username";
    char *pass = "password";
    int port = 110; // default port for POP3
    int sockfd, n;
    struct sockaddr_in servaddr;
    char buf[BUF_SIZE];

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR: Could not create socket.");
        exit(EXIT_FAILURE);
    }

    // Clear server address structure
    bzero(&servaddr, sizeof(servaddr));

    // Configure server address structure
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    struct hostent *host_entry = gethostbyname(host);
    if (host_entry == NULL) {
        perror("ERROR: Could not resolve hostname.");
        exit(EXIT_FAILURE);
    }
    memcpy(&servaddr.sin_addr, host_entry->h_addr_list[0], host_entry->h_length);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        perror("ERROR: Could not connect to server.");
        exit(EXIT_FAILURE);
    }

    // Read greeting message
    bzero(buf, BUF_SIZE);
    n = read(sockfd, buf, BUF_SIZE - 1);
    if (n < 0) {
        perror("ERROR: Could not read from server.");
        exit(EXIT_FAILURE);
    }
    printf("%s\n", buf);

    // Send username
    bzero(buf, BUF_SIZE);
    sprintf(buf, "USER %s\r\n", user);
    n = write(sockfd, buf, strlen(buf));
    if (n < 0) {
        perror("ERROR: Could not write to server.");
        exit(EXIT_FAILURE);
    }

    // Read server response to username
    bzero(buf, BUF_SIZE);
    n = read(sockfd, buf, BUF_SIZE - 1);
    if (n < 0) {
        perror("ERROR: Could not read from server.");
        exit(EXIT_FAILURE);
    }
    printf("%s\n", buf);

    // Send password
    bzero(buf, BUF_SIZE);
    sprintf(buf, "PASS %s\r\n", pass);
    n = write(sockfd, buf, strlen(buf));
    if (n < 0) {
        perror("ERROR: Could not write to server.");
        exit(EXIT_FAILURE);
    }

    // Read server response to password
    bzero(buf, BUF_SIZE);
    n = read(sockfd, buf, BUF_SIZE - 1);
    if (n < 0) {
        perror("ERROR: Could not read from server.");
        exit(EXIT_FAILURE);
    }
    printf("%s\n", buf);

    // Send list command
    bzero(buf, BUF_SIZE);
    sprintf(buf, "LIST\r\n");
    n = write(sockfd, buf, strlen(buf));
    if (n < 0) {
        perror("ERROR: Could not write to server.");
        exit(EXIT_FAILURE);
    }

    // Read server response to list command
    bzero(buf, BUF_SIZE);
    n = read(sockfd, buf, BUF_SIZE - 1);
    if (n < 0) {
        perror("ERROR: Could not read from server.");
        exit(EXIT_FAILURE);
    }
    printf("%s\n", buf);

    // Send quit command
    bzero(buf, BUF_SIZE);
    sprintf(buf, "QUIT\r\n");
    n = write(sockfd, buf, strlen(buf));
    if (n < 0) {
        perror("ERROR: Could not write to server.");
        exit(EXIT_FAILURE);
    }

    // Read server response to quit command
    bzero(buf, BUF_SIZE);
    n = read(sockfd, buf, BUF_SIZE - 1);
    if (n < 0) {
        perror("ERROR: Could not read from server.");
        exit(EXIT_FAILURE);
    }
    printf("%s\n", buf);

    // Close socket
    close(sockfd);

    return 0;
}