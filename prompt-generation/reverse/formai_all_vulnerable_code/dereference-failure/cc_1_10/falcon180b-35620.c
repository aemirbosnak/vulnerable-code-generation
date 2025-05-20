//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define PORT 21
#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, ret;
    struct sockaddr_in server_addr;
    char buffer[BUF_SIZE];

    if (argc!= 3) {
        printf("Usage: %s <server_ip> <username>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);

    ret = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (ret == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    sprintf(buffer, "USER %s\r\n", argv[2]);
    send(sockfd, buffer, strlen(buffer), 0);

    char *response = (char *)malloc(BUF_SIZE);
    memset(response, 0, BUF_SIZE);

    ret = recv(sockfd, response, BUF_SIZE, 0);
    if (ret == -1) {
        printf("Error receiving response\n");
        exit(1);
    }

    printf("Server response: %s", response);

    close(sockfd);
    return 0;
}