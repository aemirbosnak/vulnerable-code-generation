//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFSIZE 1024

int main(int argc, char* argv[]) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[BUFSIZE];

    if (argc != 3) {
       fprintf(stderr,"Usage: %s hostname port\n", argv[0]);
       exit(0);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"Error: no such host exists\n");
        exit(0);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[2]));
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);

    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    printf("Connected to SMTP server...\n");

    n = recv(sockfd, buffer, BUFSIZE - 1, 0);
    if (n < 0) {
        perror("Error receiving from server");
        exit(1);
    }

    printf("[S]: %s", buffer);

    // Send HELO command to server
    sprintf(buffer, "HELO client\r\n");
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0) {
        perror("Error sending command to server");
        exit(1);
    }

    printf("[C]: %s", buffer);

    n = recv(sockfd, buffer, BUFSIZE - 1, 0);
    if (n < 0) {
        perror("Error receiving from server");
        exit(1);
    }

    printf("[S]: %s", buffer);

    // Send MAIL FROM command to server
    sprintf(buffer, "MAIL FROM: <johndoe@gmail.com>\r\n");
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0) {
        perror("Error sending command to server");
        exit(1);
    }

    printf("[C]: %s", buffer);

    n = recv(sockfd, buffer, BUFSIZE - 1, 0);
    if (n < 0) {
        perror("Error receiving from server");
        exit(1);
    }

    printf("[S]: %s", buffer);

    // Send RCPT TO command to server
    sprintf(buffer, "RCPT TO: <janedoe@yahoo.com>\r\n");
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0) {
        perror("Error sending command to server");
        exit(1);
    }

    printf("[C]: %s", buffer);

    n = recv(sockfd, buffer, BUFSIZE - 1, 0);
    if (n < 0) {
        perror("Error receiving from server");
        exit(1);
    }

    printf("[S]: %s", buffer);

    // Send DATA command to server
    sprintf(buffer, "DATA\r\n");
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0) {
        perror("Error sending command to server");
        exit(1);
    }

    printf("[C]: %s", buffer);

    n = recv(sockfd, buffer, BUFSIZE - 1, 0);
    if (n < 0) {
        perror("Error receiving from server");
        exit(1);
    }

    printf("[S]: %s", buffer);

    // Send email content to server
    sprintf(buffer, "From: johndoe@gmail.com\r\n");
    strcat(buffer, "To: janedoe@yahoo.com\r\n");
    strcat(buffer, "Subject: Test email\r\n");
    strcat(buffer, "\r\n");
    strcat(buffer, "This is a test email.\r\n");
    strcat(buffer, ".\r\n");
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0) {
        perror("Error sending email content to server");
        exit(1);
    }

    printf("[C]: %s", buffer);

    n = recv(sockfd, buffer, BUFSIZE - 1, 0);
    if (n < 0) {
        perror("Error receiving from server");
        exit(1);
    }

    printf("[S]: %s", buffer);

    // Send QUIT command to server
    sprintf(buffer, "QUIT\r\n");
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0) {
        perror("Error sending command to server");
        exit(1);
    }

    printf("[C]: %s", buffer);

    n = recv(sockfd, buffer, BUFSIZE - 1, 0);
    if (n < 0) {
        perror("Error receiving from server");
        exit(1);
    }

    printf("[S]: %s", buffer);

    printf("Email sent successfully.\n");

    close(sockfd);
    return 0;
}