//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

#define BUFSIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s hostname port username\n", argv[0]);
        return 1;
    }

    // Get the hostname and port number
    char *hostname = argv[1];
    int port = atoi(argv[2]);

    // Get the username
    char *username = argv[3];

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return 1;
    }

    // Connect to the server
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        fprintf(stderr, "gethostbyname: %s\n", hostname);
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);

    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        return 1;
    }

    // Send the username to the server
    char buf[BUFSIZE];
    snprintf(buf, BUFSIZE, "USER %s\r\n", username);
    if (send(sockfd, buf, strlen(buf), 0) == -1) {
        perror("send");
        return 1;
    }

    // Receive the response from the server
    memset(buf, 0, BUFSIZE);
    if (recv(sockfd, buf, BUFSIZE - 1, 0) == -1) {
        perror("recv");
        return 1;
    }

    // Check the response code
    if (strncmp(buf, "+OK", 3) != 0) {
        fprintf(stderr, "Invalid response from server: %s\n", buf);
        return 1;
    }

    // Get the number of messages in the inbox
    memset(buf, 0, BUFSIZE);
    if (send(sockfd, "LIST \"\"\r\n", strlen("LIST \"\"\r\n"), 0) == -1) {
        perror("send");
        return 1;
    }

    memset(buf, 0, BUFSIZE);
    if (recv(sockfd, buf, BUFSIZE - 1, 0) == -1) {
        perror("recv");
        return 1;
    }

    // Check the response code
    if (strncmp(buf, "+OK", 3) != 0) {
        fprintf(stderr, "Invalid response from server: %s\n", buf);
        return 1;
    }

    // Parse the response to get the number of messages
    int num_messages = 0;
    char *ptr = buf;
    while (*ptr != '\0') {
        while (*ptr != '\r') {
            ptr++;
        }
        ptr += 2;
        num_messages++;
    }

    // Print the number of messages in the inbox
    printf("%d messages in inbox\n", num_messages);

    // Close the socket
    close(sockfd);

    return 0;
}