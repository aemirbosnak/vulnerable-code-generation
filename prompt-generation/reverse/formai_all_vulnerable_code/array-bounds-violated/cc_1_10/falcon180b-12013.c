//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/socket.h>
#include <errno.h>

#define PORT 21
#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, newsockfd;
    struct sockaddr_in server_addr;
    struct sockaddr_in client_addr;
    int addrlen = sizeof(client_addr);
    char buffer[BUF_SIZE];
    int n;

    if (argc!= 4) {
        printf("Usage:./ftp_client <server_ip> <username> <password>\n");
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

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    bzero(buffer, BUF_SIZE);
    sprintf(buffer, "USER %s\r\n", argv[2]);
    send(sockfd, buffer, strlen(buffer), 0);

    bzero(buffer, BUF_SIZE);
    sprintf(buffer, "PASS %s\r\n", argv[3]);
    send(sockfd, buffer, strlen(buffer), 0);

    while (1) {
        bzero(buffer, BUF_SIZE);
        n = recv(sockfd, buffer, BUF_SIZE, 0);
        if (n <= 0) {
            printf("Error receiving data\n");
            exit(1);
        }
        buffer[n] = '\0';
        printf("%s", buffer);
    }

    close(sockfd);
    return 0;
}