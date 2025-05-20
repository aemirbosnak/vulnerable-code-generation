//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_LINE 1024

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in servaddr;
    char recvline[MAX_LINE + 1];

    if (argc != 3) {
        fprintf(stderr, "usage: %s <IP address> <port>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        perror("inet_pton");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        perror("connect");
        exit(1);
    }

    // Read the welcome message from the server
    n = read(sockfd, recvline, MAX_LINE);
    if (n < 0) {
        perror("read");
        exit(1);
    }
    recvline[n] = '\0';
    printf("%s", recvline);

    // Send the USER command to the server
    char user[MAX_LINE];
    printf("Enter your username: ");
    fgets(user, MAX_LINE, stdin);
    char user_cmd[MAX_LINE + 6];
    sprintf(user_cmd, "USER %s\r\n", user);
    n = write(sockfd, user_cmd, strlen(user_cmd));
    if (n < 0) {
        perror("write");
        exit(1);
    }

    // Read the server's response to the USER command
    n = read(sockfd, recvline, MAX_LINE);
    if (n < 0) {
        perror("read");
        exit(1);
    }
    recvline[n] = '\0';
    printf("%s", recvline);

    // Send the PASS command to the server
    char pass[MAX_LINE];
    printf("Enter your password: ");
    fgets(pass, MAX_LINE, stdin);
    char pass_cmd[MAX_LINE + 6];
    sprintf(pass_cmd, "PASS %s\r\n", pass);
    n = write(sockfd, pass_cmd, strlen(pass_cmd));
    if (n < 0) {
        perror("write");
        exit(1);
    }

    // Read the server's response to the PASS command
    n = read(sockfd, recvline, MAX_LINE);
    if (n < 0) {
        perror("read");
        exit(1);
    }
    recvline[n] = '\0';
    printf("%s", recvline);

    // Send the LIST command to the server
    char list_cmd[] = "LIST\r\n";
    n = write(sockfd, list_cmd, strlen(list_cmd));
    if (n < 0) {
        perror("write");
        exit(1);
    }

    // Read the server's response to the LIST command
    n = read(sockfd, recvline, MAX_LINE);
    if (n < 0) {
        perror("read");
        exit(1);
    }
    recvline[n] = '\0';
    printf("%s", recvline);

    // Send the RETR command to the server
    char retr_cmd[MAX_LINE + 6];
    printf("Enter the number of the message you want to retrieve: ");
    char msg_num[MAX_LINE];
    fgets(msg_num, MAX_LINE, stdin);
    sprintf(retr_cmd, "RETR %s\r\n", msg_num);
    n = write(sockfd, retr_cmd, strlen(retr_cmd));
    if (n < 0) {
        perror("write");
        exit(1);
    }

    // Read the server's response to the RETR command
    n = read(sockfd, recvline, MAX_LINE);
    if (n < 0) {
        perror("read");
        exit(1);
    }
    recvline[n] = '\0';
    printf("%s", recvline);

    // Read the email content from the server
    while ((n = read(sockfd, recvline, MAX_LINE)) > 0) {
        recvline[n] = '\0';
        printf("%s", recvline);
    }
    if (n < 0) {
        perror("read");
        exit(1);
    }

    // Send the QUIT command to the server
    char quit_cmd[] = "QUIT\r\n";
    n = write(sockfd, quit_cmd, strlen(quit_cmd));
    if (n < 0) {
        perror("write");
        exit(1);
    }

    // Close the socket
    close(sockfd);

    return 0;
}