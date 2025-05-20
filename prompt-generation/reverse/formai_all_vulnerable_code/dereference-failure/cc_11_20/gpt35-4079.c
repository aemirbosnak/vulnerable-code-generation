//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[256];
    if (argc < 3) {
       fprintf(stderr,"usage %s hostname port\n", argv[0]);
       exit(0);
    }
    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) 
        error("ERROR opening socket");
    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, 
         (char *)&serv_addr.sin_addr.s_addr,
         server->h_length);
    serv_addr.sin_port = htons(portno);
    if (connect(sockfd,(struct sockaddr *) &serv_addr,sizeof(serv_addr)) < 0) 
        error("ERROR connecting");
    printf("Connected to SMTP server.\n");

    n = read(sockfd, buffer, sizeof(buffer) - 1);
    if (n < 0) 
        error("ERROR reading from socket");
    buffer[n] = '\0';
    printf("%s", buffer);

    printf("Sending HELO message...\n");
    char *helo_message = "HELO test\r\n";
    n = write(sockfd, helo_message, strlen(helo_message));
    if (n < 0) 
        error("ERROR writing to socket");

    n = read(sockfd, buffer, sizeof(buffer) - 1);
    if (n < 0) 
        error("ERROR reading from socket");
    buffer[n] = '\0';
    printf("%s", buffer);

    printf("Sending MAIL FROM message...\n");
    char *mail_from_message = "MAIL FROM:<test@example.com>\r\n";
    n = write(sockfd, mail_from_message, strlen(mail_from_message));
    if (n < 0) 
        error("ERROR writing to socket");

    n = read(sockfd, buffer, sizeof(buffer) - 1);
    if (n < 0) 
        error("ERROR reading from socket");
    buffer[n] = '\0';
    printf("%s", buffer);

    printf("Sending RCPT TO message...\n");
    char *rcpt_to_message = "RCPT TO:<recipient@example.com>\r\n";
    n = write(sockfd, rcpt_to_message, strlen(rcpt_to_message));
    if (n < 0) 
        error("ERROR writing to socket");

    n = read(sockfd, buffer, sizeof(buffer) - 1);
    if (n < 0) 
        error("ERROR reading from socket");
    buffer[n] = '\0';
    printf("%s", buffer);

    printf("Sending DATA message...\n");
    char *data_message = "DATA\r\n";
    n = write(sockfd, data_message, strlen(data_message));
    if (n < 0) 
        error("ERROR writing to socket");

    n = read(sockfd, buffer, sizeof(buffer) - 1);
    if (n < 0) 
        error("ERROR reading from socket");
    buffer[n] = '\0';
    printf("%s", buffer);

    printf("Sending email message...\n");
    char *email_message = "From: test@example.com\r\nTo: recipient@example.com\r\nSubject: Test Email\r\n\r\nThis is a test email message.\r\n.\r\n";
    n = write(sockfd, email_message, strlen(email_message));
    if (n < 0) 
        error("ERROR writing to socket");

    n = read(sockfd, buffer, sizeof(buffer) - 1);
    if (n < 0) 
        error("ERROR reading from socket");
    buffer[n] = '\0';
    printf("%s", buffer);

    printf("Closing connection.\n");
    n = write(sockfd, "QUIT\r\n", strlen("QUIT\r\n"));
    if (n < 0) 
        error("ERROR writing to socket");

    close(sockfd);
    return 0;
}