//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: irregular
// IMAP Client Example Program
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFSIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[BUFSIZE];
    char command[BUFSIZE];
    char response[BUFSIZE];

    printf("Welcome to IMAP Client - an example program\n");

    // Get server address and port from the command-line arguments
    if (argc < 3) {
        printf("Usage: %s hostname port\n", argv[0]);
        exit(1);
    }

    // Get the port number
    portno = atoi(argv[2]);

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    // Get the server information
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }

    // Setup the server address structure
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        error("ERROR connecting");
    }

    // Receive greeting from server
    bzero(response, BUFSIZE);
    n = recv(sockfd, response, BUFSIZE, 0);
    if (n < 0) {
        error("ERROR reading from socket");
    }
    printf("%s", response);

    // Login to the server
    printf("Username: ");
    fgets(buffer, BUFSIZE-1, stdin);
    buffer[strlen(buffer) - 1] = '\0'; // remove the newline character
    snprintf(command, BUFSIZE, "login %s ", buffer);
    printf("Password: ");
    fgets(buffer, BUFSIZE-1, stdin);
    buffer[strlen(buffer) - 1] = '\0'; // remove the newline character
    snprintf(command, BUFSIZE, "%s%s\r\n", command, buffer);
    n = send(sockfd, command, strlen(command), 0);
    if (n < 0) {
        error("ERROR writing to socket");
    }

    // Receive response from server
    bzero(response, BUFSIZE);
    n = recv(sockfd, response, BUFSIZE, 0);
    if (n < 0) {
        error("ERROR reading from socket");
    }
    printf("%s", response);

    // List available mailboxes
    snprintf(command, BUFSIZE, "list \"\" *\r\n");
    n = send(sockfd, command, strlen(command), 0);
    if (n < 0) {
        error("ERROR writing to socket");
    }

    // Receive response from server
    bzero(response, BUFSIZE);
    n = recv(sockfd, response, BUFSIZE, 0);
    if (n < 0) {
        error("ERROR reading from socket");
    }
    printf("%s", response);

    // Logout from the server
    snprintf(command, BUFSIZE, "logout\r\n");
    n = send(sockfd, command, strlen(command), 0);
    if (n < 0) {
        error("ERROR writing to socket");
    }

    // Receive response from server
    bzero(response, BUFSIZE);
    n = recv(sockfd, response, BUFSIZE, 0);
    if (n < 0) {
        error("ERROR reading from socket");
    }
    printf("%s", response);

    // Close the connection
    close(sockfd);

    printf("Goodbye!\n");

    return 0;
}