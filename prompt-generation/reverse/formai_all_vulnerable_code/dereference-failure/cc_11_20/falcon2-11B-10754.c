//Falcon2-11B DATASET v1.0 Category: Building a SMTP Client ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 25
#define SERVER_ADDR "smtp.example.com"
#define USERNAME "your_username"
#define PASSWORD "your_password"
#define MSG "Hello, world!"

int main()
{
    int sockfd, n;
    struct sockaddr_in serv_addr;

    // create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("ERROR opening socket");
        exit(EXIT_FAILURE);
    }

    // fill in the server address
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, SERVER_ADDR, &serv_addr.sin_addr) <= 0) {
        perror("ERROR, cannot resolve server address");
        exit(EXIT_FAILURE);
    }

    // connect to server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(EXIT_FAILURE);
    }

    // send EHLO command
    char command[50];
    sprintf(command, "EHLO localhost\r\n");
    if (write(sockfd, command, strlen(command)) < 0) {
        perror("ERROR writing to socket");
        exit(EXIT_FAILURE);
    }

    // send AUTH PLAIN command
    sprintf(command, "AUTH PLAIN %s\r\n", USERNAME);
    if (write(sockfd, command, strlen(command)) < 0) {
        perror("ERROR writing to socket");
        exit(EXIT_FAILURE);
    }

    // send AUTH PLAIN password
    sprintf(command, "%s%s", PASSWORD, "\r\n");
    if (write(sockfd, command, strlen(command)) < 0) {
        perror("ERROR writing to socket");
        exit(EXIT_FAILURE);
    }

    // send RCPT TO command
    sprintf(command, "RCPT TO: <recipient_email@example.com>\r\n");
    if (write(sockfd, command, strlen(command)) < 0) {
        perror("ERROR writing to socket");
        exit(EXIT_FAILURE);
    }

    // send DATA command
    sprintf(command, "DATA\r\n");
    if (write(sockfd, command, strlen(command)) < 0) {
        perror("ERROR writing to socket");
        exit(EXIT_FAILURE);
    }

    // send the message
    sprintf(command, "%s\r\n.\r\n", MSG);
    if (write(sockfd, command, strlen(command)) < 0) {
        perror("ERROR writing to socket");
        exit(EXIT_FAILURE);
    }

    // send QUIT command
    sprintf(command, "QUIT\r\n");
    if (write(sockfd, command, strlen(command)) < 0) {
        perror("ERROR writing to socket");
        exit(EXIT_FAILURE);
    }

    // close socket
    close(sockfd);

    return 0;
}