//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#define PORT 25

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[1024];
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("Error opening socket");
        exit(1);
    }

    server = gethostbyname(argv[1]);

    if (server == NULL) {
        perror("Error, no such host");
        exit(0);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    serv_addr.sin_addr = *((struct in_addr*) server->h_addr);
    bzero(&(serv_addr.sin_zero), 8);
    if (connect(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    bzero(buffer, 1024); 
    n = read(sockfd, buffer, 1023); 
    if (n < 0) {
        perror("Error reading from socket");
        exit(1);
    }
    printf("%s\n", buffer);

    char sender[50];
    char receiver[50];
    char message[1024];
    char data[1024];

    printf("Enter sender email address: ");
    scanf("%s", sender);
    printf("Enter recipient email address: ");
    scanf("%s", receiver);

    sprintf(message, "From: %s\n", sender);
    sprintf(data, "To: %s\n", receiver);
    strcat(message, data);

    bzero(data, 1024);
    printf("Enter message: ");
    scanf("%s", data);
    strcat(message, data);

    n = write(sockfd, "HELO client.com\r\n", strlen("HELO client.com\r\n"));

    if (n < 0) {
        perror("Error writing to socket");
        exit(1);
    }

    bzero(buffer, 1024);
    n = read(sockfd, buffer, 1023);
    if (n < 0) {
        perror("Error reading from socket");
        exit(1);
    }
    printf("%s\n", buffer);

    n = write(sockfd, "MAIL FROM:<", strlen("MAIL FROM:<"));
    n += write(sockfd, sender, strlen(sender));
    n += write(sockfd, ">\r\n", strlen(">\r\n"));

    if (n < 0) {
        perror("Error writing to socket");
        exit(1);
    }

    bzero(buffer, 1024);
    n = read(sockfd, buffer, 1023);
    if (n < 0) {
        perror("Error reading from socket");
        exit(1);
    }
    printf("%s\n", buffer);

    n = write(sockfd, "RCPT TO:<", strlen("RCPT TO:<"));
    n += write(sockfd, receiver, strlen(receiver));
    n += write(sockfd, ">\r\n", strlen(">\r\n"));

    if (n < 0) {
        perror("Error writing to socket");
        exit(1);
    }

    bzero(buffer, 1024);
    n = read(sockfd, buffer, 1023);
    if (n < 0) {
        perror("Error reading from socket");
        exit(1);
    }
    printf("%s\n", buffer);

    n = write(sockfd, "DATA\r\n", strlen("DATA\r\n"));

    if (n < 0) {
        perror("Error writing to socket");
        exit(1);
    }

    bzero(buffer, 1024);
    n = read(sockfd, buffer, 1023);
    if (n < 0) {
        perror("Error reading from socket");
        exit(1);
    }
    printf("%s\n", buffer);

    n = write(sockfd, message, strlen(message));
    n += write(sockfd, "\r\n.\r\n", strlen("\r\n.\r\n"));

    if (n < 0) {
        perror("Error writing to socket");
        exit(1);
    }

    bzero(buffer, 1024);
    n = read(sockfd, buffer, 1023);
    if (n < 0) {
        perror("Error reading from socket");
        exit(1);
    }
    printf("%s\n", buffer);

    n = write(sockfd, "QUIT\r\n", strlen("QUIT\r\n"));

    if (n < 0) {
        perror("Error writing to socket");
        exit(1);
    }

    bzero(buffer, 1024);
    n = read(sockfd, buffer, 1023);
    if (n < 0) {
        perror("Error reading from socket");
        exit(1);
    }
    printf("%s\n", buffer);

    close(sockfd);
    return 0;
}