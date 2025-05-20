//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: all-encompassing
/*
 * FTP client example program.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SERVER_PORT 21
#define MAX_LINE 1024

int main(int argc, char *argv[])
{
    int sockfd;
    struct sockaddr_in servaddr;
    char sendline[MAX_LINE], recvline[MAX_LINE];

    // Check command line arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <IP address> <filename>\n", argv[0]);
        exit(1);
    }

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }

    // Set up the server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SERVER_PORT);
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        perror("inet_pton");
        exit(1);
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        exit(1);
    }

    // Send the username
    strcpy(sendline, "USER anonymous\r\n");
    if (send(sockfd, sendline, strlen(sendline), 0) < 0) {
        perror("send");
        exit(1);
    }

    // Receive the server response
    if (recv(sockfd, recvline, MAX_LINE, 0) == 0) {
        perror("recv");
        exit(1);
    }
    printf("%s", recvline);

    // Send the password
    strcpy(sendline, "PASS anonymous\r\n");
    if (send(sockfd, sendline, strlen(sendline), 0) < 0) {
        perror("send");
        exit(1);
    }

    // Receive the server response
    if (recv(sockfd, recvline, MAX_LINE, 0) == 0) {
        perror("recv");
        exit(1);
    }
    printf("%s", recvline);

    // Send the RETR command
    strcpy(sendline, "RETR ");
    strcat(sendline, argv[2]);
    strcat(sendline, "\r\n");
    if (send(sockfd, sendline, strlen(sendline), 0) < 0) {
        perror("send");
        exit(1);
    }

    // Receive the server response
    if (recv(sockfd, recvline, MAX_LINE, 0) == 0) {
        perror("recv");
        exit(1);
    }
    printf("%s", recvline);

    // Open a file for writing
    FILE *fp = fopen(argv[2], "w");
    if (fp == NULL) {
        perror("fopen");
        exit(1);
    }

    // Receive the file data
    while (recv(sockfd, recvline, MAX_LINE, 0) > 0) {
        fwrite(recvline, 1, strlen(recvline), fp);
    }

    // Close the file
    fclose(fp);

    // Send the QUIT command
    strcpy(sendline, "QUIT\r\n");
    if (send(sockfd, sendline, strlen(sendline), 0) < 0) {
        perror("send");
        exit(1);
    }

    // Close the socket
    close(sockfd);

    return 0;
}