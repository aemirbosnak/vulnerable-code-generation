//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <sys/types.h>

#define PORT 21
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char *host = argv[1];
    char *username = argv[2];
    char *password = argv[3];
    char buffer[BUFFER_SIZE];
    int n;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, host, &server_addr.sin_addr);
    server_addr.sin_port = htons(PORT);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");
    send(sockfd, "USER ", 5, 0);
    send(sockfd, username, strlen(username), 0);
    send(sockfd, "\r\n", 2, 0);
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("Server response: %s", buffer);

    send(sockfd, "PASS ", 5, 0);
    send(sockfd, password, strlen(password), 0);
    send(sockfd, "\r\n", 2, 0);
    recv(sockfd, buffer, BUFFER_SIZE, 0);
    printf("Server response: %s", buffer);

    printf("Login successful\n");
    close(sockfd);
    return 0;
}