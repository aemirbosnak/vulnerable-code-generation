//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char *argv[]) {
    // Create a socket using TCP (SOCK_STREAM)
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    // Get the server's IP address
    struct hostent *server = gethostbyname("smtp.example.com");
    if (server == NULL) {
        fprintf(stderr, "ERROR: no such host\n");
        exit(1);
    }

    // Set up the server address struct
    struct sockaddr_in serv_addr;
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(25);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR: could not connect");
        exit(1);
    }

    // Read the server's response
    char buffer[4096];
    bzero(buffer, 4096);
    if (read(sockfd, buffer, 4095) < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    printf("%s\n", buffer);

    // Send the HELO command
    char *helo = "HELO myhost.example.com\r\n";
    if (write(sockfd, helo, strlen(helo)) < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }
    bzero(buffer, 4096);
    if (read(sockfd, buffer, 4095) < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    printf("%s\n", buffer);

    // Send the MAIL FROM command
    char *mail_from = "MAIL FROM: <user@example.com>\r\n";
    if (write(sockfd, mail_from, strlen(mail_from)) < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }
    bzero(buffer, 4096);
    if (read(sockfd, buffer, 4095) < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    printf("%s\n", buffer);

    // Send the RCPT TO command
    char *rcpt_to = "RCPT TO: <recipient@example.com>\r\n";
    if (write(sockfd, rcpt_to, strlen(rcpt_to)) < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }
    bzero(buffer, 4096);
    if (read(sockfd, buffer, 4095) < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    printf("%s\n", buffer);

    // Send the DATA command
    char *data = "DATA\r\n";
    if (write(sockfd, data, strlen(data)) < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }
    bzero(buffer, 4096);
    if (read(sockfd, buffer, 4095) < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    printf("%s\n", buffer);

    // Send the email body
    char *body = "From: user@example.com\r\n"
                 "To: recipient@example.com\r\n"
                 "Subject: Test email\r\n"
                 "\r\n"
                 "This is a test email.\r\n"
                 "\r\n"
                 ".\r\n";
    if (write(sockfd, body, strlen(body)) < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }
    bzero(buffer, 4096);
    if (read(sockfd, buffer, 4095) < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    printf("%s\n", buffer);

    // Send the QUIT command
    char *quit = "QUIT\r\n";
    if (write(sockfd, quit, strlen(quit)) < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    // Close the socket
    close(sockfd);

    return 0;
}