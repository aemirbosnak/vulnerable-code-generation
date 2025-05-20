//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 25 // SMTP port number
#define BUF_SIZE 1024 // buffer size for receiving data

int main(int argc, char *argv[]) {

    int sockfd, status;
    struct addrinfo hints, *servinfo, *p;
    char buffer[BUF_SIZE], response[BUF_SIZE], sender[BUF_SIZE], receiver[BUF_SIZE], subject[BUF_SIZE], message[BUF_SIZE];
    char *server_ip, *input;
    int numbytes;

    if (argc != 2) {
        fprintf(stderr,"Usage: ./smtpclient <SMTP server IP>\n");
        exit(1);
    }

    server_ip = argv[1];

    // set up hints to get address info of server IP and port
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    // get address info of SMTP server
    if ((status = getaddrinfo(server_ip, "25", &hints, &servinfo)) != 0) {
        fprintf(stderr, "getaddrinfo error: %s\n", gai_strerror(status));
        return 1;
    }

    // loop through all the results and connect to the first one we can
    for(p = servinfo; p != NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            perror("smtpclient: socket");
            continue;
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            perror("smtpclient: connect");
            close(sockfd);
            continue;
        }

        break;
    }

    if (p == NULL) {
        fprintf(stderr, "smtpclient: failed to connect\n");
        return 2;
    }

    // free the address info struct
    freeaddrinfo(servinfo);

    // receive server greeting message
    if ((numbytes = recv(sockfd, buffer, BUF_SIZE-1, 0)) == -1) {
        perror("smtpclient: recv");
        exit(1);
    }
    buffer[numbytes] = '\0';
    printf("%s\n", buffer);

    // send EHLO message
    sprintf(response, "EHLO %s\r\n", server_ip);
    if (send(sockfd, response, strlen(response), 0) == -1) {
        perror("smtpclient: send");
        exit(1);
    }

    // receive server response for EHLO message
    if ((numbytes = recv(sockfd, buffer, BUF_SIZE-1, 0)) == -1) {
        perror("smtpclient: recv");
        exit(1);
    }
    buffer[numbytes] = '\0';
    printf("%s\n", buffer);

    // Get email details from user
    printf("Please enter the sender's email address: ");
    fgets(sender, BUF_SIZE, stdin);
    printf("Please enter the recipient's email address: ");
    fgets(receiver, BUF_SIZE, stdin);
    printf("Please enter the subject: ");
    fgets(subject, BUF_SIZE, stdin);
    printf("Please enter the message: ");
    fgets(message, BUF_SIZE, stdin);

    // send MAIL FROM message
    sprintf(response, "MAIL FROM:<%s>\r\n", sender);
    if (send(sockfd, response, strlen(response), 0) == -1) {
        perror("smtpclient: send");
        exit(1);
    }

    // receive server response for MAIL FROM message
    if ((numbytes = recv(sockfd, buffer, BUF_SIZE-1, 0)) == -1) {
        perror("smtpclient: recv");
        exit(1);
    }
    buffer[numbytes] = '\0';
    printf("%s\n", buffer);

    // send RCPT TO message
    sprintf(response, "RCPT TO:<%s>\r\n", receiver);
    if (send(sockfd, response, strlen(response), 0) == -1) {
        perror("smtpclient: send");
        exit(1);
    }

    // receive server response for RCPT TO message
    if ((numbytes = recv(sockfd, buffer, BUF_SIZE-1, 0)) == -1) {
        perror("smtpclient: recv");
        exit(1);
    }
    buffer[numbytes] = '\0';
    printf("%s\n", buffer);

    // send DATA message
    sprintf(response, "DATA\r\n");
    if (send(sockfd, response, strlen(response), 0) == -1) {
        perror("smtpclient: send");
        exit(1);
    }

    // receive server response for DATA message
    if ((numbytes = recv(sockfd, buffer, BUF_SIZE-1, 0)) == -1) {
        perror("smtpclient: recv");
        exit(1);
    }
    buffer[numbytes] = '\0';
    printf("%s\n", buffer);

    // send email header and message
    sprintf(response, "From: %s\nTo: %s\nSubject: %s\n\n%s\n.\r\n", sender, receiver, subject, message);
    if (send(sockfd, response, strlen(response), 0) == -1) {
        perror("smtpclient: send");
        exit(1);
    }

    // receive server response for email sending
    if ((numbytes = recv(sockfd, buffer, BUF_SIZE-1, 0)) == -1) {
        perror("smtpclient: recv");
        exit(1);
    }
    buffer[numbytes] = '\0';
    printf("%s\n", buffer);

    // send QUIT message
    sprintf(response, "QUIT\r\n");
    if (send(sockfd, response, strlen(response), 0) == -1) {
        perror("smtpclient: send");
        exit(1);
    }

    // receive server response for QUIT message
    if ((numbytes = recv(sockfd, buffer, BUF_SIZE-1, 0)) == -1) {
        perror("smtpclient: recv");
        exit(1);
    }
    buffer[numbytes] = '\0';
    printf("%s\n", buffer);

    // close the socket
    close(sockfd);

    return 0;
}