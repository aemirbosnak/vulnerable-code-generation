//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUF_SIZE 1024
#define PORT 21
#define SERVER "192.168.1.100"
#define USER "ftpuser"
#define PASS "ftppass"

int main(int argc, char *argv[]) {
    int sockfd, ret;
    struct sockaddr_in servaddr;
    char send_buffer[BUF_SIZE], recv_buffer[BUF_SIZE];
    int len;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    // Set server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    inet_pton(AF_INET, SERVER, &servaddr.sin_addr);

    // Connect to server
    ret = connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
    if (ret == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    // Send username and password
    sprintf(send_buffer, "USER %s\r\n", USER);
    send(sockfd, send_buffer, strlen(send_buffer), 0);
    len = recv(sockfd, recv_buffer, BUF_SIZE, 0);
    if (len <= 0) {
        printf("Error receiving server response\n");
        exit(1);
    }
    printf("Server response: %s", recv_buffer);

    sprintf(send_buffer, "PASS %s\r\n", PASS);
    send(sockfd, send_buffer, strlen(send_buffer), 0);
    len = recv(sockfd, recv_buffer, BUF_SIZE, 0);
    if (len <= 0) {
        printf("Error receiving server response\n");
        exit(1);
    }
    printf("Server response: %s", recv_buffer);

    // Send file transfer command
    sprintf(send_buffer, "RETR /path/to/file\r\n");
    send(sockfd, send_buffer, strlen(send_buffer), 0);
    len = recv(sockfd, recv_buffer, BUF_SIZE, 0);
    if (len <= 0) {
        printf("Error receiving server response\n");
        exit(1);
    }
    printf("Server response: %s", recv_buffer);

    // Receive file data
    FILE *fp;
    fp = fopen("file.txt", "wb");
    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }
    char file_buffer[BUF_SIZE];
    while (1) {
        len = recv(sockfd, file_buffer, BUF_SIZE, 0);
        if (len <= 0) {
            printf("Error receiving file data\n");
            exit(1);
        }
        fwrite(file_buffer, len, 1, fp);
        if (feof(fp)) {
            break;
        }
    }
    fclose(fp);

    // Close socket
    close(sockfd);

    return 0;
}