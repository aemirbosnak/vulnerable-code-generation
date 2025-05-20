//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: high level of detail
#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define POP3_PORT 110

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server> <username>\n", argv[0]);
        return 1;
    }

    // Resolve the server address
    struct hostent *server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Error resolving server address\n");
        return 1;
    }

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Error creating socket\n");
        return 1;
    }

    // Connect to the server
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);
    memcpy(&server_addr.sin_addr, server->h_addr, server->h_length);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        fprintf(stderr, "Error connecting to server\n");
        return 1;
    }

    // Receive the welcome message
    char buf[1024];
    int n = read(sockfd, buf, sizeof(buf));
    if (n < 0) {
        fprintf(stderr, "Error reading welcome message\n");
        return 1;
    }

    printf("%s\n", buf);

    // Send the USER command
    snprintf(buf, sizeof(buf), "USER %s\r\n", argv[2]);
    n = write(sockfd, buf, strlen(buf));
    if (n < 0) {
        fprintf(stderr, "Error sending USER command\n");
        return 1;
    }

    // Receive the response to the USER command
    n = read(sockfd, buf, sizeof(buf));
    if (n < 0) {
        fprintf(stderr, "Error reading response to USER command\n");
        return 1;
    }

    printf("%s\n", buf);

    // Send the PASS command
    snprintf(buf, sizeof(buf), "PASS %s\r\n", argv[3]);
    n = write(sockfd, buf, strlen(buf));
    if (n < 0) {
        fprintf(stderr, "Error sending PASS command\n");
        return 1;
    }

    // Receive the response to the PASS command
    n = read(sockfd, buf, sizeof(buf));
    if (n < 0) {
        fprintf(stderr, "Error reading response to PASS command\n");
        return 1;
    }

    printf("%s\n", buf);

    // Send the LIST command
    snprintf(buf, sizeof(buf), "LIST\r\n");
    n = write(sockfd, buf, strlen(buf));
    if (n < 0) {
        fprintf(stderr, "Error sending LIST command\n");
        return 1;
    }

    // Receive the response to the LIST command
    n = read(sockfd, buf, sizeof(buf));
    if (n < 0) {
        fprintf(stderr, "Error reading response to LIST command\n");
        return 1;
    }

    printf("%s\n", buf);

    // Send the RETR command
    snprintf(buf, sizeof(buf), "RETR 1\r\n");
    n = write(sockfd, buf, strlen(buf));
    if (n < 0) {
        fprintf(stderr, "Error sending RETR command\n");
        return 1;
    }

    // Receive the response to the RETR command
    n = read(sockfd, buf, sizeof(buf));
    if (n < 0) {
        fprintf(stderr, "Error reading response to RETR command\n");
        return 1;
    }

    printf("%s\n", buf);

    // Send the QUIT command
    snprintf(buf, sizeof(buf), "QUIT\r\n");
    n = write(sockfd, buf, strlen(buf));
    if (n < 0) {
        fprintf(stderr, "Error sending QUIT command\n");
        return 1;
    }

    // Close the socket
    close(sockfd);

    return 0;
}