//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_LINE 1024
#define POP3_PORT 110
#define MAX_USERNAME 64
#define MAX_PASSWORD 64
#define MAX_COMMAND 1024

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    char send_line[MAX_LINE];
    char recv_line[MAX_LINE];
    char user_name[MAX_USERNAME];
    char pass_word[MAX_PASSWORD];
    char command[MAX_COMMAND];
    char *token;
    char *delimiter = " ";
    int i;

    printf("Enter user name: ");
    scanf("%s", user_name);

    printf("Enter password: ");
    scanf("%s", pass_word);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(POP3_PORT);
    inet_pton(AF_INET, "localhost", &serv_addr.sin_addr);

    connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    printf("Connected to server\n");

    send(sockfd, "USER ", 5, 0);
    send(sockfd, user_name, strlen(user_name), 0);
    send(sockfd, "\r\n", 2, 0);

    recv(sockfd, recv_line, MAX_LINE, 0);
    printf("Received from server: %s", recv_line);

    token = strtok(recv_line, delimiter);
    if (strcmp(token, "+OK")!= 0) {
        printf("Authentication failed\n");
        exit(1);
    }

    send(sockfd, "PASS ", 5, 0);
    send(sockfd, pass_word, strlen(pass_word), 0);
    send(sockfd, "\r\n", 2, 0);

    recv(sockfd, recv_line, MAX_LINE, 0);
    printf("Received from server: %s", recv_line);

    token = strtok(recv_line, delimiter);
    if (strcmp(token, "+OK")!= 0) {
        printf("Authentication failed\n");
        exit(1);
    }

    printf("Enter POP3 command: ");
    scanf("%s", command);

    send(sockfd, command, strlen(command), 0);
    send(sockfd, "\r\n", 2, 0);

    recv(sockfd, recv_line, MAX_LINE, 0);
    printf("Received from server: %s", recv_line);

    close(sockfd);
    return 0;
}