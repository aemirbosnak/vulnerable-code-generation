//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[BUF_SIZE];
    int numbytes;

    if (argc != 3) {
        fprintf(stderr, "usage: ./smtp_client <server_address> <port_number>\n");
        exit(1);
    }

    // create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    // set address information
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_port = htons(atoi(argv[2]));

    // connect to server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        exit(1);
    }

    // read initial greeting message
    numbytes = recv(sock, buffer, BUF_SIZE - 1, 0);
    buffer[numbytes] = '\0';
    printf("%s", buffer);

    // send HELO message
    char helo[BUF_SIZE];
    sprintf(helo, "HELO %s\r\n", "mydomain.com");
    send(sock, helo, strlen(helo), 0);

    // read server response
    numbytes = recv(sock, buffer, BUF_SIZE - 1, 0);
    buffer[numbytes] = '\0';
    printf("%s", buffer);

    // send MAIL FROM message
    char mail_from[BUF_SIZE];
    sprintf(mail_from, "MAIL FROM:<%s>\r\n", "sender@mydomain.com");
    send(sock, mail_from, strlen(mail_from), 0);

    // read server response
    numbytes = recv(sock, buffer, BUF_SIZE - 1, 0);
    buffer[numbytes] = '\0';
    printf("%s", buffer);

    // send RCPT TO message
    char rcpt_to[BUF_SIZE];
    sprintf(rcpt_to, "RCPT TO:<%s>\r\n", "recipient@otherdomain.com");
    send(sock, rcpt_to, strlen(rcpt_to), 0);

    // read server response
    numbytes = recv(sock, buffer, BUF_SIZE - 1, 0);
    buffer[numbytes] = '\0';
    printf("%s", buffer);

    // send DATA message
    char data[BUF_SIZE];
    sprintf(data, "DATA\r\n");
    send(sock, data, strlen(data), 0);

    // read server response
    numbytes = recv(sock, buffer, BUF_SIZE - 1, 0);
    buffer[numbytes] = '\0';
    printf("%s", buffer);

    // send email message
    char email[BUF_SIZE];
    sprintf(email, "From: <%s>\r\nTo: <%s>\r\nSubject: Test email\r\n\r\nThis is a test email.\r\n.\r\n", "sender@mydomain.com", "recipient@otherdomain.com");
    send(sock, email, strlen(email), 0);

    // read server response
    numbytes = recv(sock, buffer, BUF_SIZE - 1, 0);
    buffer[numbytes] = '\0';
    printf("%s", buffer);

    // send QUIT message
    char quit[BUF_SIZE];
    sprintf(quit, "QUIT\r\n");
    send(sock, quit, strlen(quit), 0);

    // read server response
    numbytes = recv(sock, buffer, BUF_SIZE - 1, 0);
    buffer[numbytes] = '\0';
    printf("%s", buffer);

    // close socket
    close(sock);

    return 0;
}