//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>

#define MAXLINE 1024

int main(int argc, char **argv){
    int sockfd, n;
    char recvline[MAXLINE + 1];
    struct sockaddr_in servaddr;
    
    if (argc != 3) {
        printf("usage: %s <IPaddress> <port>\n", argv[0]);
        exit(1);
    }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("socket error\n");
        exit(1);
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        printf("inet_pton error for %s\n", argv[1]);
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        printf("connect error\n");
        exit(1);
    }

    char helo_cmd[MAXLINE], mail_cmd[MAXLINE], rcpt_cmd[MAXLINE], data_cmd[MAXLINE], from_addr[MAXLINE], to_addr[MAXLINE], msg[MAXLINE];
    sprintf(helo_cmd, "HELO %s\r\n", argv[1]); // greeting the server
    sprintf(mail_cmd, "MAIL FROM: <%s>\r\n", from_addr); // sender address
    sprintf(rcpt_cmd, "RCPT TO: <%s>\r\n", to_addr); // recipient address
    sprintf(data_cmd, "DATA\r\n"); // start sending data
    sprintf(msg, "From: <%s>\r\nTo: <%s>\r\nSubject: SMTP example\r\n\r\nHello, how are you?", from_addr, to_addr); // message to be sent
    
    char smtp_msg[MAXLINE];
    
    // sending HELO command and receiving server response
    send(sockfd, helo_cmd, strlen(helo_cmd), 0);
    n = recv(sockfd, smtp_msg, MAXLINE, 0);
    if (n < 0) {
        printf("recv error\n");
        exit(1);
    }
    smtp_msg[n] = 0;
    printf("Server response: %s", smtp_msg);
    
    // sending MAIL command and receiving server response
    send(sockfd, mail_cmd, strlen(mail_cmd), 0);
    n = recv(sockfd, smtp_msg, MAXLINE, 0);
    if (n < 0) {
        printf("recv error\n");
        exit(1);
    }
    smtp_msg[n] = 0;
    printf("Server response: %s", smtp_msg);
    
    // sending RCPT command and receiving server response
    send(sockfd, rcpt_cmd, strlen(rcpt_cmd), 0);
    n = recv(sockfd, smtp_msg, MAXLINE, 0);
    if (n < 0) {
        printf("recv error\n");
        exit(1);
    }
    smtp_msg[n] = 0;
    printf("Server response: %s", smtp_msg);
    
    // sending DATA command and receiving server response
    send(sockfd, data_cmd, strlen(data_cmd), 0);
    n = recv(sockfd, smtp_msg, MAXLINE, 0);
    if (n < 0) {
        printf("recv error\n");
        exit(1);
    }
    smtp_msg[n] = 0;
    printf("Server response: %s", smtp_msg);
    
    // sending message body and receiving server response
    send(sockfd, msg, strlen(msg), 0);
    n = recv(sockfd, smtp_msg, MAXLINE, 0);
    if (n < 0) {
        printf("recv error\n");
        exit(1);
    }
    smtp_msg[n] = 0;
    printf("Server response: %s", smtp_msg);
    
    // sending QUIT command and receiving server response
    send(sockfd, "QUIT\r\n", strlen("QUIT\r\n"), 0);
    n = recv(sockfd, smtp_msg, MAXLINE, 0);
    if (n < 0) {
        printf("recv error\n");
        exit(1);
    }
    smtp_msg[n] = 0;
    printf("Server response: %s", smtp_msg);

    close(sockfd);
    exit(0);
}