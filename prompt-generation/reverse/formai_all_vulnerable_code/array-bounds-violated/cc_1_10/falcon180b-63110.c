//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_LINE 1024
#define POP3_PORT 110
#define USER "username"
#define PASS "password"
#define SERVER "pop.gmail.com"

int main() {
    int sockfd;
    struct sockaddr_in serveraddr;
    char buffer[MAX_LINE];
    char send_buffer[MAX_LINE];
    char *ptr;
    int n, bytes_read;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(POP3_PORT);
    inet_pton(AF_INET, SERVER, &serveraddr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to %s:%d\n", inet_ntoa(serveraddr.sin_addr), ntohs(serveraddr.sin_port));

    send(sockfd, "USER ", strlen("USER "), 0);
    send(sockfd, USER, strlen(USER), 0);
    send(sockfd, "\r\n", strlen("\r\n"), 0);

    while ((bytes_read = recv(sockfd, buffer, MAX_LINE, 0)) > 0) {
        buffer[bytes_read] = '\0';
        printf("%s", buffer);

        if (strstr(buffer, "+OK")) {
            sprintf(send_buffer, "PASS %s\r\n", PASS);
            send(sockfd, send_buffer, strlen(send_buffer), 0);
        }
    }

    close(sockfd);
    return 0;
}