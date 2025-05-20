//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: modular
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

#define SMTP_PORT 25
#define MAX_BUFFER 1024

// Function to establish a TCP connection to the SMTP server
int connect_smtp_server(const char *hostname) {
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *server_info;

    // Get the host information
    server_info = gethostbyname(hostname);
    if (!server_info) {
        perror("gethostbyname");
        exit(EXIT_FAILURE);
    }

    // Create a TCP socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set the server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SMTP_PORT);
    memcpy(&server_addr.sin_addr, server_info->h_addr, server_info->h_length);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    return sockfd;
}

// Function to send a command to the SMTP server
void send_command(int sockfd, const char *command) {
    int nbytes;

    // Send the command
    nbytes = send(sockfd, command, strlen(command), 0);
    if (nbytes == -1) {
        perror("send");
        exit(EXIT_FAILURE);
    }

    // Print the command for debugging
    printf("C: %s\n", command);
}

// Function to receive a response from the SMTP server
char *receive_response(int sockfd) {
    char buffer[MAX_BUFFER];
    char *response = NULL;
    int nbytes;

    // Receive the response
    nbytes = recv(sockfd, buffer, MAX_BUFFER, 0);
    if (nbytes == -1) {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    // Allocate memory for the response
    response = malloc(nbytes + 1);
    if (!response) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    // Copy the response into the allocated memory
    memcpy(response, buffer, nbytes);
    response[nbytes] = '\0';

    // Print the response for debugging
    printf("S: %s\n", response);

    return response;
}

// Function to send an email message
void send_email(int sockfd, const char *from, const char *to, const char *subject, const char *message) {
    char buffer[MAX_BUFFER];

    // Send the MAIL FROM command
    snprintf(buffer, MAX_BUFFER, "MAIL FROM: %s", from);
    send_command(sockfd, buffer);

    // Receive the response
    receive_response(sockfd);

    // Send the RCPT TO command
    snprintf(buffer, MAX_BUFFER, "RCPT TO: %s", to);
    send_command(sockfd, buffer);

    // Receive the response
    receive_response(sockfd);

    // Send the DATA command
    send_command(sockfd, "DATA");

    // Receive the response
    receive_response(sockfd);

    // Send the email subject
    snprintf(buffer, MAX_BUFFER, "Subject: %s", subject);
    send_command(sockfd, buffer);

    // Send a blank line to indicate the end of the subject
    send_command(sockfd, "");

    // Send the email message
    send_command(sockfd, message);

    // Send a period (.) to indicate the end of the message
    send_command(sockfd, ".");

    // Receive the response
    receive_response(sockfd);

    // Send the QUIT command
    send_command(sockfd, "QUIT");

    // Receive the response
    receive_response(sockfd);

    // Close the socket
    close(sockfd);
}

int main(int argc, char **argv) {
    if (argc != 6) {
        fprintf(stderr, "Usage: %s <hostname> <from> <to> <subject> <message>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Get the command line arguments
    const char *hostname = argv[1];
    const char *from = argv[2];
    const char *to = argv[3];
    const char *subject = argv[4];
    const char *message = argv[5];

    // Connect to the SMTP server
    int sockfd = connect_smtp_server(hostname);

    // Send the email message
    send_email(sockfd, from, to, subject, message);

    // Exit the program
    exit(EXIT_SUCCESS);
}