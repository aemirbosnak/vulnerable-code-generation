//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define PORT 21

int main(int argc, char *argv[]) {
    int sockfd;
    struct addrinfo hints, *servinfo;
    char *host, *username, *password;
    int rv;

    printf("Enter FTP server hostname: ");
    scanf("%s", host);

    printf("Enter FTP server username: ");
    scanf("%s", username);

    printf("Enter FTP server password: ");
    scanf("%s", password);

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    rv = getaddrinfo(host, "21", &hints, &servinfo);
    if (rv!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        exit(1);
    }

    sockfd = socket(servinfo->ai_family, servinfo->ai_socktype, servinfo->ai_protocol);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    rv = connect(sockfd, servinfo->ai_addr, servinfo->ai_addrlen);
    if (rv == -1) {
        perror("connect");
        exit(1);
    }

    char *login_message = "USER ";
    strcat(login_message, username);
    strcat(login_message, "\r\n");

    send(sockfd, login_message, strlen(login_message), 0);

    char *password_message = "PASS ";
    strcat(password_message, password);
    strcat(password_message, "\r\n");

    send(sockfd, password_message, strlen(password_message), 0);

    char buffer[BUFFER_SIZE];
    memset(buffer, 0, BUFFER_SIZE);

    char *command = "LIST\r\n";
    send(sockfd, command, strlen(command), 0);

    while (recv(sockfd, buffer, BUFFER_SIZE, 0) > 0) {
        printf("%s", buffer);
    }

    close(sockfd);
    return 0;
}