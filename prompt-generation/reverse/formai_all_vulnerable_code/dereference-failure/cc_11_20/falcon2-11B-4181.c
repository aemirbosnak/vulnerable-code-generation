//Falcon2-11B DATASET v1.0 Category: Email Client ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define PORT 25

int main() {
    int sockfd, numBytes, sendBytes;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char message[100], subject[100];

    // Prompt user for message and subject
    printf("Enter your message: ");
    scanf("%s", message);
    printf("Enter subject: ");
    scanf("%s", subject);

    // Convert message and subject to lowercase for case-insensitive comparison
    for (int i = 0; i < strlen(message); i++) {
        message[i] = tolower(message[i]);
    }
    for (int i = 0; i < strlen(subject); i++) {
        subject[i] = tolower(subject[i]);
    }

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    // Set up server address and port
    server = gethostbyname("smtp.gmail.com");
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(PORT);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting to server");
        exit(EXIT_FAILURE);
    }

    // Send HELO command
    numBytes = send(sockfd, "HELO\r\n", 5, 0);
    if (numBytes < 0) {
        perror("Error sending HELO command");
        exit(EXIT_FAILURE);
    }

    // Send MAIL FROM command with message sender
    numBytes = send(sockfd, "MAIL FROM: ", 16, 0);
    if (numBytes < 0) {
        perror("Error sending MAIL FROM command");
        exit(EXIT_FAILURE);
    }
    numBytes = send(sockfd, message, strlen(message), 0);
    if (numBytes < 0) {
        perror("Error sending message");
        exit(EXIT_FAILURE);
    }

    // Send RCPT TO command with recipient
    numBytes = send(sockfd, "RCPT TO: ", 13, 0);
    if (numBytes < 0) {
        perror("Error sending RCPT TO command");
        exit(EXIT_FAILURE);
    }
    numBytes = send(sockfd, subject, strlen(subject), 0);
    if (numBytes < 0) {
        perror("Error sending subject");
        exit(EXIT_FAILURE);
    }

    // Send DATA command
    numBytes = send(sockfd, "DATA\r\n", 7, 0);
    if (numBytes < 0) {
        perror("Error sending DATA command");
        exit(EXIT_FAILURE);
    }

    // Send message body
    numBytes = send(sockfd, "Subject: ", 10, 0);
    if (numBytes < 0) {
        perror("Error sending subject");
        exit(EXIT_FAILURE);
    }
    numBytes = send(sockfd, message, strlen(message), 0);
    if (numBytes < 0) {
        perror("Error sending message");
        exit(EXIT_FAILURE);
    }

    // Send QUIT command
    numBytes = send(sockfd, "QUIT\r\n", 7, 0);
    if (numBytes < 0) {
        perror("Error sending QUIT command");
        exit(EXIT_FAILURE);
    }

    // Close socket
    close(sockfd);

    return 0;
}