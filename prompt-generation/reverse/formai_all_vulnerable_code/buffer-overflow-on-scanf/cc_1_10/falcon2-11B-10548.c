//Falcon2-11B DATASET v1.0 Category: Building a SMTP Client ; Style: automated
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAXLINE 1024
#define MAXEMAIL 100

void send_mail(char *to, char *from, char *msg) {
    struct hostent *server;
    struct sockaddr_in server_addr;
    int sockfd, n;
    char line[MAXLINE];
    char buffer[MAXEMAIL];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Error opening socket\n");
        exit(1);
    }

    bzero(&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(25);

    server = gethostbyname("smtp.gmail.com");
    if (server == NULL) {
        fprintf(stderr, "Error, no such host\n");
        exit(1);
    }

    bcopy((char *)server->h_addr, (char *)&server_addr.sin_addr.s_addr, server->h_length);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        fprintf(stderr, "Error connecting to SMTP server\n");
        exit(1);
    }

    sprintf(buffer, "EHLO %s", "localhost");
    write(sockfd, buffer, strlen(buffer));
    if (gets(line) == NULL) {
        fprintf(stderr, "Error reading server response\n");
        exit(1);
    }

    if (strstr(line, "250 OK") == NULL) {
        fprintf(stderr, "Error, server rejected HELO request\n");
        exit(1);
    }

    sprintf(buffer, "MAIL FROM: %s", from);
    write(sockfd, buffer, strlen(buffer));
    if (gets(line) == NULL) {
        fprintf(stderr, "Error reading server response\n");
        exit(1);
    }

    if (strstr(line, "250 OK") == NULL) {
        fprintf(stderr, "Error, server rejected MAIL FROM request\n");
        exit(1);
    }

    sprintf(buffer, "RCPT TO: %s", to);
    write(sockfd, buffer, strlen(buffer));
    if (gets(line) == NULL) {
        fprintf(stderr, "Error reading server response\n");
        exit(1);
    }

    if (strstr(line, "250 OK") == NULL) {
        fprintf(stderr, "Error, server rejected RCPT TO request\n");
        exit(1);
    }

    sprintf(buffer, "DATA");
    write(sockfd, buffer, strlen(buffer));
    if (gets(line) == NULL) {
        fprintf(stderr, "Error reading server response\n");
        exit(1);
    }

    if (strstr(line, "354 Start mail input; end with <CRLF>.<CRLF>") == NULL) {
        fprintf(stderr, "Error, server rejected DATA request\n");
        exit(1);
    }

    sprintf(buffer, "%s\r\n", msg);
    write(sockfd, buffer, strlen(buffer));
    if (gets(line) == NULL) {
        fprintf(stderr, "Error reading server response\n");
        exit(1);
    }

    if (strstr(line, "250 OK") == NULL) {
        fprintf(stderr, "Error, server rejected DATA request\n");
        exit(1);
    }

    sprintf(buffer, "QUIT");
    write(sockfd, buffer, strlen(buffer));
    if (gets(line) == NULL) {
        fprintf(stderr, "Error reading server response\n");
        exit(1);
    }

    if (strstr(line, "221 Goodbye") == NULL) {
        fprintf(stderr, "Error, server rejected QUIT request\n");
        exit(1);
    }

    close(sockfd);
}

int main() {
    char to[MAXEMAIL];
    char from[MAXEMAIL];
    char msg[MAXEMAIL];
    int i;

    printf("Enter email address: ");
    scanf("%s", to);

    printf("Enter sender email address: ");
    scanf("%s", from);

    printf("Enter message: ");
    fgets(msg, MAXEMAIL, stdin);

    send_mail(to, from, msg);

    return 0;
}