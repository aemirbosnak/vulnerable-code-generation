//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_LINE 1024

int main(int argc, char* argv[]) {
    if (argc!= 4) {
        printf("Usage: %s <hostname> <username> <password>\n", argv[0]);
        return 1;
    }

    char* hostname = argv[1];
    char* username = argv[2];
    char* password = argv[3];

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);

    struct addrinfo hints, *serverinfo;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    getaddrinfo(hostname, "21", &hints, &serverinfo);

    connect(sockfd, serverinfo->ai_addr, serverinfo->ai_addrlen);

    char login[100] = "USER ";
    strcat(login, username);
    strcat(login, "\r\n");

    send(sockfd, login, strlen(login), 0);

    char pass[100] = "PASS ";
    strcat(pass, password);
    strcat(pass, "\r\n");

    send(sockfd, pass, strlen(pass), 0);

    char cmd[MAX_LINE];

    while (1) {
        bzero(cmd, MAX_LINE);
        fgets(cmd, MAX_LINE, stdin);

        send(sockfd, cmd, strlen(cmd), 0);

        bzero(cmd, MAX_LINE);
        recv(sockfd, cmd, MAX_LINE, 0);

        printf("%s", cmd);
    }

    close(sockfd);

    return 0;
}