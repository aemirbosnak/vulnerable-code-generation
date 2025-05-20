//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define IMAP_PORT 143

int main(int argc, char **argv)
{
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <hostname> <username>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *hostname = argv[1];
    const char *username = argv[2];

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Get the IP address of the hostname
    struct hostent *hostent = gethostbyname(hostname);
    if (hostent == NULL) {
        herror("gethostbyname");
        return EXIT_FAILURE;
    }

    // Connect to the server
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(IMAP_PORT);
    server_addr.sin_addr = *(struct in_addr *)hostent->h_addr;

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Send the greeting
    char greeting[1024];
    snprintf(greeting, sizeof(greeting), "A01 CAPABILITY\r\n");
    if (send(sockfd, greeting, strlen(greeting), 0) < 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the capabilities
    char capabilities[1024];
    int num_bytes = recv(sockfd, capabilities, sizeof(capabilities), 0);
    if (num_bytes < 0) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Check if the server supports IMAP4rev1
    if (strstr(capabilities, "IMAP4rev1") == NULL) {
        fprintf(stderr, "Server does not support IMAP4rev1\n");
        return EXIT_FAILURE;
    }

    // Send the login command
    char login[1024];
    snprintf(login, sizeof(login), "A01 LOGIN %s %s\r\n", username, argv[3]);
    if (send(sockfd, login, strlen(login), 0) < 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the login response
    char login_response[1024];
    num_bytes = recv(sockfd, login_response, sizeof(login_response), 0);
    if (num_bytes < 0) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Check if the login was successful
    if (strstr(login_response, "OK") == NULL) {
        fprintf(stderr, "Login failed: %s\n", login_response);
        return EXIT_FAILURE;
    }

    // Send the list command
    char list[1024];
    snprintf(list, sizeof(list), "A01 LIST \"\" *\r\n");
    if (send(sockfd, list, strlen(list), 0) < 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the list response
    char list_response[1024];
    num_bytes = recv(sockfd, list_response, sizeof(list_response), 0);
    if (num_bytes < 0) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Parse the list response
    char *line = strtok(list_response, "\n");
    while (line != NULL) {
        if (strstr(line, "FLAGS") != NULL) {
            printf("FLAGS: %s\n", line);
        } else if (strstr(line, "MAILBOX") != NULL) {
            printf("MAILBOX: %s\n", line);
        } else if (strstr(line, "UNSEEN") != NULL) {
            printf("UNSEEN: %s\n", line);
        }
        line = strtok(NULL, "\n");
    }

    // Send the logout command
    char logout[1024];
    snprintf(logout, sizeof(logout), "A01 LOGOUT\r\n");
    if (send(sockfd, logout, strlen(logout), 0) < 0) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the logout response
    char logout_response[1024];
    num_bytes = recv(sockfd, logout_response, sizeof(logout_response), 0);
    if (num_bytes < 0) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Close the socket
    close(sockfd);

    return EXIT_SUCCESS;
}