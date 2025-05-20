//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAXLINE 1024
#define PORT 25

int main() {
    int sockfd, n;
    struct sockaddr_in servaddr;
    struct hostent *server;

    char sendline[MAXLINE], recvline[MAXLINE];

    printf("Please enter the email address of the recipient:\n");
    fgets(sendline, MAXLINE, stdin);

    //Removes the new line character from input
    sendline[strcspn(sendline, "\n")] = 0;

    printf("Please enter the message:\n");
    fgets(recvline, MAXLINE, stdin);

    //Removes the new line character from input
    recvline[strcspn(recvline, "\n")] = 0;

    // Get the domain name from email address
    char *domain_name = strrchr(sendline, '@');
    domain_name++;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    server = gethostbyname(domain_name);

    if(server == NULL) {
        perror("Error");
        exit(1);
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    bcopy((char *)server->h_addr, (char *)&servaddr.sin_addr.s_addr, server->h_length);

    // Connect to the server
    if(connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("Error");
        exit(1);
    }

    // Receive the initial message
    n = recv(sockfd, recvline, MAXLINE, 0);

    if(n < 0) {
        perror("Error");
        exit(1);
    }

    printf("Server Response: %s\n", recvline);

    // Send HELO/EHLO command
    sprintf(sendline, "EHLO %s\r\n", domain_name);

    n = send(sockfd, sendline, strlen(sendline), 0);

    if(n < 0) {
        perror("Error");
        exit(1);
    }

    n = recv(sockfd, recvline, MAXLINE, 0);

    if(n < 0) {
        perror("Error");
        exit(1);
    }

    printf("Server Response: %s\n", recvline);

    // Send MAIL FROM command
    sprintf(sendline, "MAIL FROM:<%s>\r\n", sendline);

    n = send(sockfd, sendline, strlen(sendline), 0);

    if(n < 0) {
        perror("Error");
        exit(1);
    }

    n = recv(sockfd, recvline, MAXLINE, 0);

    if(n < 0) {
        perror("Error");
        exit(1);
    }

    printf("Server Response: %s\n", recvline);

    // Send RCPT TO command
    printf("Please enter your email address:\n");
    fgets(sendline, MAXLINE, stdin);

    //Removes the new line character from input
    sendline[strcspn(sendline, "\n")] = 0;

    sprintf(sendline, "RCPT TO:<%s>\r\n", sendline);

    n = send(sockfd, sendline, strlen(sendline), 0);

    if(n < 0) {
        perror("Error");
        exit(1);
    }

    n = recv(sockfd, recvline, MAXLINE, 0);

    if(n < 0) {
        perror("Error");
        exit(1);
    }

    printf("Server Response: %s\n", recvline);

    // Send DATA command
    sprintf(sendline, "DATA\r\n");

    n = send(sockfd, sendline, strlen(sendline), 0);

    if(n < 0) {
        perror("Error");
        exit(1);
    }

    n = recv(sockfd, recvline, MAXLINE, 0);

    if(n < 0) {
        perror("Error");
        exit(1);
    }

    printf("Server Response: %s\n", recvline);

    // Send message
    sprintf(sendline, "Subject: SMTP C Client Test\nFrom: <%s>\nTo: <%s>\n\n%s\n.\r\n", sendline, domain_name, recvline);

    n = send(sockfd, sendline, strlen(sendline), 0);

    if(n < 0) {
        perror("Error");
        exit(1);
    }

    n = recv(sockfd, recvline, MAXLINE, 0);

    if(n < 0) {
        perror("Error");
        exit(1);
    }

    printf("Server Response: %s\n", recvline);

    // Send QUIT command
    sprintf(sendline, "QUIT\r\n");

    n = send(sockfd, sendline, strlen(sendline), 0);

    if(n < 0) {
        perror("Error");
        exit(1);
    }

    n = recv(sockfd, recvline, MAXLINE, 0);

    if(n < 0) {
        perror("Error");
        exit(1);
    }

    printf("Server Response: %s\n", recvline);

    close(sockfd);

    return 0;
}