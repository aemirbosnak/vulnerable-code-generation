//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAXLINE 4096 /* Max length of the message to be sent */

int main(int argc, char **argv) {
    int sockfd, n;
    char recvline[MAXLINE + 1];
    struct sockaddr_in servaddr;

    if(argc != 3) {
        fprintf(stderr, "Usage: %s <IP Address> <Port Number>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    /* Creating the socket to be used for sending */
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        fprintf(stderr, "Error creating the socket.\n");
        exit(EXIT_FAILURE);
    }

    /* Setting the IP address and Port number of the server */
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    if(inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        fprintf(stderr, "Invalid IP Address: %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    /* Connecting to the server */
    if(connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        fprintf(stderr, "Error connecting to the server.\n");
        exit(EXIT_FAILURE);
    }

    /* Sending the HELO message to initiate the SMTP conversation */
    char helo[MAXLINE];
    sprintf(helo, "HELO %s\r\n", argv[1]);
    if(write(sockfd, helo, strlen(helo)) < 0) {
        fprintf(stderr, "Error sending the HELO message.\n");
        exit(EXIT_FAILURE);
    }

    /* Receiving and printing the server response */
    if((n = read(sockfd, recvline, MAXLINE)) < 0) {
        fprintf(stderr, "Error receiving the response.\n");
        exit(EXIT_FAILURE);
    }
    recvline[n] = '\0';
    printf("%s", recvline);

    /* Sending the MAIL FROM command to specify the sender address */
    char mailfrom[MAXLINE];
    sprintf(mailfrom, "MAIL FROM: <example@server.com>\r\n");
    if(write(sockfd, mailfrom, strlen(mailfrom)) < 0) {
        fprintf(stderr, "Error sending the MAIL FROM command.\n");
        exit(EXIT_FAILURE);
    }

    /* Receiving and printing the server response */
    if((n = read(sockfd, recvline, MAXLINE)) < 0) {
        fprintf(stderr, "Error receiving the response.\n");
        exit(EXIT_FAILURE);
    }
    recvline[n] = '\0';
    printf("%s", recvline);

    /* Sending the RCPT TO command to specify the recipient address */
    char rcptto[MAXLINE];
    sprintf(rcptto, "RCPT TO: <example@client.com>\r\n");
    if(write(sockfd, rcptto, strlen(rcptto)) < 0) {
        fprintf(stderr, "Error sending the RCPT TO command.\n");
        exit(EXIT_FAILURE);
    }

    /* Receiving and printing the server response */
    if((n = read(sockfd, recvline, MAXLINE)) < 0) {
        fprintf(stderr, "Error receiving the response.\n");
        exit(EXIT_FAILURE);
    }
    recvline[n] = '\0';
    printf("%s", recvline);

    /* Sending the DATA command to start the message data */
    char data[MAXLINE];
    sprintf(data, "DATA\r\n");
    if(write(sockfd, data, strlen(data)) < 0) {
        fprintf(stderr, "Error sending the DATA command.\n");
        exit(EXIT_FAILURE);
    }

    /* Receiving and printing the server response */
    if((n = read(sockfd, recvline, MAXLINE)) < 0) {
        fprintf(stderr, "Error receiving the response.\n");
        exit(EXIT_FAILURE);
    }
    recvline[n] = '\0';
    printf("%s", recvline);

    /* Sending the message body */
    char message[MAXLINE];
    sprintf(message, "From: example@server.com\r\nTo: example@client.com\r\nSubject: SMTP Test\r\n\r\nThis is a test message sent using SMTP Client.\r\n.\r\n");
    if(write(sockfd, message, strlen(message)) < 0) {
        fprintf(stderr, "Error sending the message body.\n");
        exit(EXIT_FAILURE);
    }

    /* Receiving and printing the server response */
    if((n = read(sockfd, recvline, MAXLINE)) < 0) {
        fprintf(stderr, "Error receiving the response.\n");
        exit(EXIT_FAILURE);
    }
    recvline[n] = '\0';
    printf("%s", recvline);

    /* Sending the QUIT command to end the conversation */
    char quit[MAXLINE];
    sprintf(quit, "QUIT\r\n");
    if(write(sockfd, quit, strlen(quit)) < 0) {
        fprintf(stderr, "Error sending the QUIT command.\n");
        exit(EXIT_FAILURE);
    }

    /* Receiving and printing the server response */
    if((n = read(sockfd, recvline, MAXLINE)) < 0) {
        fprintf(stderr, "Error receiving the response.\n");
        exit(EXIT_FAILURE);
    }
    recvline[n] = '\0';
    printf("%s", recvline);

    /* Closing the socket */
    close(sockfd);

    return 0;
}