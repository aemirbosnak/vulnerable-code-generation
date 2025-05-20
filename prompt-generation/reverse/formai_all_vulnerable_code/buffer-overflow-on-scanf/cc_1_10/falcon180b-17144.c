//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    char *server = "localhost";
    int port = 110;
    int sockfd;
    struct sockaddr_in server_addr;
    char username[64];
    char password[64];
    char buffer[BUFFER_SIZE];

    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, server, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    char *auth_str = "USER ";
    strcat(auth_str, username);
    strcat(auth_str, "\r\n");
    send(sockfd, auth_str, strlen(auth_str), 0);

    char *pass_str = "PASS ";
    strcat(pass_str, password);
    strcat(pass_str, "\r\n");
    send(sockfd, pass_str, strlen(pass_str), 0);

    char *stat_str = "STAT\r\n";
    send(sockfd, stat_str, strlen(stat_str), 0);

    char *list_str = "LIST\r\n";
    send(sockfd, list_str, strlen(list_str), 0);

    char *retr_str = "RETR 1\r\n";
    send(sockfd, retr_str, strlen(retr_str), 0);

    char *dele_str = "DELE 1\r\n";
    send(sockfd, dele_str, strlen(dele_str), 0);

    char *quit_str = "QUIT\r\n";
    send(sockfd, quit_str, strlen(quit_str), 0);

    close(sockfd);
    return 0;
}