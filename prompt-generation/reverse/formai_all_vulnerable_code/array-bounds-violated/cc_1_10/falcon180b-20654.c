//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <ctype.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define BUF_SIZE 1024
#define USERNAME "username"
#define PASSWORD "password"
#define POP3_PORT 110

int main() {
    int sockfd, n;
    struct addrinfo hints, *serverinfo;
    char buffer[BUF_SIZE];
    char response[BUF_SIZE];
    char username[BUF_SIZE];
    char password[BUF_SIZE];
    char command[BUF_SIZE];
    char *ptr;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo("localhost", "110", &hints, &serverinfo)!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(errno));
        exit(1);
    }

    sockfd = socket(serverinfo->ai_family, serverinfo->ai_socktype, serverinfo->ai_protocol);
    if (sockfd == -1) {
        fprintf(stderr, "socket: %s\n", strerror(errno));
        exit(1);
    }

    if (connect(sockfd, serverinfo->ai_addr, serverinfo->ai_addrlen) == -1) {
        fprintf(stderr, "connect: %s\n", strerror(errno));
        exit(1);
    }

    sprintf(username, "USER %s\r\n", USERNAME);
    send(sockfd, username, strlen(username), 0);

    while ((n = recv(sockfd, buffer, BUF_SIZE, 0)) > 0) {
        buffer[n] = '\0';
        printf("Received: %s", buffer);

        strcpy(response, buffer);
        ptr = strtok(response, "\r\n");
        while (ptr!= NULL) {
            if (strcmp(ptr, "+OK") == 0) {
                sprintf(command, "PASS %s\r\n", PASSWORD);
                send(sockfd, command, strlen(command), 0);
                break;
            }
            ptr = strtok(NULL, "\r\n");
        }
    }

    return 0;
}