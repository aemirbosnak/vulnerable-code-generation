//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define PORT 110
#define USER "your_username"
#define PASS "your_password"
#define HOST "pop.gmail.com"

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error opening socket\n");
        exit(1);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    serv_addr.sin_addr.s_addr = inet_addr(HOST);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    char auth[100];
    sprintf(auth, "USER %s\r\n", USER);
    write(sockfd, auth, strlen(auth));
    recv(sockfd, buffer, BUFFER_SIZE, 0);

    sprintf(auth, "PASS %s\r\n", PASS);
    write(sockfd, auth, strlen(auth));
    recv(sockfd, buffer, BUFFER_SIZE, 0);

    char quit[10];
    strcpy(quit, "QUIT\r\n");
    write(sockfd, quit, strlen(quit));
    recv(sockfd, buffer, BUFFER_SIZE, 0);

    close(sockfd);
    return 0;
}