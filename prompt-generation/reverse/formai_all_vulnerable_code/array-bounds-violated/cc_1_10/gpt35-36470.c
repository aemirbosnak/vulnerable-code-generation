//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER "mail.example.com"
#define PORT 25

void send_email(int sock, char *msg) {
    int len = strlen(msg);
    if (len == 0) return;
    int sent = send(sock, msg, len, 0);
    if (sent <= 0) {
        perror("send");
        exit(EXIT_FAILURE);
    }
    printf("Sent: %s", msg);
    char buf[1024];
    int rcv = recv(sock, buf, sizeof(buf), 0);
    if (rcv <= 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    buf[rcv] = '\0';
    printf("Received: %s", buf);
    send_email(sock, strtok(NULL, "\r\n"));
}

int main() {
    struct sockaddr_in server;
    int sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(SERVER);
    server.sin_port = htons(PORT);
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("connect");
        exit(EXIT_FAILURE);
    }
    char buf[1024];
    int rcv = recv(sock, buf, sizeof(buf), 0);
    if (rcv <= 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }
    buf[rcv] = '\0';
    printf("Received: %s", buf);
    char *msg = "HELO example.com\r\n";
    send_email(sock, msg);
    msg = "MAIL FROM:<me@example.com>\r\n";
    send_email(sock, msg);
    msg = "RCPT TO:<you@example.com>\r\n";
    send_email(sock, msg);
    msg = "DATA\r\n";
    send_email(sock, msg);
    msg = "Subject: Test email\r\n\r\nThis is a test message.\r\n.\r\n";
    send_email(sock, msg);
    msg = "QUIT\r\n";
    send_email(sock, msg);
    close(sock);
    return 0;
}