//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUFSIZE 1024
#define POP3_PORT 110

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <username>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *hostname = argv[1];
    char *username = argv[2];
    char password[BUFSIZE];
    fprintf(stdout, "Please enter your password: ");
    scanf("%s", password);

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket() failed");
        exit(EXIT_FAILURE);
    }

    // Connect to server
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(POP3_PORT);
    if (inet_pton(AF_INET, hostname, &serv_addr.sin_addr) <= 0) {
        perror("inet_pton() failed");
        exit(EXIT_FAILURE);
    }
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect() failed");
        exit(EXIT_FAILURE);
    }

    // Read greeting message from server
    char recv_buf[BUFSIZE];
    if (recv(sockfd, recv_buf, BUFSIZE, 0) < 0) {
        perror("recv() failed");
        exit(EXIT_FAILURE);
    }
    fprintf(stdout, "Server greeting:\n%s", recv_buf);

    // Send username and password
    char send_buf[BUFSIZE];
    sprintf(send_buf, "USER %s\r\n", username);
    if (send(sockfd, send_buf, strlen(send_buf), 0) < 0) {
        perror("send() failed");
        exit(EXIT_FAILURE);
    }
    if (recv(sockfd, recv_buf, BUFSIZE, 0) < 0) {
        perror("recv() failed");
        exit(EXIT_FAILURE);
    }
    fprintf(stdout, "Server response:\n%s", recv_buf);

    sprintf(send_buf, "PASS %s\r\n", password);
    if (send(sockfd, send_buf, strlen(send_buf), 0) < 0) {
        perror("send() failed");
        exit(EXIT_FAILURE);
    }
    if (recv(sockfd, recv_buf, BUFSIZE, 0) < 0) {
        perror("recv() failed");
        exit(EXIT_FAILURE);
    }
    fprintf(stdout, "Server response:\n%s", recv_buf);

    // List emails
    sprintf(send_buf, "LIST\r\n");
    if (send(sockfd, send_buf, strlen(send_buf), 0) < 0) {
        perror("send() failed");
        exit(EXIT_FAILURE);
    }
    if (recv(sockfd, recv_buf, BUFSIZE, 0) < 0) {
        perror("recv() failed");
        exit(EXIT_FAILURE);
    }
    fprintf(stdout, "Server response:\n%s", recv_buf);

    // Quit
    sprintf(send_buf, "QUIT\r\n");
    if (send(sockfd, send_buf, strlen(send_buf), 0) < 0) {
        perror("send() failed");
        exit(EXIT_FAILURE);
    }
    if (recv(sockfd, recv_buf, BUFSIZE, 0) < 0) {
        perror("recv() failed");
        exit(EXIT_FAILURE);
    }
    fprintf(stdout, "Server response:\n%s", recv_buf);

    // Close socket
    if (close(sockfd) < 0) {
        perror("close() failed");
        exit(EXIT_FAILURE);
    }

    return 0;
}