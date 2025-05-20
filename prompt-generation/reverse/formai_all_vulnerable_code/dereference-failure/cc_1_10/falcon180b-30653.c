//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define PORT 110
#define USER "your_username"
#define PASS "your_password"

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE];
    char *cmd = "PASS ";
    char *pwd = "\r\n";
    char *user = "USER ";
    char *username = USER;
    char *password = PASS;

    if (argc!= 3) {
        printf("Usage:./client <hostname> <port>\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[2]));
    inet_pton(AF_INET, argv[1], &serv_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    send(sockfd, user, strlen(user), 0);
    send(sockfd, username, strlen(username), 0);
    send(sockfd, pwd, strlen(pwd), 0);

    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        n = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (n <= 0) {
            printf("Error receiving data\n");
            exit(1);
        }
        printf("%s", buffer);
    }

    close(sockfd);
    return 0;
}