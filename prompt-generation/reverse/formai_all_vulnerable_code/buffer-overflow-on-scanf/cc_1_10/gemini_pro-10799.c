//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 21
#define MAX_BUF 1024

int main() {
    int sockfd, len, n;
    char buf[MAX_BUF];
    char username[100], password[100];
    struct sockaddr_in servaddr;

    // Create a TCP socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    // Set up server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        exit(1);
    }

    // Read welcome message from server
    len = recv(sockfd, buf, MAX_BUF, 0);
    printf("%s", buf);

    // Send username
    printf("Enter username: ");
    scanf("%s", username);
    strcpy(buf, "USER ");
    strcat(buf, username);
    strcat(buf, "\r\n");
    len = send(sockfd, buf, strlen(buf), 0);

    // Read server response
    len = recv(sockfd, buf, MAX_BUF, 0);
    printf("%s", buf);

    // Send password
    printf("Enter password: ");
    scanf("%s", password);
    strcpy(buf, "PASS ");
    strcat(buf, password);
    strcat(buf, "\r\n");
    len = send(sockfd, buf, strlen(buf), 0);

    // Read server response
    len = recv(sockfd, buf, MAX_BUF, 0);
    printf("%s", buf);

    // Send command to list files
    strcpy(buf, "LIST\r\n");
    len = send(sockfd, buf, strlen(buf), 0);

    // Read file list
    while ((len = recv(sockfd, buf, MAX_BUF, 0)) > 0) {
        printf("%s", buf);
    }

    // Close socket
    close(sockfd);

    return 0;
}