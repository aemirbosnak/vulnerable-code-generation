//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_SIZE 1024
#define PORT 21

int main() {
    int sockfd;
    struct sockaddr_in servaddr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, "127.0.0.1", &servaddr.sin_addr) <= 0) {
        perror("inet_pton");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        exit(1);
    }

    char buffer[MAX_SIZE];
    int n;

    // Send the username
    printf("Enter username: ");
    scanf("%s", buffer);
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0) {
        perror("send");
        exit(1);
    }

    // Receive the response
    n = recv(sockfd, buffer, MAX_SIZE, 0);
    if (n < 0) {
        perror("recv");
        exit(1);
    }
    printf("%s\n", buffer);

    // Send the password
    printf("Enter password: ");
    scanf("%s", buffer);
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0) {
        perror("send");
        exit(1);
    }

    // Receive the response
    n = recv(sockfd, buffer, MAX_SIZE, 0);
    if (n < 0) {
        perror("recv");
        exit(1);
    }
    printf("%s\n", buffer);

    // Send the command
    printf("Enter command: ");
    scanf("%s", buffer);
    n = send(sockfd, buffer, strlen(buffer), 0);
    if (n < 0) {
        perror("send");
        exit(1);
    }

    // Receive the response
    n = recv(sockfd, buffer, MAX_SIZE, 0);
    if (n < 0) {
        perror("recv");
        exit(1);
    }
    printf("%s\n", buffer);

    // Close the connection
    close(sockfd);

    return 0;
}