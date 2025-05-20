//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define MAXLINE 1024

void send_email(char *server_address, char *to, char *from, char *subject, char *message_body);

int main()
{
    char server_address[MAXLINE];
    char to[MAXLINE];
    char from[MAXLINE];
    char subject[MAXLINE];
    char message_body[MAXLINE];

    printf("Enter server address: ");
    fgets(server_address, MAXLINE, stdin);
    server_address[strlen(server_address) - 1] = '\0';

    printf("Enter email recipient: ");
    fgets(to, MAXLINE, stdin);
    to[strlen(to) - 1] = '\0';

    printf("Enter email sender: ");
    fgets(from, MAXLINE, stdin);
    from[strlen(from) - 1] = '\0';

    printf("Enter email subject: ");
    fgets(subject, MAXLINE, stdin);
    subject[strlen(subject) - 1] = '\0';

    printf("Enter email message body: ");
    fgets(message_body, MAXLINE, stdin);
    message_body[strlen(message_body) - 1] = '\0';

    send_email(server_address, to, from, subject, message_body);

    return 0;
}

void send_email(char *server_address, char *to, char *from, char *subject, char *message_body)
{
    int sockfd, n;
    struct sockaddr_in servaddr;
    char recvline[MAXLINE + 1];
    char sendline[MAXLINE + 1];
    struct hostent *he;

    if ((he=gethostbyname(server_address)) == NULL) {
        perror("gethostbyname error");
        exit(1);
    }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket error");
        exit(1);
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(25);
    if (inet_pton(AF_INET, inet_ntoa(*(struct in_addr*)he->h_addr), &servaddr.sin_addr) <= 0) {
        perror("inet_pton error");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        perror("connect error");
        exit(1);
    }

    // Send HELO command
    sprintf(sendline, "HELO %s\r\n", server_address);
    write(sockfd, sendline, strlen(sendline));
    read(sockfd, recvline, MAXLINE);

    // Send MAIL FROM command
    sprintf(sendline, "MAIL FROM: <%s>\r\n", from);
    write(sockfd, sendline, strlen(sendline));
    read(sockfd, recvline, MAXLINE);

    // Send RCPT TO command
    sprintf(sendline, "RCPT TO: <%s>\r\n", to);
    write(sockfd, sendline, strlen(sendline));
    read(sockfd, recvline, MAXLINE);

    // Send DATA command
    sprintf(sendline, "DATA\r\n");
    write(sockfd, sendline, strlen(sendline));
    read(sockfd, recvline, MAXLINE);

    // Send email headers and body
    sprintf(sendline, "From: %s\n", from);
    write(sockfd, sendline, strlen(sendline));
    sprintf(sendline, "To: %s\n", to);
    write(sockfd, sendline, strlen(sendline));
    sprintf(sendline, "Subject: %s\n\n", subject);
    write(sockfd, sendline, strlen(sendline));
    sprintf(sendline, "%s\n", message_body);
    write(sockfd, sendline, strlen(sendline));
    
    // Send QUIT command
    sprintf(sendline, "QUIT\r\n");
    write(sockfd, sendline, strlen(sendline));
    read(sockfd, recvline, MAXLINE);

    close(sockfd);
}