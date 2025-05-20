//Code Llama-13B DATASET v1.0 Category: Building a POP3 Client ; Style: active
/*
 * POP3 Client Example Program in an active style
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>

#define POP3_PORT 110
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, n;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in server_addr;
    struct hostent *server;

    // Check command-line arguments
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    // Set up the server address
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "gethostbyname: %s\n", hstrerror(h_errno));
        exit(1);
    }
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);
    server_addr.sin_addr = *((struct in_addr *) server->h_addr);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        exit(1);
    }

    // Send the POP3 command
    n = write(sockfd, "USER <username>\r\n", strlen("USER <username>\r\n"));
    if (n < 0) {
        perror("write");
        exit(1);
    }

    // Read the server response
    n = read(sockfd, buffer, BUFFER_SIZE);
    if (n < 0) {
        perror("read");
        exit(1);
    }
    printf("Server response: %s", buffer);

    // Send the POP3 command
    n = write(sockfd, "PASS <password>\r\n", strlen("PASS <password>\r\n"));
    if (n < 0) {
        perror("write");
        exit(1);
    }

    // Read the server response
    n = read(sockfd, buffer, BUFFER_SIZE);
    if (n < 0) {
        perror("read");
        exit(1);
    }
    printf("Server response: %s", buffer);

    // Send the POP3 command
    n = write(sockfd, "STAT\r\n", strlen("STAT\r\n"));
    if (n < 0) {
        perror("write");
        exit(1);
    }

    // Read the server response
    n = read(sockfd, buffer, BUFFER_SIZE);
    if (n < 0) {
        perror("read");
        exit(1);
    }
    printf("Server response: %s", buffer);

    // Send the POP3 command
    n = write(sockfd, "LIST\r\n", strlen("LIST\r\n"));
    if (n < 0) {
        perror("write");
        exit(1);
    }

    // Read the server response
    n = read(sockfd, buffer, BUFFER_SIZE);
    if (n < 0) {
        perror("read");
        exit(1);
    }
    printf("Server response: %s", buffer);

    // Send the POP3 command
    n = write(sockfd, "RETR 1\r\n", strlen("RETR 1\r\n"));
    if (n < 0) {
        perror("write");
        exit(1);
    }

    // Read the server response
    n = read(sockfd, buffer, BUFFER_SIZE);
    if (n < 0) {
        perror("read");
        exit(1);
    }
    printf("Server response: %s", buffer);

    // Send the POP3 command
    n = write(sockfd, "DELE 1\r\n", strlen("DELE 1\r\n"));
    if (n < 0) {
        perror("write");
        exit(1);
    }

    // Read the server response
    n = read(sockfd, buffer, BUFFER_SIZE);
    if (n < 0) {
        perror("read");
        exit(1);
    }
    printf("Server response: %s", buffer);

    // Send the POP3 command
    n = write(sockfd, "QUIT\r\n", strlen("QUIT\r\n"));
    if (n < 0) {
        perror("write");
        exit(1);
    }

    // Read the server response
    n = read(sockfd, buffer, BUFFER_SIZE);
    if (n < 0) {
        perror("read");
        exit(1);
    }
    printf("Server response: %s", buffer);

    return 0;
}