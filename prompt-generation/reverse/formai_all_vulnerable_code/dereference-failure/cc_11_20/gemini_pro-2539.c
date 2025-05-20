//GEMINI-pro DATASET v1.0 Category: Building a IMAP Client ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname> <username> <password>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get the hostname, username, and password from the command line arguments.
    char *hostname = argv[1];
    char *username = argv[2];
    char *password = argv[3];

    // Create a socket for communicating with the IMAP server.
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Get the IP address of the IMAP server.
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        herror("gethostbyname");
        return EXIT_FAILURE;
    }

    // Connect to the IMAP server.
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(143);
    server_addr.sin_addr = *((struct in_addr *)host->h_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Send the login command to the IMAP server.
    char login_cmd[BUFFER_SIZE];
    snprintf(login_cmd, BUFFER_SIZE, "LOGIN %s %s\r\n", username, password);

    if (send(sockfd, login_cmd, strlen(login_cmd), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the response from the IMAP server.
    char buffer[BUFFER_SIZE];
    int nbytes = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (nbytes == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Check if the login was successful.
    if (strncmp(buffer, "+OK LOGIN", 9) != 0) {
        fprintf(stderr, "Login failed: %s", buffer);
        return EXIT_FAILURE;
    }

    // Send the list command to the IMAP server.
    char list_cmd[BUFFER_SIZE];
    snprintf(list_cmd, BUFFER_SIZE, "LIST \"\" *\r\n");

    if (send(sockfd, list_cmd, strlen(list_cmd), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Receive the response from the IMAP server.
    nbytes = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (nbytes == -1) {
        perror("recv");
        return EXIT_FAILURE;
    }

    // Print the list of mailboxes.
    printf("%s", buffer);

    // Send the logout command to the IMAP server.
    char logout_cmd[BUFFER_SIZE];
    snprintf(logout_cmd, BUFFER_SIZE, "LOGOUT\r\n");

    if (send(sockfd, logout_cmd, strlen(logout_cmd), 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }

    // Close the socket.
    close(sockfd);

    return EXIT_SUCCESS;
}