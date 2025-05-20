//GEMINI-pro DATASET v1.0 Category: Email Client ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define SMTP_PORT 25

int main() {
    // Get the target email address
    char recipient_email[100];
    printf("Enter the recipient's email address: ");
    scanf(" %s", recipient_email);

    // Get the subject of the email
    char subject[100];
    printf("Enter the subject of the email: ");
    scanf(" %s", subject);

    // Get the body of the email
    char body[500];
    printf("Enter the body of the email: ");
    scanf(" %s", body);

    // Create a socket for connecting to the SMTP server
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    // Get the IP address of the SMTP server
    struct hostent *he = gethostbyname("smtp.example.com");
    if (he == NULL) {
        perror("gethostbyname");
        exit(1);
    }

    // Connect to the SMTP server
    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(SMTP_PORT);
    addr.sin_addr = *(struct in_addr *)he->h_addr;
    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("connect");
        exit(1);
    }

    // Send the HELO command
    char helo_command[50];
    sprintf(helo_command, "HELO %s\r\n", "my-hostname");
    if (send(sockfd, helo_command, strlen(helo_command), 0) == -1) {
        perror("send");
        exit(1);
    }

    // Receive the server's response
    char response[500];
    if (recv(sockfd, response, sizeof(response), 0) == -1) {
        perror("recv");
        exit(1);
    }

    // Send the MAIL FROM command
    char mail_from_command[50];
    sprintf(mail_from_command, "MAIL FROM: <%s>\r\n", "my-email@example.com");
    if (send(sockfd, mail_from_command, strlen(mail_from_command), 0) == -1) {
        perror("send");
        exit(1);
    }

    // Receive the server's response
    if (recv(sockfd, response, sizeof(response), 0) == -1) {
        perror("recv");
        exit(1);
    }

    // Send the RCPT TO command
    char rcpt_to_command[50];
    sprintf(rcpt_to_command, "RCPT TO: <%s>\r\n", recipient_email);
    if (send(sockfd, rcpt_to_command, strlen(rcpt_to_command), 0) == -1) {
        perror("send");
        exit(1);
    }

    // Receive the server's response
    if (recv(sockfd, response, sizeof(response), 0) == -1) {
        perror("recv");
        exit(1);
    }

    // Send the DATA command
    if (send(sockfd, "DATA\r\n", 6, 0) == -1) {
        perror("send");
        exit(1);
    }

    // Receive the server's response
    if (recv(sockfd, response, sizeof(response), 0) == -1) {
        perror("recv");
        exit(1);
    }

    // Send the email header
    char header[500];
    sprintf(header, "From: %s\r\nTo: %s\r\nSubject: %s\r\n\r\n", "my-email@example.com", recipient_email, subject);
    if (send(sockfd, header, strlen(header), 0) == -1) {
        perror("send");
        exit(1);
    }

    // Send the email body
    if (send(sockfd, body, strlen(body), 0) == -1) {
        perror("send");
        exit(1);
    }

    // Send the dot to indicate the end of the message
    if (send(sockfd, ".\r\n", 3, 0) == -1) {
        perror("send");
        exit(1);
    }

    // Receive the server's response
    if (recv(sockfd, response, sizeof(response), 0) == -1) {
        perror("recv");
        exit(1);
    }

    // Send the QUIT command
    if (send(sockfd, "QUIT\r\n", 6, 0) == -1) {
        perror("send");
        exit(1);
    }

    // Close the socket
    close(sockfd);

    return 0;
}