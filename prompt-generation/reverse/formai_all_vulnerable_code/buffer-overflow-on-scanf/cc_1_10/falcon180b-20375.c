//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    int sockfd;
    struct sockaddr_in server_addr;
    char username[30], password[30];
    char command[50], response[BUFFER_SIZE];
    int portno = 110;

    printf("Enter POP3 server address: ");
    scanf("%s", server_addr.sin_addr.s_addr);

    printf("Enter POP3 server port: ");
    scanf("%d", &portno);

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(portno);
    server_addr.sin_addr.s_addr = inet_addr(server_addr.sin_addr.s_addr);

    connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

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

    bzero(response, BUFFER_SIZE);

    int bytes_received = recv(sockfd, response, BUFFER_SIZE, 0);

    printf("Response: %s", response);

    close(sockfd);

    return 0;
}