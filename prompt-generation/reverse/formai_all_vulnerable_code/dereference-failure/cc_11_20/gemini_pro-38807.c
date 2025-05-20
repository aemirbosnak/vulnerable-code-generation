//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>

// POP3 commands
#define USER "USER"
#define PASS "PASS"
#define QUIT "QUIT"
#define RETR "RETR"
#define DELE "DELE"

// Server information
#define SERVER "pop.example.com"
#define PORT 110

int main() {
    // Socket connection
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[1024];

    // Resolve server address
    struct hostent *host = gethostbyname(SERVER);
    if (host == NULL) {
        fprintf(stderr, "Error resolving server address: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        fprintf(stderr, "Error creating socket: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Set server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        fprintf(stderr, "Error connecting to server: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Receive welcome message
    if (recv(sockfd, buffer, sizeof(buffer), 0) == -1) {
        fprintf(stderr, "Error receiving welcome message: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    printf("%s", buffer);

    // Send USER command
    sprintf(buffer, "%s username\r\n", USER);
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        fprintf(stderr, "Error sending USER command: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Receive USER response
    if (recv(sockfd, buffer, sizeof(buffer), 0) == -1) {
        fprintf(stderr, "Error receiving USER response: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    printf("%s", buffer);

    // Send PASS command
    sprintf(buffer, "%s password\r\n", PASS);
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        fprintf(stderr, "Error sending PASS command: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Receive PASS response
    if (recv(sockfd, buffer, sizeof(buffer), 0) == -1) {
        fprintf(stderr, "Error receiving PASS response: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    printf("%s", buffer);

    // Send RETR command
    sprintf(buffer, "%s 1\r\n", RETR);
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        fprintf(stderr, "Error sending RETR command: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Receive RETR response
    FILE *fp = fopen("email.txt", "w");
    while (1) {
        int bytes_received = recv(sockfd, buffer, sizeof(buffer), 0);
        if (bytes_received == -1) {
            fprintf(stderr, "Error receiving RETR response: %s\n", strerror(errno));
            exit(EXIT_FAILURE);
        } else if (bytes_received == 0) {
            break;
        }
        fwrite(buffer, 1, bytes_received, fp);
    }
    fclose(fp);

    // Send DELE command
    sprintf(buffer, "%s 1\r\n", DELE);
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        fprintf(stderr, "Error sending DELE command: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Receive DELE response
    if (recv(sockfd, buffer, sizeof(buffer), 0) == -1) {
        fprintf(stderr, "Error receiving DELE response: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    printf("%s", buffer);

    // Send QUIT command
    sprintf(buffer, "%s\r\n", QUIT);
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        fprintf(stderr, "Error sending QUIT command: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    // Close socket
    close(sockfd);

    return EXIT_SUCCESS;
}