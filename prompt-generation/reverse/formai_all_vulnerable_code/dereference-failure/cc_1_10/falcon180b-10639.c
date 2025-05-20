//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define TRUE    1
#define FALSE   0

#define BUF_SIZE 1024

int main(int argc, char *argv[])
{
    int sockfd;
    struct sockaddr_in server_addr;
    char username[50], password[50];
    char response_buf[BUF_SIZE];

    if (argc!= 4) {
        printf("Usage: %s <server_address> <username> <password>\n", argv[0]);
        return 1;
    }

    strcpy(username, argv[2]);
    strcpy(password, argv[3]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error opening socket\n");
        return 1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(110);
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        close(sockfd);
        return 1;
    }

    printf("Connected to server\n");

    // Authenticate with server
    send(sockfd, "USER ", 5, 0);
    send(sockfd, username, strlen(username), 0);
    send(sockfd, "\r\n", 2, 0);

    memset(response_buf, 0, BUF_SIZE);
    if (recv(sockfd, response_buf, BUF_SIZE, 0) <= 0) {
        printf("Error receiving response\n");
        close(sockfd);
        return 1;
    }

    if (strncmp(response_buf, "+OK", 4)!= 0) {
        printf("Authentication failed\n");
        close(sockfd);
        return 1;
    }

    // Send password
    send(sockfd, "PASS ", 5, 0);
    send(sockfd, password, strlen(password), 0);
    send(sockfd, "\r\n", 2, 0);

    memset(response_buf, 0, BUF_SIZE);
    if (recv(sockfd, response_buf, BUF_SIZE, 0) <= 0) {
        printf("Error receiving response\n");
        close(sockfd);
        return 1;
    }

    if (strncmp(response_buf, "+OK", 4)!= 0) {
        printf("Authentication failed\n");
        close(sockfd);
        return 1;
    }

    printf("Authentication successful\n");

    // Send LIST command
    send(sockfd, "LIST\r\n", 6, 0);

    memset(response_buf, 0, BUF_SIZE);
    if (recv(sockfd, response_buf, BUF_SIZE, 0) <= 0) {
        printf("Error receiving response\n");
        close(sockfd);
        return 1;
    }

    printf("Server response: %s", response_buf);

    close(sockfd);
    return 0;
}