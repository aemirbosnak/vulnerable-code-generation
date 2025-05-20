//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define SERVER "imap.example.com"
#define PORT 143

void read_response(int sockfd, char* response) {
    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));
    int nbytes = recv(sockfd, buffer, sizeof(buffer), 0);
    if (nbytes < 0) {
        perror("recv");
        exit(1);
    }
    buffer[nbytes] = '\0';
    strcpy(response, buffer);
}

int main() {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(SERVER);
    server_addr.sin_port = htons(PORT);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        exit(1);
    }

    char response[1024];
    read_response(sockfd, response);
    printf("%s", response);

    char* username = "username";
    char* password = "password";

    char command[1024];
    sprintf(command, "a001 LOGIN %s %s\r\n", username, password);
    send(sockfd, command, strlen(command), 0);

    read_response(sockfd, response);
    printf("%s", response);

    sprintf(command, "a002 LIST \"\" *\r\n");
    send(sockfd, command, strlen(command), 0);

    read_response(sockfd, response);
    printf("%s", response);

    sprintf(command, "a003 SELECT INBOX\r\n");
    send(sockfd, command, strlen(command), 0);

    read_response(sockfd, response);
    printf("%s", response);

    sprintf(command, "a004 FETCH 1 FULL\r\n");
    send(sockfd, command, strlen(command), 0);

    read_response(sockfd, response);
    printf("%s", response);

    sprintf(command, "a005 LOGOUT\r\n");
    send(sockfd, command, strlen(command), 0);

    read_response(sockfd, response);
    printf("%s", response);

    close(sockfd);
    return 0;
}