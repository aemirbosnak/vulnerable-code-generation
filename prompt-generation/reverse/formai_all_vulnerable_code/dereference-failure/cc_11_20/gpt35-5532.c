//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFSIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <server> <port> <username>\n", argv[0]);
        exit(1);
    }

    // Extract arguments
    char *server = argv[1];
    int port = atoi(argv[2]);
    char *username = argv[3];

    // Connect to server
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    if (inet_pton(AF_INET, server, &servaddr.sin_addr) <= 0) {
        perror("inet_pton error");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        perror("connect error");
        exit(1);
    }

    // Receive server greeting message
    char buf[BUFSIZE];
    if (recv(sockfd, buf, BUFSIZE, 0) == 0) {
        printf("Server disconnected\n");
        exit(1);
    }
    printf("Server says: %s", buf);

    // Send login command
    char login_command[BUFSIZE];
    snprintf(login_command, BUFSIZE, "LOGIN %s\n", username);
    if (send(sockfd, login_command, strlen(login_command), 0) < 0) {
        perror("send error");
        exit(1);
    }

    // Receive login response
    if (recv(sockfd, buf, BUFSIZE, 0) == 0) {
        printf("Server disconnected\n");
        exit(1);
    }
    printf("Server says: %s", buf);

    // Send SELECT command to select INBOX
    char select_command[] = "SELECT INBOX\n";
    if (send(sockfd, select_command, strlen(select_command), 0) < 0) {
        perror("send error");
        exit(1);
    }

    // Receive SELECT response
    if (recv(sockfd, buf, BUFSIZE, 0) == 0) {
        printf("Server disconnected\n");
        exit(1);
    }
    printf("Server says: %s", buf);

    // Send FETCH command to retrieve first 5 messages
    char fetch_command[] = "FETCH 1:5 BODY[TEXT]\n";
    if (send(sockfd, fetch_command, strlen(fetch_command), 0) < 0) {
        perror("send error");
        exit(1);
    }

    // Receive FETCH response
    if (recv(sockfd, buf, BUFSIZE, 0) == 0) {
        printf("Server disconnected\n");
        exit(1);
    }
    printf("Server says: %s", buf);

    // Send LOGOUT command
    char logout_command[] = "LOGOUT\n";
    if (send(sockfd, logout_command, strlen(logout_command), 0) < 0) {
        perror("send error");
        exit(1);
    }

    // Receive server closing message
    if (recv(sockfd, buf, BUFSIZE, 0) == 0) {
        printf("Server disconnected\n");
        exit(1);
    }
    printf("Server says: %s", buf);

    close(sockfd);

    return 0;
}