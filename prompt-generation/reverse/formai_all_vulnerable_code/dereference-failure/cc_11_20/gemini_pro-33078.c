//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define POP3_PORT 110
#define POP3_USER "test@example.com"
#define POP3_PASS "password"

int main(int argc, char **argv) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[1024];
    char *hostname = "pop.example.com";

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Get the server's IP address
    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "Error: no such host: %s", hostname);
        exit(EXIT_FAILURE);
    }

    // Set up the server address
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    serv_addr.sin_port = htons(POP3_PORT);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    // Receive the server's welcome message
    memset(buffer, 0, sizeof(buffer));
    n = read(sockfd, buffer, sizeof(buffer) - 1);
    if (n < 0) {
        perror("read");
        exit(EXIT_FAILURE);
    }
    printf("Server: %s", buffer);

    // Send the USER command
    memset(buffer, 0, sizeof(buffer));
    sprintf(buffer, "USER %s\n", POP3_USER);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("write");
        exit(EXIT_FAILURE);
    }

    // Receive the server's response
    memset(buffer, 0, sizeof(buffer));
    n = read(sockfd, buffer, sizeof(buffer) - 1);
    if (n < 0) {
        perror("read");
        exit(EXIT_FAILURE);
    }
    printf("Server: %s", buffer);

    // Send the PASS command
    memset(buffer, 0, sizeof(buffer));
    sprintf(buffer, "PASS %s\n", POP3_PASS);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("write");
        exit(EXIT_FAILURE);
    }

    // Receive the server's response
    memset(buffer, 0, sizeof(buffer));
    n = read(sockfd, buffer, sizeof(buffer) - 1);
    if (n < 0) {
        perror("read");
        exit(EXIT_FAILURE);
    }
    printf("Server: %s", buffer);

    // Send the STAT command
    memset(buffer, 0, sizeof(buffer));
    strcpy(buffer, "STAT\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("write");
        exit(EXIT_FAILURE);
    }

    // Receive the server's response
    memset(buffer, 0, sizeof(buffer));
    n = read(sockfd, buffer, sizeof(buffer) - 1);
    if (n < 0) {
        perror("read");
        exit(EXIT_FAILURE);
    }
    printf("Server: %s", buffer);

    // Send the LIST command
    memset(buffer, 0, sizeof(buffer));
    strcpy(buffer, "LIST\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("write");
        exit(EXIT_FAILURE);
    }

    // Receive the server's response
    memset(buffer, 0, sizeof(buffer));
    n = read(sockfd, buffer, sizeof(buffer) - 1);
    if (n < 0) {
        perror("read");
        exit(EXIT_FAILURE);
    }
    printf("Server: %s", buffer);

    // Send the QUIT command
    memset(buffer, 0, sizeof(buffer));
    strcpy(buffer, "QUIT\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("write");
        exit(EXIT_FAILURE);
    }

    // Close the socket
    close(sockfd);

    return 0;
}