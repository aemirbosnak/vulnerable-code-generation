//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

#define MAX_LINE 2048

int main(int argc, char *argv[]) {

    if(argc != 4) {
        fprintf(stderr, "Usage: %s <IP> <port> <sender_email_address>\n", argv[0]);
        exit(1);
    }

    struct sockaddr_in server_addr;
    char *IP = argv[1];                             // IP address of the SMTP server
    int port = atoi(argv[2]);                       // Port number of the SMTP server
    char *sender = argv[3];                         // Sender's email address

    // Create a TCP socket
    int sockfd;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        perror("socket() error");
        exit(1);
    }

    // Fill in the server's address details
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    if(inet_pton(AF_INET, IP, &server_addr.sin_addr) <= 0) {
        perror("inet_pton() error");
        exit(1);
    }

    // Connect to the server
    if(connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("connect() error");
        exit(1);
    }

    char recv_buff[MAX_LINE];
    memset(recv_buff, 0, MAX_LINE);

    // Receive the server's welcome message
    if(recv(sockfd, recv_buff, MAX_LINE, 0) < 0) {
        perror("recv() error");
        exit(1);
    }

    printf("%s\n", recv_buff);

    // Send the HELO message to initiate the SMTP conversation
    char *helo = "HELO localhost\r\n";
    if(send(sockfd, helo, strlen(helo), 0) < 0) {
        perror("send() error");
        exit(1);
    }

    memset(recv_buff, 0, MAX_LINE);

    // Receive the server's response to the HELO message
    if(recv(sockfd, recv_buff, MAX_LINE, 0) < 0) {
        perror("recv() error");
        exit(1);
    }

    printf("%s\n", recv_buff);

    // Send the MAIL FROM message with the sender's email address
    char mail_from[MAX_LINE];
    sprintf(mail_from, "MAIL FROM: <%s>\r\n", sender);
    if(send(sockfd, mail_from, strlen(mail_from), 0) < 0) {
        perror("send() error");
        exit(1);
    }

    memset(recv_buff, 0, MAX_LINE);

    // Receive the server's response to the MAIL FROM message
    if(recv(sockfd, recv_buff, MAX_LINE, 0) < 0) {
        perror("recv() error");
        exit(1);
    }

    printf("%s\n", recv_buff);

    // Get the recipient's email address from the user
    char recipient[MAX_LINE];
    printf("Recipient email address: ");
    scanf("%s", recipient);

    // Send the RCPT TO message with the recipient's email address
    char rcpt_to[MAX_LINE];
    sprintf(rcpt_to, "RCPT TO: <%s>\r\n", recipient);
    if(send(sockfd, rcpt_to, strlen(rcpt_to), 0) < 0) {
        perror("send() error");
        exit(1);
    }

    memset(recv_buff, 0, MAX_LINE);

    // Receive the server's response to the RCPT TO message
    if(recv(sockfd, recv_buff, MAX_LINE, 0) < 0) {
        perror("recv() error");
        exit(1);
    }

    printf("%s\n", recv_buff);

    // Send the DATA message to start the data transmission
    char *data = "DATA\r\n";
    if(send(sockfd, data, strlen(data), 0) < 0) {
        perror("send() error");
        exit(1);
    }

    memset(recv_buff, 0, MAX_LINE);

    // Receive the server's response to the DATA message
    if(recv(sockfd, recv_buff, MAX_LINE, 0) < 0) {
        perror("recv() error");
        exit(1);
    }

    printf("%s\n", recv_buff);

    // Get the email message from the user
    char message[MAX_LINE];
    memset(message, 0, MAX_LINE);
    printf("Enter your message, end with . on a line by itself:\n");
    char line[MAX_LINE];
    while(1) {
        memset(line, 0, MAX_LINE);
        fgets(line, MAX_LINE, stdin);
        if(strcmp(line, ".\n") == 0) {
            break;
        }
        strcat(message, line);
    }

    // Send the email message to the server
    if(send(sockfd, message, strlen(message), 0) < 0) {
        perror("send() error");
        exit(1);
    }

    // Send the QUIT message to terminate the SMTP conversation
    char *quit = "QUIT\r\n";
    if(send(sockfd, quit, strlen(quit), 0) < 0) {
        perror("send() error");
        exit(1);
    }

    memset(recv_buff, 0, MAX_LINE);

    // Receive the server's response to the QUIT message
    if(recv(sockfd, recv_buff, MAX_LINE, 0) < 0) {
        perror("recv() error");
        exit(1);
    }

    printf("%s\n", recv_buff);

    // Close the socket
    close(sockfd);

    return 0;
}