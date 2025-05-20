//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SERVER_PORT 25
#define MAX_MSG_LEN 1024

int main(int argc, char **argv) {
    struct hostent *hp;
    struct sockaddr_in sin;
    char *host;
    char buf[MAX_MSG_LEN];
    int s;
    int len;
    
    if (argc != 2) {
        fprintf(stderr, "usage: %s <hostname>\n", argv[0]);
        exit(1);
    }
    host = argv[1];

    // get IP of the hostname
    hp = gethostbyname(host);
    if (!hp) {
        fprintf(stderr, "%s: unknown host\n", host);
        exit(1);
    }

    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    memcpy(&sin.sin_addr, hp->h_addr, hp->h_length);
    sin.sin_port = htons(SERVER_PORT);

    // connect to SMTP server
    s = socket(AF_INET, SOCK_STREAM, 0);
    if (connect(s, (struct sockaddr *)&sin, sizeof(sin)) < 0) {
        perror("connect error");
        exit(1);
    }

    // receive greeting message from SMTP server
    len = recv(s, buf, MAX_MSG_LEN, 0);
    if (len < 0) {
        perror("recv error");
        exit(1);
    }
    buf[len] = '\0';
    printf("%s", buf);

    // send HELO command
    printf("HELO myclient.com\r\n");
    if (send(s, "HELO myclient.com\r\n", strlen("HELO myclient.com\r\n"), 0) < 0) {
        perror("send error");
        exit(1);
    }
    len = recv(s, buf, MAX_MSG_LEN, 0);
    if (len < 0) {
        perror("recv error");
        exit(1);
    }
    buf[len] = '\0';
    printf("%s", buf);

    // send MAIL FROM command
    printf("MAIL FROM:<sender@example.com>\r\n");
    if (send(s, "MAIL FROM:<sender@example.com>\r\n", strlen("MAIL FROM:<sender@example.com>\r\n"), 0) < 0) {
        perror("send error");
        exit(1);
    }
    len = recv(s, buf, MAX_MSG_LEN, 0);
    if (len < 0) {
        perror("recv error");
        exit(1);
    }
    buf[len] = '\0';
    printf("%s", buf);

    // send RCPT TO command
    printf("RCPT TO:<recipient@example.com>\r\n");
    if (send(s, "RCPT TO:<recipient@example.com>\r\n", strlen("RCPT TO:<recipient@example.com>\r\n"), 0) < 0) {
        perror("send error");
        exit(1);
    }
    len = recv(s, buf, MAX_MSG_LEN, 0);
    if (len < 0) {
        perror("recv error");
        exit(1);
    }
    buf[len] = '\0';
    printf("%s", buf);

    // send DATA command
    printf("DATA\r\n");
    if (send(s, "DATA\r\n", strlen("DATA\r\n"), 0) < 0) {
        perror("send error");
        exit(1);
    }
    len = recv(s, buf, MAX_MSG_LEN, 0);
    if (len < 0) {
        perror("recv error");
        exit(1);
    }
    buf[len] = '\0';
    printf("%s", buf);

    // send message body
    printf("From: sender@example.com\r\nTo: recipient@example.com\r\nSubject: Test message\r\n\r\nHello world!\r\n.\r\n");
    if (send(s, "From: sender@example.com\r\nTo: recipient@example.com\r\nSubject: Test message\r\n\r\nHello world!\r\n.\r\n", 
             strlen("From: sender@example.com\r\nTo: recipient@example.com\r\nSubject: Test message\r\n\r\nHello world!\r\n.\r\n"), 0) < 0) {
        perror("send error");
        exit(1);
    }
    len = recv(s, buf, MAX_MSG_LEN, 0);
    if (len < 0) {
        perror("recv error");
        exit(1);
    }
    buf[len] = '\0';
    printf("%s", buf);

    // send QUIT command
    printf("QUIT\r\n");
    if (send(s, "QUIT\r\n", strlen("QUIT\r\n"), 0) < 0) {
        perror("send error");
        exit(1);
    }
    len = recv(s, buf, MAX_MSG_LEN, 0);
    if (len < 0) {
        perror("recv error");
        exit(1);
    }
    buf[len] = '\0';
    printf("%s", buf);

    // close socket
    close(s);

    return 0;
}