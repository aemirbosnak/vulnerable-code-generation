//Falcon-180B DATASET v1.0 Category: Email Client ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>

#define MAX_LINE 1024
#define SERVER_PORT "25"
#define SERVER_ADDR "localhost"
#define FROM_ADDR "funny.programmer@example.com"
#define TO_ADDR "recipient@example.com"
#define SUBJECT "A Funny Email"
#define BODY "Hello, World! This is a funny email sent by a C program. \r\n"
#define DELIMITER "\r\n"
#define BUFFER_SIZE 1024

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    char *ptr;
    int n;
    FILE *fp;
    char line[MAX_LINE];
    time_t now;
    char *date_str;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error: socket() failed\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(SERVER_PORT));
    server_addr.sin_addr.s_addr = inet_addr(SERVER_ADDR);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error: connect() failed\n");
        exit(1);
    }

    printf("Connected to server\n");

    fp = fopen("email.txt", "r");
    if (fp == NULL) {
        printf("Error: could not open email.txt\n");
        exit(1);
    }

    while (fgets(line, MAX_LINE, fp)!= NULL) {
        n = strlen(line);
        if (line[n-1] == '\n') {
            line[--n] = '\0';
        }
        send(sockfd, line, n, 0);
        if (line[n-2] == '.') {
            break;
        }
    }

    fclose(fp);

    while ((n = recv(sockfd, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[n] = '\0';
        printf("%s", buffer);
    }

    close(sockfd);

    return 0;
}