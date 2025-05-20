//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

// Max length of a line
#define MAX_LINE 1024

// POP3 port
#define POP3_PORT 110

// Usage: ./pop3_client <hostname> <username> <password>
int main(int argc, char *argv[])
{
    // Check command line arguments
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        return 1;
    }

    // Set up the socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return 2;
    }

    // Get the IP address of the host
    struct hostent *host = gethostbyname(argv[1]);
    if (host == NULL) {
        fprintf(stderr, "Error: could not resolve hostname\n");
        return 3;
    }

    // Connect to the host
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(POP3_PORT);
    addr.sin_addr = *(struct in_addr *)host->h_addr;
    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("connect");
        return 4;
    }

    // Receive the welcome message
    char buf[MAX_LINE];
    if (recv(sockfd, buf, MAX_LINE, 0) < 0) {
        perror("recv");
        return 5;
    }

    // Check the welcome message
    if (strncmp(buf, "+OK", 3) != 0) {
        fprintf(stderr, "Error: unexpected welcome message\n");
        return 6;
    }

    // Send the user command
    sprintf(buf, "USER %s\r\n", argv[2]);
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        perror("send");
        return 7;
    }

    // Receive the response
    if (recv(sockfd, buf, MAX_LINE, 0) < 0) {
        perror("recv");
        return 8;
    }

    // Check the response
    if (strncmp(buf, "+OK", 3) != 0) {
        fprintf(stderr, "Error: unexpected response to USER command\n");
        return 9;
    }

    // Send the pass command
    sprintf(buf, "PASS %s\r\n", argv[3]);
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        perror("send");
        return 10;
    }

    // Receive the response
    if (recv(sockfd, buf, MAX_LINE, 0) < 0) {
        perror("recv");
        return 11;
    }

    // Check the response
    if (strncmp(buf, "+OK", 3) != 0) {
        fprintf(stderr, "Error: unexpected response to PASS command\n");
        return 12;
    }

    // Send the stat command
    sprintf(buf, "STAT\r\n");
    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        perror("send");
        return 13;
    }

    // Receive the response
    if (recv(sockfd, buf, MAX_LINE, 0) < 0) {
        perror("recv");
        return 14;
    }

    // Check the response
    if (strncmp(buf, "+OK", 3) != 0) {
        fprintf(stderr, "Error: unexpected response to STAT command\n");
        return 15;
    }

    // Parse the response
    int num_messages;
    int total_size;
    sscanf(buf, "+OK %d %d", &num_messages, &total_size);

    // Print the results
    printf("Number of messages: %d\n", num_messages);
    printf("Total size: %d\n", total_size);

    // Close the socket
    close(sockfd);

    return 0;
}