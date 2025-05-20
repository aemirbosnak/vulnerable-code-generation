//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: single-threaded
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define BUFFERSIZE 1024

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the IP address of the IMAP server
    struct hostent *host = gethostbyname(argv[1]);
    if (host == NULL) {
        fprintf(stderr, "Error: Could not resolve hostname %s\n", argv[1]);
        return EXIT_FAILURE;
    }

    // Create a socket to connect to the IMAP server
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Error: Could not create socket");
        return EXIT_FAILURE;
    }

    // Connect to the IMAP server
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(143);
    memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("Error: Could not connect to server");
        return EXIT_FAILURE;
    }

    // Send the login command
    char buffer[BUFFERSIZE];
    snprintf(buffer, BUFFERSIZE, "LOGIN %s %s\r\n", argv[2], argv[3]);
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("Error: Could not send login command");
        return EXIT_FAILURE;
    }

    // Receive the login response
    memset(buffer, 0, BUFFERSIZE);
    if (recv(sockfd, buffer, BUFFERSIZE, 0) == -1) {
        perror("Error: Could not receive login response");
        return EXIT_FAILURE;
    }

    // Check if the login was successful
    if (strncmp(buffer, "OK", 2) != 0) {
        fprintf(stderr, "Error: Could not log in to server\n");
        return EXIT_FAILURE;
    }

    // Send the select command
    snprintf(buffer, BUFFERSIZE, "SELECT INBOX\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("Error: Could not send select command");
        return EXIT_FAILURE;
    }

    // Receive the select response
    memset(buffer, 0, BUFFERSIZE);
    if (recv(sockfd, buffer, BUFFERSIZE, 0) == -1) {
        perror("Error: Could not receive select response");
        return EXIT_FAILURE;
    }

    // Check if the select was successful
    if (strncmp(buffer, "OK", 2) != 0) {
        fprintf(stderr, "Error: Could not select inbox\n");
        return EXIT_FAILURE;
    }

    // Send the search command
    snprintf(buffer, BUFFERSIZE, "SEARCH SUBJECT \"Test\"\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("Error: Could not send search command");
        return EXIT_FAILURE;
    }

    // Receive the search response
    memset(buffer, 0, BUFFERSIZE);
    if (recv(sockfd, buffer, BUFFERSIZE, 0) == -1) {
        perror("Error: Could not receive search response");
        return EXIT_FAILURE;
    }

    // Check if the search was successful
    if (strncmp(buffer, "OK", 2) != 0) {
        fprintf(stderr, "Error: Could not search for emails\n");
        return EXIT_FAILURE;
    }

    // Send the fetch command
    snprintf(buffer, BUFFERSIZE, "FETCH 1 BODY[TEXT]\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("Error: Could not send fetch command");
        return EXIT_FAILURE;
    }

    // Receive the fetch response
    memset(buffer, 0, BUFFERSIZE);
    if (recv(sockfd, buffer, BUFFERSIZE, 0) == -1) {
        perror("Error: Could not receive fetch response");
        return EXIT_FAILURE;
    }

    // Check if the fetch was successful
    if (strncmp(buffer, "OK", 2) != 0) {
        fprintf(stderr, "Error: Could not fetch email\n");
        return EXIT_FAILURE;
    }

    // Print the email body
    printf("%s", buffer);

    // Send the logout command
    snprintf(buffer, BUFFERSIZE, "LOGOUT\r\n");
    if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
        perror("Error: Could not send logout command");
        return EXIT_FAILURE;
    }

    // Close the socket
    close(sockfd);

    return EXIT_SUCCESS;
}