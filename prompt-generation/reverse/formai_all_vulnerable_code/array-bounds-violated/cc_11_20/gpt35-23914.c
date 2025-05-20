//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAXLINE 1024    // Maximum buffer size

int main(int argc, char **argv) {
    int sockfd, n;
    struct sockaddr_in servaddr;
    char sendline[MAXLINE], recvline[MAXLINE];

    // Check if server info is provided correctly
    if (argc != 3) {
        printf("Usage: ./smtpclient <IP address> <port number>\n");
        exit(1);
    }

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Socket creation error.\n");
        exit(1);
    }

    // Set server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(argv[1]);
    servaddr.sin_port = htons(atoi(argv[2]));

    // Connect to server
    if (connect(sockfd, (struct sockaddr*) &servaddr, sizeof(servaddr)) < 0) {
        printf("Connection error.\n");
        exit(1);
    }

    // Receive welcome message from server
    if ((n = recv(sockfd, recvline, MAXLINE, 0)) < 0) {
        printf("Error receiving message from server.\n");
        exit(1);
    }
    recvline[n] = 0;
    printf("%s", recvline);

    // Send greeting message to server
    sprintf(sendline, "HELO localhost\r\n");
    if (send(sockfd, sendline, strlen(sendline), 0) < 0) {
        printf("Error sending message to server.\n");
        exit(1);
    }

    // Receive acknowledgement from server
    if ((n = recv(sockfd, recvline, MAXLINE, 0)) < 0) {
        printf("Error receiving message from server.\n");
        exit(1);
    }
    recvline[n] = 0;
    printf("%s", recvline);

    // Send mail from address
    sprintf(sendline, "MAIL FROM:<sender@example.com>\r\n");
    if (send(sockfd, sendline, strlen(sendline), 0) < 0) {
        printf("Error sending message to server.\n");
        exit(1);
    }

    // Receive acknowledgement from server
    if ((n = recv(sockfd, recvline, MAXLINE, 0)) < 0) {
        printf("Error receiving message from server.\n");
        exit(1);
    }
    recvline[n] = 0;
    printf("%s", recvline);

    // Send mail to address
    sprintf(sendline, "RCPT TO:<recipient@example.com>\r\n");
    if (send(sockfd, sendline, strlen(sendline), 0) < 0) {
        printf("Error sending message to server.\n");
        exit(1);
    }

    // Receive acknowledgement from server
    if ((n = recv(sockfd, recvline, MAXLINE, 0)) < 0) {
        printf("Error receiving message from server.\n");
        exit(1);
    }
    recvline[n] = 0;
    printf("%s", recvline);

    // Send email data
    sprintf(sendline, "DATA\r\n");
    if (send(sockfd, sendline, strlen(sendline), 0) < 0) {
        printf("Error sending message to server.\n");
        exit(1);
    }

    // Receive acknowledgement from server
    if ((n = recv(sockfd, recvline, MAXLINE, 0)) < 0) {
        printf("Error receiving message from server.\n");
        exit(1);
    }
    recvline[n] = 0;
    printf("%s", recvline);

    // Send email message
    sprintf(sendline, "From: sender@example.com\r\n"
                      "To: recipient@example.com\r\n"
                      "Subject: Test\r\n\r\n"
                      "This is a test email.\r\n"
                      ".\r\n");
    if (send(sockfd, sendline, strlen(sendline), 0) < 0) {
        printf("Error sending message to server.\n");
        exit(1);
    }

    // Receive acknowledgement from server
    if ((n = recv(sockfd, recvline, MAXLINE, 0)) < 0) {
        printf("Error receiving message from server.\n");
        exit(1);
    }
    recvline[n] = 0;
    printf("%s", recvline);

    // Send QUIT message
    sprintf(sendline, "QUIT\r\n");
    if (send(sockfd, sendline, strlen(sendline), 0) < 0) {
        printf("Error sending message to server.\n");
        exit(1);
    }

    // Close socket
    close(sockfd);

    return 0;
}