//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define SERVER_PORT 110
#define BUFFER_SIZE 1024
#define USERNAME "your_username"
#define PASSWORD "your_password"
#define POP3_SERVER "pop3.example.com"

int main(int argc, char *argv[]) {
    int sockfd;
    struct addrinfo hints, *servinfo;
    char username[50], password[50];

    // Initialize hints structure
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    // Get address information for POP3 server
    if ((getaddrinfo(POP3_SERVER, "pop3", &hints, &servinfo))!= 0) {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(errno));
        exit(1);
    }

    // Connect to POP3 server
    sockfd = socket(servinfo->ai_family, servinfo->ai_socktype, servinfo->ai_protocol);
    if (sockfd == -1) {
        fprintf(stderr, "socket error: %s\n", strerror(errno));
        exit(1);
    }

    if (connect(sockfd, servinfo->ai_addr, servinfo->ai_addrlen) == -1) {
        fprintf(stderr, "connect error: %s\n", strerror(errno));
        exit(1);
    }

    // Send USER command
    sprintf(username, "USER %s", USERNAME);
    send(sockfd, username, strlen(username), 0);

    // Send PASS command
    sprintf(password, "PASS %s", PASSWORD);
    send(sockfd, password, strlen(password), 0);

    // Receive server response
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);
    int bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (bytes_received <= 0) {
        fprintf(stderr, "recv error: %s\n", strerror(errno));
        exit(1);
    }

    // Print server response
    printf("Server response: %s\n", buffer);

    // Close socket
    close(sockfd);

    return 0;
}