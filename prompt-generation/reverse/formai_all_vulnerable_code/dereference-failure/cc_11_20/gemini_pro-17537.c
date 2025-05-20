//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <unistd.h>
#include <time.h>

#define IMAP_PORT 143

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <hostname> <username>\n", argv[0]);
        return EXIT_FAILURE;
    }

    struct hostent *host = gethostbyname(argv[1]);
    if (!host) {
        fprintf(stderr, "Host %s not found.\n", argv[1]);
        return EXIT_FAILURE;
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket.");
        return EXIT_FAILURE;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(IMAP_PORT);
    server_addr.sin_addr = *(struct in_addr *)host->h_addr;

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to host.");
        return EXIT_FAILURE;
    }

    char buffer[1024];
    int n;

    // Read the welcome message.
    n = read(sockfd, buffer, sizeof(buffer) - 1);
    if (n < 0) {
        perror("Error reading welcome message.");
        return EXIT_FAILURE;
    }
    buffer[n] = '\0';
    printf("%s", buffer);

    // Send the login command.
    snprintf(buffer, sizeof(buffer), "LOGIN %s %s\r\n", argv[2], argv[3]);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("Error sending login command.");
        return EXIT_FAILURE;
    }

    // Read the login response.
    n = read(sockfd, buffer, sizeof(buffer) - 1);
    if (n < 0) {
        perror("Error reading login response.");
        return EXIT_FAILURE;
    }
    buffer[n] = '\0';
    printf("%s", buffer);

    // Send the list command.
    snprintf(buffer, sizeof(buffer), "LIST \"\" *\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("Error sending list command.");
        return EXIT_FAILURE;
    }

    // Read the list response.
    while ((n = read(sockfd, buffer, sizeof(buffer) - 1)) > 0) {
        buffer[n] = '\0';
        printf("%s", buffer);
    }
    if (n < 0) {
        perror("Error reading list response.");
        return EXIT_FAILURE;
    }

    // Send the quit command.
    snprintf(buffer, sizeof(buffer), "QUIT\r\n");
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("Error sending quit command.");
        return EXIT_FAILURE;
    }

    // Read the quit response.
    n = read(sockfd, buffer, sizeof(buffer) - 1);
    if (n < 0) {
        perror("Error reading quit response.");
        return EXIT_FAILURE;
    }
    buffer[n] = '\0';
    printf("%s", buffer);

    close(sockfd);

    return EXIT_SUCCESS;
}