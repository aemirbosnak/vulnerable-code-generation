//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define PORT 21
#define MAX_LINE 1024
#define USER "anonymous"
#define PASS "anonymous@example.com"

char *command = "LIST\r\n";
char *filename = "test.txt";

void ftp_connect(int *sockfd) {
    struct sockaddr_in serveraddr;
    int opt = 1;
    char hostname[50] = "192.168.1.100"; // change to your ftp server IP address
    int portno = PORT;

    *sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (*sockfd == 0) {
        printf("socket creation failed\n");
        exit(0);
    }

    if (setsockopt(*sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        printf("setsockopt failed\n");
        exit(0);
    }

    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = inet_addr(hostname);
    serveraddr.sin_port = htons(portno);

    if (connect(*sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0) {
        printf("connection failed\n");
        exit(0);
    }
}

void ftp_login(int sockfd) {
    char *login = "USER ";
    char *pass = "PASS ";
    char response[MAX_LINE];
    char user_pass[100];

    strcat(login, USER);
    strcat(pass, PASS);

    send(sockfd, login, strlen(login), 0);
    recv(sockfd, response, MAX_LINE, 0);

    strcat(user_pass, login);
    strcat(user_pass, "\r\n");

    send(sockfd, user_pass, strlen(user_pass), 0);
    recv(sockfd, response, MAX_LINE, 0);
}

void ftp_send_command(int sockfd, char *command) {
    send(sockfd, command, strlen(command), 0);
    recv(sockfd, command, MAX_LINE, 0);
}

void ftp_download_file(int sockfd, char *filename) {
    char command[100];
    strcpy(command, "RETR ");
    strcat(command, filename);

    ftp_send_command(sockfd, command);
}

int main() {
    int sockfd;
    ftp_connect(&sockfd);
    ftp_login(sockfd);
    ftp_download_file(sockfd, filename);

    close(sockfd);
    return 0;
}