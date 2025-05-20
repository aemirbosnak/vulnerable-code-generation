//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

// Define the port number for the email server
#define PORT 25

// Define the maximum length of an email message
#define MAX_MESSAGE_LENGTH 1024

// Define the Romeo and Juliet email addresses
#define ROMEO_EMAIL "romeo@example.com"
#define JULIET_EMAIL "juliet@example.com"

// Define the email server address
#define EMAIL_SERVER "mail.example.com"

// Define the email subject
#define EMAIL_SUBJECT "A Most Excellent Message"

// Define the email body
#define EMAIL_BODY "My dearest Juliet,\n\nI write to thee with a heart full of love and longing. I cannot express the depths of my affection for thee, nor the joy that fills me when I am in thy presence. Thou art the sun that brightens my days and the moon that guides me through the darkest nights. I would cross a thousand seas and climb a thousand mountains just to be with thee.\n\nEver thine,\n\nRomeo"

// Main function
int main() {
    // Create a socket for connecting to the email server
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    // Resolve the email server address
    struct hostent *host = gethostbyname(EMAIL_SERVER);
    if (host == NULL) {
        perror("gethostbyname");
        exit(1);
    }

    // Set up the socket address for the email server
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr = *(struct in_addr *)host->h_addr_list[0];

    // Connect to the email server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        perror("connect");
        exit(1);
    }

    // Send the HELO command to the email server
    char helo[1024];
    sprintf(helo, "HELO %s\r\n", EMAIL_SERVER);
    if (send(sockfd, helo, strlen(helo), 0) == -1) {
        perror("send");
        exit(1);
    }

    // Send the MAIL FROM command to the email server
    char mail_from[1024];
    sprintf(mail_from, "MAIL FROM: <%s>\r\n", ROMEO_EMAIL);
    if (send(sockfd, mail_from, strlen(mail_from), 0) == -1) {
        perror("send");
        exit(1);
    }

    // Send the RCPT TO command to the email server
    char rcpt_to[1024];
    sprintf(rcpt_to, "RCPT TO: <%s>\r\n", JULIET_EMAIL);
    if (send(sockfd, rcpt_to, strlen(rcpt_to), 0) == -1) {
        perror("send");
        exit(1);
    }

    // Send the DATA command to the email server
    char data[1024];
    sprintf(data, "DATA\r\n");
    if (send(sockfd, data, strlen(data), 0) == -1) {
        perror("send");
        exit(1);
    }

    // Send the email subject to the email server
    char subject[1024];
    sprintf(subject, "Subject: %s\r\n", EMAIL_SUBJECT);
    if (send(sockfd, subject, strlen(subject), 0) == -1) {
        perror("send");
        exit(1);
    }

    // Send the email body to the email server
    char body[MAX_MESSAGE_LENGTH];
    sprintf(body, "%s\r\n", EMAIL_BODY);
    if (send(sockfd, body, strlen(body), 0) == -1) {
        perror("send");
        exit(1);
    }

    // Send the end of message indicator to the email server
    char eom[1024];
    sprintf(eom, "\r\n.\r\n");
    if (send(sockfd, eom, strlen(eom), 0) == -1) {
        perror("send");
        exit(1);
    }

    // Send the QUIT command to the email server
    char quit[1024];
    sprintf(quit, "QUIT\r\n");
    if (send(sockfd, quit, strlen(quit), 0) == -1) {
        perror("send");
        exit(1);
    }

    // Close the socket
    close(sockfd);

    return 0;
}