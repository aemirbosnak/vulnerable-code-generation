//MISTRAL-7B DATASET v1.0 Category: Building a POP3 Client ; Style: minimalist
#include <arpa/inet.h>
#include <netdb.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 110
#define BUFFER_SIZE 1024

void die(const char *msg) {
    perror(msg);
    exit(1);
}

int main() {
    int sockfd;
    struct addrinfo hints, *res;
    int status;
    char buffer[BUFFER_SIZE];

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((status = getaddrinfo("localhost", "pop3", &hints, &res)) != 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
        return 1;
    }

    if ((sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol)) < 0) {
        perror("socket");
        freeaddrinfo(res);
        return 1;
    }

    if (connect(sockfd, res->ai_addr, res->ai_addrlen) < 0) {
        perror("connect");
        freeaddrinfo(res);
        close(sockfd);
        return 1;
    }

    freeaddrinfo(res);

    // greeting exchange
    send(sockfd, "+OK POP3 server ready\r\n", 17, 0);
    recv(sockfd, buffer, BUFFER_SIZE, 0);

    // user authentication
    printf("Enter your username: ");
    scanf("%s", buffer);
    send(sockfd, "USER ", 5, 0);
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, BUFFER_SIZE, 0);

    printf("Enter your password: ");
    fgets(buffer, BUFFER_SIZE, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
    send(sockfd, "PASS ", 5, 0);
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, BUFFER_SIZE, 0);

    // selecting a mailbox
    send(sockfd, "LIST ", 5, 0);
    recv(sockfd, buffer, BUFFER_SIZE, 0);

    int idx = 0;
    while (buffer[idx] != ' ') {
        idx++;
    }
    idx++;

    char mailbox[10];
    strncpy(mailbox, buffer + idx, 9);
    mailbox[9] = '\0';

    send(sockfd, "SELECT ", 7, 0);
    send(sockfd, mailbox, strlen(mailbox), 0);
    recv(sockfd, buffer, BUFFER_SIZE, 0);

    // retrieving messages
    int num_msgs;
    sscanf(buffer, "+OK %d messages %d octets\r\n", &num_msgs, NULL);

    for (int i = 1; i <= num_msgs; i++) {
        printf("\nMessage %d:\n", i);
        send(sockfd, "RETR ", 5, 0);
        recv(sockfd, buffer, BUFFER_SIZE, 0);
        printf("%s", buffer);
    }

    close(sockfd);

    return 0;
}