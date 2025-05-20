//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if(argc != 4) {
        printf("Usage: %s <ip address> <port> <message>\n", argv[0]);
        exit(1);
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(sockfd < 0) {
        perror("create socket error");
        exit(1);
    }
    
    struct sockaddr_in server_addr;
    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    if(connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect error");
        exit(1);
    }

    char buffer[BUFFER_SIZE];
    int n;

    // receive greeting message from server
    if((n = recv(sockfd, buffer, BUFFER_SIZE, 0)) < 0) {
        perror("receive greeting message error");
        exit(1);
    }
    buffer[n] = '\0';
    printf("%s\n", buffer);

    // send HELO message
    char *helo_msg = "HELO server\r\n";
    if(send(sockfd, helo_msg, strlen(helo_msg), 0) < 0) {
        perror("send HELO message error");
        exit(1);
    }

    // receive reply message from server
    if((n = recv(sockfd, buffer, BUFFER_SIZE, 0)) < 0) {
        perror("receive HELO reply message error");
        exit(1);
    }
    buffer[n] = '\0';
    printf("%s\n", buffer);

    // send MAIL FROM message
    char *mail_from_msg = "MAIL FROM:<sender@example.com>\r\n";
    if(send(sockfd, mail_from_msg, strlen(mail_from_msg), 0) < 0) {
        perror("send MAIL FROM message error");
        exit(1);
    }

    // receive reply message from server
    if((n = recv(sockfd, buffer, BUFFER_SIZE, 0)) < 0) {
        perror("receive MAIL FROM reply message error");
        exit(1);
    }
    buffer[n] = '\0';
    printf("%s\n", buffer);

    // send RCPT TO message
    char *rcpt_to_msg = "RCPT TO:<receiver@example.com>\r\n";
    if(send(sockfd, rcpt_to_msg, strlen(rcpt_to_msg), 0) < 0) {
        perror("send RCPT TO message error");
        exit(1);
    }

    // receive reply message from server
    if((n = recv(sockfd, buffer, BUFFER_SIZE, 0)) < 0) {
        perror("receive RCPT TO reply message error");
        exit(1);
    }
    buffer[n] = '\0';
    printf("%s\n", buffer);

    // send DATA message
    char *data_msg = "DATA\r\n";
    if(send(sockfd, data_msg, strlen(data_msg), 0) < 0) {
        perror("send DATA message error");
        exit(1);
    }

    // receive reply message from server
    if((n = recv(sockfd, buffer, BUFFER_SIZE, 0)) < 0) {
        perror("receive DATA reply message error");
        exit(1);
    }
    buffer[n] = '\0';
    printf("%s\n", buffer);

    // send message content
    char *message = argv[3];
    if(send(sockfd, message, strlen(message), 0) < 0) {
        perror("send message error");
        exit(1);
    }
    char *end_msg = "\r\n.\r\n";
    if(send(sockfd, end_msg, strlen(end_msg), 0) < 0) {
        perror("send message end error");
        exit(1);
    }

    // receive reply message from server
    if((n = recv(sockfd, buffer, BUFFER_SIZE, 0)) < 0) {
        perror("receive message end reply message error");
        exit(1);
    }
    buffer[n] = '\0';
    printf("%s\n", buffer);

    // send QUIT message
    char *quit_msg = "QUIT\r\n";
    if(send(sockfd, quit_msg, strlen(quit_msg), 0) < 0) {
        perror("send QUIT message error");
        exit(1);
    }

    // receive reply message from server
    if((n = recv(sockfd, buffer, BUFFER_SIZE, 0)) < 0) {
        perror("receive QUIT reply message error");
        exit(1);
    }
    buffer[n] = '\0';
    printf("%s\n", buffer);

    close(sockfd);
    return 0;
}