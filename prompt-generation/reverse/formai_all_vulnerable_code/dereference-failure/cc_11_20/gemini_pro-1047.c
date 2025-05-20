//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>

// Define the POP3 port
#define POP3_PORT 110

// Define the POP3 commands
#define USER "USER"
#define PASS "PASS"
#define RETR "RETR"
#define DELE "DELE"
#define QUIT "QUIT"

// Main function
int main(int argc, char *argv[]) {
    // Check if the user provided the correct number of arguments
    if (argc != 4) {
        printf("Usage: %s <hostname> <username> <password>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the hostname, username, and password from the user
    char *hostname = argv[1];
    char *username = argv[2];
    char *password = argv[3];

    // Resolve the hostname
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        printf("Error: Could not resolve hostname\n");
        return EXIT_FAILURE;
    }

    // Create the socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error: Could not create socket\n");
        return EXIT_FAILURE;
    }

    // Connect to the POP3 server
    struct sockaddr_in servaddr;
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(POP3_PORT);
    servaddr.sin_addr = *((struct in_addr *)host->h_addr);
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        printf("Error: Could not connect to POP3 server\n");
        return EXIT_FAILURE;
    }

    // Read the welcome message from the POP3 server
    char buffer[1024];
    if (recv(sockfd, buffer, sizeof(buffer), 0) == -1) {
        printf("Error: Could not receive welcome message from POP3 server\n");
        return EXIT_FAILURE;
    }
    printf("%s\n", buffer);

    // Send the USER command
    sprintf(buffer, "%s %s\r\n", USER, username);
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        printf("Error: Could not send USER command\n");
        return EXIT_FAILURE;
    }

    // Read the response from the POP3 server
    if (recv(sockfd, buffer, sizeof(buffer), 0) == -1) {
        printf("Error: Could not receive response to USER command\n");
        return EXIT_FAILURE;
    }
    printf("%s\n", buffer);

    // Send the PASS command
    sprintf(buffer, "%s %s\r\n", PASS, password);
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        printf("Error: Could not send PASS command\n");
        return EXIT_FAILURE;
    }

    // Read the response from the POP3 server
    if (recv(sockfd, buffer, sizeof(buffer), 0) == -1) {
        printf("Error: Could not receive response to PASS command\n");
        return EXIT_FAILURE;
    }
    printf("%s\n", buffer);

    // Send the RETR command
    sprintf(buffer, "%s 1\r\n", RETR);
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        printf("Error: Could not send RETR command\n");
        return EXIT_FAILURE;
    }

    // Read the response from the POP3 server
    if (recv(sockfd, buffer, sizeof(buffer), 0) == -1) {
        printf("Error: Could not receive response to RETR command\n");
        return EXIT_FAILURE;
    }
    printf("%s\n", buffer);

    // Send the DELE command
    sprintf(buffer, "%s 1\r\n", DELE);
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        printf("Error: Could not send DELE command\n");
        return EXIT_FAILURE;
    }

    // Read the response from the POP3 server
    if (recv(sockfd, buffer, sizeof(buffer), 0) == -1) {
        printf("Error: Could not receive response to DELE command\n");
        return EXIT_FAILURE;
    }
    printf("%s\n", buffer);

    // Send the QUIT command
    if (send(sockfd, QUIT "\r\n", strlen(QUIT) + 2, 0) == -1) {
        printf("Error: Could not send QUIT command\n");
        return EXIT_FAILURE;
    }

    // Close the socket
    close(sockfd);

    return EXIT_SUCCESS;
}