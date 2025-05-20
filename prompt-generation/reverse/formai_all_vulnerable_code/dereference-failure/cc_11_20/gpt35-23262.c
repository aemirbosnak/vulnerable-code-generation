//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_MESSAGE_SIZE 1024
#define MAX_RESPONSE_SIZE 2048

int main(int argc, char* argv[])
{
    if (argc != 4) {
        printf("Usage: ./smtp_client <mail_from_address> <rcpt_to_address> <smtp_server_address>\n");
        exit(0);
    }
  
    char* mail_from = argv[1];
    char* rcpt_to = argv[2];
    char* smtp_server = argv[3];
    char message[MAX_MESSAGE_SIZE];
    char response[MAX_RESPONSE_SIZE];
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent* server;
  
    portno = 25; // default SMTP server port number

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    server = gethostbyname(smtp_server);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    n = recv(sockfd, response, MAX_RESPONSE_SIZE-1, 0);
    response[n] = '\0';
    printf("%s", response);

    // Send EHLO command
    snprintf(message, MAX_MESSAGE_SIZE, "EHLO %s\r\n", smtp_server);
    n = send(sockfd, message, strlen(message), 0);
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    n = recv(sockfd, response, MAX_RESPONSE_SIZE-1, 0);
    response[n] = '\0';
    printf("%s", response);

    // Send MAIL FROM command
    snprintf(message, MAX_MESSAGE_SIZE, "MAIL FROM:<%s>\r\n", mail_from);
    n = send(sockfd, message, strlen(message), 0);
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    n = recv(sockfd, response, MAX_RESPONSE_SIZE-1, 0);
    response[n] = '\0';
    printf("%s", response);

    // Send RCPT TO command
    snprintf(message, MAX_MESSAGE_SIZE, "RCPT TO:<%s>\r\n", rcpt_to);
    n = send(sockfd, message, strlen(message), 0);
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    n = recv(sockfd, response, MAX_RESPONSE_SIZE-1, 0);
    response[n] = '\0';
    printf("%s", response);

    // Send DATA command
    snprintf(message, MAX_MESSAGE_SIZE, "DATA\r\n");
    n = send(sockfd, message, strlen(message), 0);
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    n = recv(sockfd, response, MAX_RESPONSE_SIZE-1, 0);
    response[n] = '\0';
    printf("%s", response);

    // Send message body
    printf("Enter message:\n");
    fgets(message, MAX_MESSAGE_SIZE-1, stdin);
    n = send(sockfd, message, strlen(message), 0);
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    // Send period to signify end of message
    snprintf(message, MAX_MESSAGE_SIZE, ".\r\n");
    n = send(sockfd, message, strlen(message), 0);
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    n = recv(sockfd, response, MAX_RESPONSE_SIZE-1, 0);
    response[n] = '\0';
    printf("%s", response);

    // Send QUIT command
    snprintf(message, MAX_MESSAGE_SIZE, "QUIT\r\n");
    n = send(sockfd, message, strlen(message), 0);
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    n = recv(sockfd, response, MAX_RESPONSE_SIZE-1, 0);
    response[n] = '\0';
    printf("%s", response);

    close(sockfd);
    return 0;
}