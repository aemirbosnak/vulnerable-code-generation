//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: accurate
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define FTP_PORT 21
#define FTP_BUFF_SIZE 1024

int main(int argc, char *argv[]) {
    // Validate arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server-ip> <filename>\n", argv[0]);
        return 1;
    }

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return 1;
    }

    // Set up the server address
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(FTP_PORT);
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        perror("connect");
        return 1;
    }

    // Send the USER command
    char buff[FTP_BUFF_SIZE];
    snprintf(buff, FTP_BUFF_SIZE, "USER anonymous\r\n");
    if (send(sockfd, buff, strlen(buff), 0) == -1) {
        perror("send");
        return 1;
    }

    // Receive the server response
    memset(buff, 0, FTP_BUFF_SIZE);
    if (recv(sockfd, buff, FTP_BUFF_SIZE, 0) == -1) {
        perror("recv");
        return 1;
    }

    // Send the PASS command
    snprintf(buff, FTP_BUFF_SIZE, "PASS anonymous@example.com\r\n");
    if (send(sockfd, buff, strlen(buff), 0) == -1) {
        perror("send");
        return 1;
    }

    // Receive the server response
    memset(buff, 0, FTP_BUFF_SIZE);
    if (recv(sockfd, buff, FTP_BUFF_SIZE, 0) == -1) {
        perror("recv");
        return 1;
    }

    // Send the TYPE command
    snprintf(buff, FTP_BUFF_SIZE, "TYPE I\r\n");
    if (send(sockfd, buff, strlen(buff), 0) == -1) {
        perror("send");
        return 1;
    }

    // Receive the server response
    memset(buff, 0, FTP_BUFF_SIZE);
    if (recv(sockfd, buff, FTP_BUFF_SIZE, 0) == -1) {
        perror("recv");
        return 1;
    }

    // Send the RETR command
    snprintf(buff, FTP_BUFF_SIZE, "RETR %s\r\n", argv[2]);
    if (send(sockfd, buff, strlen(buff), 0) == -1) {
        perror("send");
        return 1;
    }

    // Receive the file data
    FILE *fp = fopen(argv[2], "wb");
    if (fp == NULL) {
        perror("fopen");
        return 1;
    }

    while (1) {
        memset(buff, 0, FTP_BUFF_SIZE);
        if (recv(sockfd, buff, FTP_BUFF_SIZE, 0) == -1) {
            perror("recv");
            return 1;
        }

        if (strcmp(buff, "226 Transfer complete.\r\n") == 0) {
            break;
        }

        fwrite(buff, 1, strlen(buff), fp);
    }

    fclose(fp);

    // Send the QUIT command
    snprintf(buff, FTP_BUFF_SIZE, "QUIT\r\n");
    if (send(sockfd, buff, strlen(buff), 0) == -1) {
        perror("send");
        return 1;
    }

    // Close the socket
    close(sockfd);

    return 0;
}