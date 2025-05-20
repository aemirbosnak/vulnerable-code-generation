//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define MAXLINE 1024
#define HOST "smtp.gmail.com"
#define PORT 587

int main(int argc, char **argv){
    int sockfd, n;
    struct sockaddr_in servaddr;
    char sendline[MAXLINE], recvline[MAXLINE];

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0){
        perror("Error creating socket");
        exit(1);
    }

    // Set server address
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);

    struct hostent *h;
    h = gethostbyname(HOST);
    if(h == NULL){
        perror("Error getting server IP");
        exit(1);
    }

    memcpy(&servaddr.sin_addr, h->h_addr_list[0], h->h_length);

    // Connect to server
    if(connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0){
        perror("Error connecting to server");
        exit(1);
    }

    // Send hello message
    snprintf(sendline, MAXLINE, "EHLO client.example.com\r\n");
    send(sockfd, sendline, strlen(sendline), 0);
    if((n = recv(sockfd, recvline, MAXLINE, 0)) < 0){
        perror("Error receiving data from server");
        exit(1);
    }

    // Start TLS
    snprintf(sendline, MAXLINE, "STARTTLS\r\n");
    send(sockfd, sendline, strlen(sendline), 0);
    if((n = recv(sockfd, recvline, MAXLINE, 0)) < 0){
        perror("Error receiving data from server");
        exit(1);
    }

    // Send authentication data
    snprintf(sendline, MAXLINE, "AUTH LOGIN\r\n");
    send(sockfd, sendline, strlen(sendline), 0);
    if((n = recv(sockfd, recvline, MAXLINE, 0)) < 0){
        perror("Error receiving data from server");
        exit(1);
    }

    snprintf(sendline, MAXLINE, "<YOUR_EMAIL_ADDRESS>\r\n");
    send(sockfd, sendline, strlen(sendline), 0);
    if((n = recv(sockfd, recvline, MAXLINE, 0)) < 0){
        perror("Error receiving data from server");
        exit(1);
    }

    snprintf(sendline, MAXLINE, "<YOUR_EMAIL_PASSWORD>\r\n");
    send(sockfd, sendline, strlen(sendline), 0);
    if((n = recv(sockfd, recvline, MAXLINE, 0)) < 0){
        perror("Error receiving data from server");
        exit(1);
    }

    // Send message data
    snprintf(sendline, MAXLINE, "MAIL FROM:<your_email_address>\r\n");
    send(sockfd, sendline, strlen(sendline), 0);
    if((n = recv(sockfd, recvline, MAXLINE, 0)) < 0){
        perror("Error receiving data from server");
        exit(1);
    }

    snprintf(sendline, MAXLINE, "RCPT TO:<recipient_email_address>\r\n");
    send(sockfd, sendline, strlen(sendline), 0);
    if((n = recv(sockfd, recvline, MAXLINE, 0)) < 0){
        perror("Error receiving data from server");
        exit(1);
    }

    snprintf(sendline, MAXLINE, "DATA\r\n");
    send(sockfd, sendline, strlen(sendline), 0);
    if((n = recv(sockfd, recvline, MAXLINE, 0)) < 0){
        perror("Error receiving data from server");
        exit(1);
    }

    // Send message body
    snprintf(sendline, MAXLINE, "From: your_email_address\r\nTo: recipient_email_address\r\nSubject: SMTP Client Example\r\n\r\nThis is a test email from my SMTP client example code.\r\n.\r\n");
    send(sockfd, sendline, strlen(sendline), 0);
    if((n = recv(sockfd, recvline, MAXLINE, 0)) < 0){
        perror("Error receiving data from server");
        exit(1);
    }

    // Close socket
    close(sockfd);
    return 0;
}