//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_MSG_LENGTH 1024
#define SMTP_SERVER "smtp.example.com"
#define SMTP_PORT 25

int main() {
    // Initialize variables
    int sockfd;
    char msg[MAX_MSG_LENGTH];
    struct sockaddr_in serv_addr;
    struct hostent *server;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        perror("Error opening socket");
        exit(1);
    }

    // Get server information
    server = gethostbyname(SMTP_SERVER);
    if(server == NULL) {
        fprintf(stderr, "Error: No such host\n");
        exit(1);
    }

    // Set server address struct
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(SMTP_PORT);
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    // Connect to server
    if(connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting");
        exit(1);
    }

    // Receive server greeting
    memset(msg, 0, MAX_MSG_LENGTH);
    if(recv(sockfd, msg, MAX_MSG_LENGTH, 0) < 0) {
        perror("Error receiving greeting");
        exit(1);
    }

    // Send HELO command
    sprintf(msg, "HELO %s\n", SMTP_SERVER);
    if(send(sockfd, msg, strlen(msg), 0) < 0) {
        perror("Error sending HELO");
        exit(1);
    }

    // Receive response to HELO command
    memset(msg, 0, MAX_MSG_LENGTH);
    if(recv(sockfd, msg, MAX_MSG_LENGTH, 0) < 0) {
        perror("Error receiving response to HELO");
        exit(1);
    }

    // Send MAIL FROM command
    sprintf(msg, "MAIL FROM:<sender@example.com>\n");
    if(send(sockfd, msg, strlen(msg), 0) < 0) {
        perror("Error sending MAIL FROM");
        exit(1);
    }

    // Receive response to MAIL FROM command
    memset(msg, 0, MAX_MSG_LENGTH);
    if(recv(sockfd, msg, MAX_MSG_LENGTH, 0) < 0) {
        perror("Error receiving response to MAIL FROM");
        exit(1);
    }

    // Send RCPT TO command
    sprintf(msg, "RCPT TO:<recipient@example.com>\n");
    if(send(sockfd, msg, strlen(msg), 0) < 0) {
        perror("Error sending RCPT TO");
        exit(1);
    }

    // Receive response to RCPT TO command
    memset(msg, 0, MAX_MSG_LENGTH);
    if(recv(sockfd, msg, MAX_MSG_LENGTH, 0) < 0) {
        perror("Error receiving response to RCPT TO");
        exit(1);
    }

    // Send DATA command
    sprintf(msg, "DATA\n");
    if(send(sockfd, msg, strlen(msg), 0) < 0) {
        perror("Error sending DATA");
        exit(1);
    }

    // Receive response to DATA command
    memset(msg, 0, MAX_MSG_LENGTH);
    if(recv(sockfd, msg, MAX_MSG_LENGTH, 0) < 0) {
        perror("Error receiving response to DATA");
        exit(1);
    }

    // Send message body
    sprintf(msg, "From: sender@example.com\nTo: recipient@example.com\nSubject: Example Email\n\nHello, this is an example email!\n.\n");
    if(send(sockfd, msg, strlen(msg), 0) < 0) {
        perror("Error sending message body");
        exit(1);
    }

    // Receive response to message body
    memset(msg, 0, MAX_MSG_LENGTH);
    if(recv(sockfd, msg, MAX_MSG_LENGTH, 0) < 0) {
        perror("Error receiving response to message body");
        exit(1);
    }

    // Send QUIT command
    sprintf(msg, "QUIT\n");
    if(send(sockfd, msg, strlen(msg), 0) < 0) {
        perror("Error sending QUIT");
        exit(1);
    }

    // Receive response to QUIT command
    memset(msg, 0, MAX_MSG_LENGTH);
    if(recv(sockfd, msg, MAX_MSG_LENGTH, 0) < 0) {
        perror("Error receiving response to QUIT");
        exit(1);
    }

    // Close socket
    close(sockfd);

    // Exit program
    return 0;
}