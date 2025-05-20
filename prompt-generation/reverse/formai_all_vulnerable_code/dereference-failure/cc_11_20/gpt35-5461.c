//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_LINE 2048

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <server_address> <port_number> <sender_email_address>\n", argv[0]);
        exit(1);
    }

    struct hostent *hp;
    struct sockaddr_in sin;
    char *host = argv[1];
    char *sender_addr = argv[3];
    int port = atoi(argv[2]);

    char buffer[MAX_LINE];
    char message[MAX_LINE];
    char temp[MAX_LINE];

    sprintf(message, "From: %s\r\n", sender_addr);
    sprintf(temp, "To: %s\r\n", "recipient@example.com");
    strcat(message, temp);
    sprintf(temp, "Cc: %s\r\n", "cc@example.com");
    strcat(message, temp);
    sprintf(temp, "Subject: Test Email\r\n");
    strcat(message, temp);
    sprintf(temp, "\r\n");
    strcat(message, temp);
    sprintf(temp, "This is a test email message.\r\n");
    strcat(message, temp);

    /* translate host name into peer's IP address */
    hp = gethostbyname(host);
    if (!hp) {
        fprintf(stderr, "unknown host: %s\n", host);
        exit(1);
    }

    /* build address data structure */
    memset((char *)&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    memcpy((char *)&sin.sin_addr, hp->h_addr, hp->h_length);
    sin.sin_port = htons(port);

    /* active open */
    int s = socket(AF_INET, SOCK_STREAM, 0);
    if (s < 0) {
        perror("socket");
        exit(1);
    }

    if (connect(s, (struct sockaddr *)&sin, sizeof(sin)) < 0) {
        perror("connect");
        close(s);
        exit(1);
    }

    /* receive greeting */
    if (recv(s, buffer, MAX_LINE, 0) < 0) {
        perror("error receiving message");
    }

    printf("%s", buffer);

    /* send HELO command */
    sprintf(buffer, "HELO %s\r\n", host);
    if (send(s, buffer, strlen(buffer) + 1, 0) < 0) {
        perror("send");
        close(s);
        exit(1);
    }

    /* receive response */
    if (recv(s, buffer, MAX_LINE, 0) < 0) {
        perror("error receiving message");
    }

    printf("%s", buffer);

    /* send MAIL FROM command */
    sprintf(buffer, "MAIL FROM:<%s>\r\n", sender_addr);
    if (send(s, buffer, strlen(buffer) + 1, 0) < 0) {
        perror("send");
        close(s);
        exit(1);
    }

    /* receive response */
    if (recv(s, buffer, MAX_LINE, 0) < 0) {
        perror("error receiving message");
    }

    printf("%s", buffer);

    /* send RCPT TO command */
    sprintf(buffer, "RCPT TO:<%s>\r\n", "recipient@example.com");
    if (send(s, buffer, strlen(buffer) + 1, 0) < 0) {
        perror("send");
        close(s);
        exit(1);
    }

    /* receive response */
    if (recv(s, buffer, MAX_LINE, 0) < 0) {
        perror("error receiving message");
    }

    printf("%s", buffer);

    /* send DATA command */
    sprintf(buffer, "DATA\r\n");
    if (send(s, buffer, strlen(buffer) + 1, 0) < 0) {
        perror("send");
        close(s);
        exit(1);
    }

    /* receive response */
    if (recv(s, buffer, MAX_LINE, 0) < 0) {
        perror("error receiving message");
    }

    printf("%s", buffer);

    /* send message body */
    if (send(s, message, strlen(message) + 1, 0) < 0) {
        perror("send");
        close(s);
        exit(1);
    }

    /* send period to indicate end of message */
    sprintf(buffer, ".\r\n");
    if (send(s, buffer, strlen(buffer) + 1, 0) < 0) {
        perror("send");
        close(s);
        exit(1);
    }

    /* receive response */
    if (recv(s, buffer, MAX_LINE, 0) < 0) {
        perror("error receiving message");
    }

    printf("%s", buffer);

    /* send QUIT command */
    sprintf(buffer, "QUIT\r\n");
    if (send(s, buffer, strlen(buffer) + 1, 0) < 0) {
        perror("send");
        close(s);
        exit(1);
    }

    /* receive response */
    if (recv(s, buffer, MAX_LINE, 0) < 0) {
        perror("error receiving message");
    }

    printf("%s", buffer);

    close(s);

    return 0;
}