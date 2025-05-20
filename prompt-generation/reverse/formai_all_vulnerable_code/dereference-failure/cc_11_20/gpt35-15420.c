//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#define PORT 110
#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, n;
    char buffer[BUF_SIZE];
    struct sockaddr_in serv_addr;
    struct hostent *server;

    if (argc < 3) {
        fprintf(stderr, "usage %s hostname username\n", argv[0]);
        exit(0);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }

    bzero((char *)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(PORT);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    bzero(buffer, BUF_SIZE);
    n = read(sockfd, buffer, BUF_SIZE - 1);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    printf("%s\n", buffer);

    char user_command[BUF_SIZE] = "USER ";
    strcat(user_command, argv[2]);
    strcat(user_command, "\r\n");
    n = write(sockfd, user_command, strlen(user_command));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    bzero(buffer, BUF_SIZE);
    n = read(sockfd, buffer, BUF_SIZE - 1);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    printf("%s\n", buffer);

    char pass_command[BUF_SIZE] = "PASS ";
    char password[50];
    printf("Enter your password: ");
    fgets(password, 50, stdin);
    password[strlen(password) - 1] = '\0';
    strcat(pass_command, password);
    strcat(pass_command, "\r\n");
    n = write(sockfd, pass_command, strlen(pass_command));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    bzero(buffer, BUF_SIZE);
    n = read(sockfd, buffer, BUF_SIZE - 1);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    printf("%s\n", buffer);

    char list_command[BUF_SIZE] = "LIST\r\n";
    n = write(sockfd, list_command, strlen(list_command));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    bzero(buffer, BUF_SIZE);
    n = read(sockfd, buffer, BUF_SIZE - 1);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    printf("%s\n", buffer);

    char quit_command[BUF_SIZE] = "QUIT\r\n";
    n = write(sockfd, quit_command, strlen(quit_command));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    bzero(buffer, BUF_SIZE);
    n = read(sockfd, buffer, BUF_SIZE - 1);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    printf("%s\n", buffer);

    close(sockfd);

    return 0;
}