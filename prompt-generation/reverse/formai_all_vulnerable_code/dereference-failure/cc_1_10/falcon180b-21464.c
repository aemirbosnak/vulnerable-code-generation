//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/sendfile.h>

#define BUFFER_SIZE 1024
#define SERVER_PORT 25
#define SERVER_ADDRESS "smtp.gmail.com"

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];

    if (argc < 3) {
        printf("Usage:./smtp_client <username> <password>\n");
        exit(1);
    }

    char *username = argv[1];
    char *password = argv[2];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_ADDRESS, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    char *helo_cmd = "HELO localhost\r\n";
    send(sockfd, helo_cmd, strlen(helo_cmd), 0);

    char *auth_cmd = "AUTH LOGIN\r\n";
    send(sockfd, auth_cmd, strlen(auth_cmd), 0);

    char *user_cmd = "USER ";
    strcat(user_cmd, username);
    send(sockfd, user_cmd, strlen(user_cmd), 0);

    char *pass_cmd = "PASS ";
    strcat(pass_cmd, password);
    send(sockfd, pass_cmd, strlen(pass_cmd), 0);

    char *mail_cmd = "MAIL FROM:<";
    strcat(mail_cmd, username);
    strcat(mail_cmd, ">\r\n");
    send(sockfd, mail_cmd, strlen(mail_cmd), 0);

    char *rcpt_cmd = "RCPT TO:<";
    strcat(rcpt_cmd, username);
    strcat(rcpt_cmd, ">\r\n");
    send(sockfd, rcpt_cmd, strlen(rcpt_cmd), 0);

    char *data_cmd = "DATA\r\n";
    send(sockfd, data_cmd, strlen(data_cmd), 0);

    FILE *fp;
    fp = fopen("message.txt", "r");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    char ch;
    while ((ch = fgetc(fp))!= EOF) {
        send(sockfd, &ch, sizeof(ch), 0);
    }

    fclose(fp);

    char *dot_cmd = ".\r\n";
    send(sockfd, dot_cmd, strlen(dot_cmd), 0);

    char *quit_cmd = "QUIT\r\n";
    send(sockfd, quit_cmd, strlen(quit_cmd), 0);

    close(sockfd);

    return 0;
}