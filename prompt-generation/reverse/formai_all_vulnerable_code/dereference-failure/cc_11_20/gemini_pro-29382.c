//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define MAXLINE 1024

int main(int argc, char **argv) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }

    char *hostname = argv[1];
    int port = atoi(argv[2]);

    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        fprintf(stderr, "Error: could not resolve hostname %s\n", hostname);
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);
    server_addr.sin_port = htons(port);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Error: could not create socket");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Error: could not connect to server");
        exit(1);
    }

    // Send the USER command
    char *user = "USER username";
    if (write(sockfd, user, strlen(user)) == -1) {
        perror("Error: could not send USER command");
        exit(1);
    }

    // Read the server's response
    char buffer[MAXLINE];
    memset(buffer, 0, MAXLINE);
    if (read(sockfd, buffer, MAXLINE) == -1) {
        perror("Error: could not read server's response");
        exit(1);
    }

    // Check the server's response
    if (strncmp(buffer, "+OK", 3) != 0) {
        fprintf(stderr, "Error: server returned an error: %s\n", buffer);
        exit(1);
    }

    // Send the PASS command
    char *pass = "PASS password";
    if (write(sockfd, pass, strlen(pass)) == -1) {
        perror("Error: could not send PASS command");
        exit(1);
    }

    // Read the server's response
    memset(buffer, 0, MAXLINE);
    if (read(sockfd, buffer, MAXLINE) == -1) {
        perror("Error: could not read server's response");
        exit(1);
    }

    // Check the server's response
    if (strncmp(buffer, "+OK", 3) != 0) {
        fprintf(stderr, "Error: server returned an error: %s\n", buffer);
        exit(1);
    }

    // Send the STAT command
    char *stat = "STAT";
    if (write(sockfd, stat, strlen(stat)) == -1) {
        perror("Error: could not send STAT command");
        exit(1);
    }

    // Read the server's response
    memset(buffer, 0, MAXLINE);
    if (read(sockfd, buffer, MAXLINE) == -1) {
        perror("Error: could not read server's response");
        exit(1);
    }

    // Check the server's response
    if (strncmp(buffer, "+OK", 3) != 0) {
        fprintf(stderr, "Error: server returned an error: %s\n", buffer);
        exit(1);
    }

    // Parse the server's response
    int num_messages, total_size;
    sscanf(buffer, "+OK %d %d", &num_messages, &total_size);

    printf("Number of messages: %d\n", num_messages);
    printf("Total size of messages: %d\n", total_size);

    // Send the QUIT command
    char *quit = "QUIT";
    if (write(sockfd, quit, strlen(quit)) == -1) {
        perror("Error: could not send QUIT command");
        exit(1);
    }

    // Read the server's response
    memset(buffer, 0, MAXLINE);
    if (read(sockfd, buffer, MAXLINE) == -1) {
        perror("Error: could not read server's response");
        exit(1);
    }

    // Check the server's response
    if (strncmp(buffer, "+OK", 3) != 0) {
        fprintf(stderr, "Error: server returned an error: %s\n", buffer);
        exit(1);
    }

    close(sockfd);

    return 0;
}