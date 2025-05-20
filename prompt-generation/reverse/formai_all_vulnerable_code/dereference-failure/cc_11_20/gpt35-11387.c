//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
 
#define MAX_STRING_LEN 100
#define MAX_SIZE 300
#define SMTP_PORT 25
 
int main(int argc, char *argv[])
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[MAX_SIZE];
    char command[MAX_STRING_LEN];
    char recipient[MAX_STRING_LEN];
    char sender[MAX_STRING_LEN];
    char subject[MAX_STRING_LEN];
    char message[MAX_SIZE];
    char mailfrom[MAX_SIZE];
    char rcptto[MAX_SIZE];
    char data[MAX_SIZE];
    char quit[MAX_SIZE];
 
    if (argc < 2) {
       fprintf(stderr,"ERROR, no host provided\n");
       exit(1);
    }
 
    portno = SMTP_PORT;
 
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
 
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }
 
    server = gethostbyname(argv[1]);
 
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(1);
    }
 
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);
 
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }
 
    bzero(buffer, MAX_SIZE);
    n = recv(sockfd, buffer, MAX_SIZE-1, 0);
 
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
 
    buffer[n] = '\0';
    printf("%s\n", buffer);
 
    strcpy(command, "HELO localhost\n");
    n = send(sockfd, command, strlen(command), 0);
 
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }
 
    bzero(buffer, MAX_SIZE);
    n = recv(sockfd, buffer, MAX_SIZE-1, 0);
 
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
 
    buffer[n] = '\0';
    printf("%s\n", buffer);
 
    printf("Enter Sender's email address: ");
    fgets(sender, MAX_STRING_LEN, stdin);
    strtok(sender, "\n");
 
    sprintf(mailfrom, "MAIL FROM:<%s>\n", sender);
    n = send(sockfd, mailfrom, strlen(mailfrom), 0);
 
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }
 
    bzero(buffer, MAX_SIZE);
    n = recv(sockfd, buffer, MAX_SIZE-1, 0);
 
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
 
    buffer[n] = '\0';
    printf("%s\n", buffer);
 
    printf("Enter Recipient's email address: ");
    fgets(recipient, MAX_STRING_LEN, stdin);
    strtok(recipient, "\n");
 
    sprintf(rcptto, "RCPT TO:<%s>\n", recipient);
    n = send(sockfd, rcptto, strlen(rcptto), 0);
 
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }
 
    bzero(buffer, MAX_SIZE);
    n = recv(sockfd, buffer, MAX_SIZE-1, 0);
 
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
 
    buffer[n] = '\0';
    printf("%s\n", buffer);
 
    printf("Enter email subject: ");
    fgets(subject, MAX_STRING_LEN, stdin);
    strtok(subject, "\n");
 
    printf("Enter message:\n");
    fgets(message, MAX_SIZE, stdin);
    strtok(message, "\n");
 
    strcpy(data, "DATA\n");
    n = send(sockfd, data, strlen(data), 0);
 
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }
 
    bzero(buffer, MAX_SIZE);
    n = recv(sockfd, buffer, MAX_SIZE-1, 0);
 
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
 
    buffer[n] = '\0';
    printf("%s\n", buffer);
 
    sprintf(buffer, "Subject: %s\nFrom: %s\nTo: %s\n%s\n.\n", subject, sender, recipient, message);
    n = send(sockfd, buffer, strlen(buffer), 0);
 
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }
 
    bzero(buffer, MAX_SIZE);
    n = recv(sockfd, buffer, MAX_SIZE-1, 0);
 
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
 
    buffer[n] = '\0';
    printf("%s\n", buffer);
 
    strcpy(quit, "QUIT\n");
    n = send(sockfd, quit, strlen(quit), 0);
 
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }
 
    bzero(buffer, MAX_SIZE);
    n = recv(sockfd, buffer, MAX_SIZE-1, 0);
 
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
 
    buffer[n] = '\0';
    printf("%s\n", buffer);
 
    close(sockfd);
 
    return 0;
}