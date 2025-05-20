//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define BUFFSIZE 1024
#define PORT 993

int main(int argc, char *argv[]) {
    int sockfd, n, i;
    char buffer[BUFFSIZE];
    struct sockaddr_in serv_addr;
    struct hostent *server;

    // Check for the correct usage of program
    if (argc < 3) {
        fprintf(stderr, "Usage: %s hostname username\n", argv[0]);
        exit(1);
    }

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Get the server details
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "Error: no such host\n");
        exit(1);
    }

    // Clear the serv_addr variable
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server -> h_addr, (char *) &serv_addr.sin_addr.s_addr, server -> h_length);
    serv_addr.sin_port = htons(PORT);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    // Authenticate the user
    snprintf(buffer, sizeof(buffer), ". login %s\r\n", argv[2]);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("Error writing to socket");
        exit(1);
    }
    n = read(sockfd, buffer, sizeof(buffer));
    if (n < 0) {
        perror("Error reading from socket");
        exit(1);
    }
    buffer[n] = '\0';

    if (strncmp(buffer, ". OK", 4) != 0) {
        fprintf(stderr, "Error authenticating user\n");
        exit(1);
    }

    // List all the mailboxes
    snprintf(buffer, sizeof(buffer), ". list \"\" *\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("Error writing to socket");
        exit(1);
    }
    n = read(sockfd, buffer, sizeof(buffer));
    if (n < 0) {
        perror("Error reading from socket");
        exit(1);
    }
    buffer[n] = '\0';

    printf("List of mailboxes:\n");
    char *pch = strtok(buffer, "*");
    while (pch != NULL) {
        if (strncmp(pch, " LIST", 5) == 0) {
            char *mbox = pch + 6;
            for (i = 0; mbox[i] != '"'; i++);
            printf("%.*s\n", i, mbox);
        }
        pch = strtok(NULL, "*");
    }

    // Logout and close connection
    snprintf(buffer, sizeof(buffer), ". logout\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("Error writing to socket");
        exit(1);
    }
    n = read(sockfd, buffer, sizeof(buffer));
    if (n < 0) {
        perror("Error reading from socket");
        exit(1);
    }
    buffer[n] = '\0';

    if (strncmp(buffer, ". OK", 4) != 0) {
        fprintf(stderr, "Error logging out\n");
        exit(1);
    }

    close(sockfd);
    return 0;
}