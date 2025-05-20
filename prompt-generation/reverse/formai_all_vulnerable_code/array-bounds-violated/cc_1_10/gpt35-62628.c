//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define SERVER_PORT "25"
#define SERVER_ADDRESS "smtp.gmail.com"

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct addrinfo hints, *servinfo, *p;
    char buffer[BUFFER_SIZE];
    char response[BUFFER_SIZE];
    char *line = NULL;
    size_t len = 0;
    ssize_t read = 0;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((n = getaddrinfo(SERVER_ADDRESS, SERVER_PORT, &hints, &servinfo)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(n));
        return 1;
    }

    for (p = servinfo; p != NULL; p = p->ai_next) {
        if ((sockfd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            perror("socket");
            continue;
        }

        if (connect(sockfd, p->ai_addr, p->ai_addrlen) == -1) {
            close(sockfd);
            perror("connect");
            continue;
        }

        break;
    }

    if (p == NULL) {
        fprintf(stderr, "failed to connect\n");
        return 2;
    }

    freeaddrinfo(servinfo);

    n = recv(sockfd, response, BUFFER_SIZE - 1, 0);
    response[n] = '\0';
    printf("%s\n", response);

    snprintf(buffer, sizeof(buffer), "EHLO %s\r\n", SERVER_ADDRESS);
    send(sockfd, buffer, strlen(buffer), 0);

    n = recv(sockfd, response, BUFFER_SIZE - 1, 0);
    response[n] = '\0';
    printf("%s\n", response);

    snprintf(buffer, sizeof(buffer), "AUTH LOGIN\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    n = recv(sockfd, response, BUFFER_SIZE - 1, 0);
    response[n] = '\0';
    printf("%s\n", response);

    snprintf(buffer, sizeof(buffer), "%s", "some_email@gmail.com");
    send(sockfd, buffer, strlen(buffer), 0);

    n = recv(sockfd, response, BUFFER_SIZE - 1, 0);
    response[n] = '\0';
    printf("%s\n", response);

    snprintf(buffer, sizeof(buffer), "%s", "some_password");
    send(sockfd, buffer, strlen(buffer), 0);

    n = recv(sockfd, response, BUFFER_SIZE - 1, 0);
    response[n] = '\0';
    printf("%s\n", response);

    snprintf(buffer, sizeof(buffer), "MAIL FROM: <some_email@gmail.com>\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    n = recv(sockfd, response, BUFFER_SIZE - 1, 0);
    response[n] = '\0';
    printf("%s\n", response);

    snprintf(buffer, sizeof(buffer), "RCPT TO: <some_other_email@gmail.com>\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    n = recv(sockfd, response, BUFFER_SIZE - 1, 0);
    response[n] = '\0';
    printf("%s\n", response);

    snprintf(buffer, sizeof(buffer), "DATA\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    n = recv(sockfd, response, BUFFER_SIZE - 1, 0);
    response[n] = '\0';
    printf("%s\n", response);

    printf("Enter the message: ");
    while ((read = getline(&line, &len, stdin)) != -1) {
        if (strcmp(line, ".\n") == 0) {
            break;
        }
        send(sockfd, line, read, 0);
        line = NULL;
        len = 0;
    }

    send(sockfd, "\r\n.\r\n", strlen("\r\n.\r\n"), 0);

    n = recv(sockfd, response, BUFFER_SIZE - 1, 0);
    response[n] = '\0';
    printf("%s\n", response);

    snprintf(buffer, sizeof(buffer), "QUIT\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    n = recv(sockfd, response, BUFFER_SIZE - 1, 0);
    response[n] = '\0';
    printf("%s\n", response);

    close(sockfd);
    return 0;
}