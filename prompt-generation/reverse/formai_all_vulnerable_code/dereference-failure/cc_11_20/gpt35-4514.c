//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAXLINE 1024

int main(int argc, char **argv) {
    int sockfd, portno, n;
    struct sockaddr_in servaddr;
    char sendline[MAXLINE];
    char recvline[MAXLINE+1];

    if (argc != 3) {
        fprintf(stderr,"usage: ./smtp_client <IP address> <port>\n");
        exit(1);
    }

    portno = atoi(argv[2]);

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket error");
        exit(2);
    }

    // Initialize the server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(portno);
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        perror("inet_pton error");
        exit(3);
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        perror("connect error");
        exit(4);
    }

    // Read from the server
    n = read(sockfd, recvline, MAXLINE);
    if (n < 0) {
        perror("read error");
        exit(5);
    }
    recvline[n] = 0;
    printf("%s\n", recvline); // Print the server welcome message

    // Send the HELO command
    sprintf(sendline, "HELO localhost\r\n");
    n = write(sockfd, sendline, strlen(sendline));
    if (n < 0) {
        perror("write error");
        exit(6);
    }

    // Read from the server
    n = read(sockfd, recvline, MAXLINE);
    if (n < 0) {
        perror("read error");
        exit(7);
    }
    recvline[n] = 0;
    printf("%s\n", recvline); // Print the server response

    // Send the MAIL FROM command
    sprintf(sendline, "MAIL FROM: <sender@localhost>\r\n");
    n = write(sockfd, sendline, strlen(sendline));
    if (n < 0) {
        perror("write error");
        exit(8);
    }

    // Read from the server
    n = read(sockfd, recvline, MAXLINE);
    if (n < 0) {
        perror("read error");
        exit(9);
    }
    recvline[n] = 0;
    printf("%s\n", recvline); // Print the server response

    // Send the RCPT TO command
    sprintf(sendline, "RCPT TO: <receiver@localhost>\r\n");
    n = write(sockfd, sendline, strlen(sendline));
    if (n < 0) {
        perror("write error");
        exit(10);
    }

    // Read from the server
    n = read(sockfd, recvline, MAXLINE);
    if (n < 0) {
        perror("read error");
        exit(11);
    }
    recvline[n] = 0;
    printf("%s\n", recvline); // Print the server response

    // Send the DATA command
    sprintf(sendline, "DATA\r\n");
    n = write(sockfd, sendline, strlen(sendline));
    if (n < 0) {
        perror("write error");
        exit(12);
    }

    // Read from the server
    n = read(sockfd, recvline, MAXLINE);
    if (n < 0) {
        perror("read error");
        exit(13);
    }
    recvline[n] = 0;
    printf("%s\n", recvline); // Print the server response

    // Send the email body
    sprintf(sendline, "From: sender@localhost\r\nTo: receiver@localhost\r\nSubject: Test email\r\nHello, World!\r\n.\r\n");
    n = write(sockfd, sendline, strlen(sendline));
    if (n < 0) {
        perror("write error");
        exit(14);
    }

    // Read from the server
    n = read(sockfd, recvline, MAXLINE);
    if (n < 0) {
        perror("read error");
        exit(15);
    }
    recvline[n] = 0;
    printf("%s\n", recvline); // Print the server response

    // Send the QUIT command
    sprintf(sendline, "QUIT\r\n");
    n = write(sockfd, sendline, strlen(sendline));
    if (n < 0) {
        perror("write error");
        exit(16);
    }

    // Read from the server
    n = read(sockfd, recvline, MAXLINE);
    if (n < 0) {
        perror("read error");
        exit(17);
    }
    recvline[n] = 0;
    printf("%s\n", recvline); // Print the server response

    // Close the socket
    close(sockfd);

    return 0;
}