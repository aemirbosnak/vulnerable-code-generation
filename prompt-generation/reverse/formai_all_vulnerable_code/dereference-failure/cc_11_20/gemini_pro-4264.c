//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>
#include <errno.h>

#define MAX_LINE 1024

int main(int argc, char **argv) {
    if (argc < 6) {
        printf("Usage: %s <server_ip> <server_port> <sender_email> <recipient_email> <message>\n", argv[0]);
        return 1;
    }

    char *server_ip = argv[1];
    int server_port = atoi(argv[2]);
    char *sender_email = argv[3];
    char *recipient_email = argv[4];
    char *message = argv[5];

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket() failed");
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(server_port);
    inet_pton(AF_INET, server_ip, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect() failed");
        return 1;
    }

    char recv_buf[MAX_LINE];
    int num_bytes_recv;

    num_bytes_recv = recv(sockfd, recv_buf, MAX_LINE, 0);
    if (num_bytes_recv == -1) {
        perror("recv() failed");
        return 1;
    }

    printf("Server: %s\n", recv_buf);

    char send_buf[MAX_LINE];

    sprintf(send_buf, "HELO localhost\r\n");
    if (send(sockfd, send_buf, strlen(send_buf), 0) == -1) {
        perror("send() failed");
        return 1;
    }

    num_bytes_recv = recv(sockfd, recv_buf, MAX_LINE, 0);
    if (num_bytes_recv == -1) {
        perror("recv() failed");
        return 1;
    }

    printf("Server: %s\n", recv_buf);

    sprintf(send_buf, "MAIL FROM: <%s>\r\n", sender_email);
    if (send(sockfd, send_buf, strlen(send_buf), 0) == -1) {
        perror("send() failed");
        return 1;
    }

    num_bytes_recv = recv(sockfd, recv_buf, MAX_LINE, 0);
    if (num_bytes_recv == -1) {
        perror("recv() failed");
        return 1;
    }

    printf("Server: %s\n", recv_buf);

    sprintf(send_buf, "RCPT TO: <%s>\r\n", recipient_email);
    if (send(sockfd, send_buf, strlen(send_buf), 0) == -1) {
        perror("send() failed");
        return 1;
    }

    num_bytes_recv = recv(sockfd, recv_buf, MAX_LINE, 0);
    if (num_bytes_recv == -1) {
        perror("recv() failed");
        return 1;
    }

    printf("Server: %s\n", recv_buf);

    sprintf(send_buf, "DATA\r\n");
    if (send(sockfd, send_buf, strlen(send_buf), 0) == -1) {
        perror("send() failed");
        return 1;
    }

    num_bytes_recv = recv(sockfd, recv_buf, MAX_LINE, 0);
    if (num_bytes_recv == -1) {
        perror("recv() failed");
        return 1;
    }

    printf("Server: %s\n", recv_buf);

    sprintf(send_buf, "Subject: Test Email\r\n\r\n%s\r\n.\r\n", message);
    if (send(sockfd, send_buf, strlen(send_buf), 0) == -1) {
        perror("send() failed");
        return 1;
    }

    num_bytes_recv = recv(sockfd, recv_buf, MAX_LINE, 0);
    if (num_bytes_recv == -1) {
        perror("recv() failed");
        return 1;
    }

    printf("Server: %s\n", recv_buf);

    sprintf(send_buf, "QUIT\r\n");
    if (send(sockfd, send_buf, strlen(send_buf), 0) == -1) {
        perror("send() failed");
        return 1;
    }

    num_bytes_recv = recv(sockfd, recv_buf, MAX_LINE, 0);
    if (num_bytes_recv == -1) {
        perror("recv() failed");
        return 1;
    }

    printf("Server: %s\n", recv_buf);

    close(sockfd);

    return 0;
}