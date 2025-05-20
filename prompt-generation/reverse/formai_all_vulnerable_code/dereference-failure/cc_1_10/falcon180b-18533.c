//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>

#define PORT 21
#define BUF_SIZE 1024

void error_handling(char *message);

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno, clilen;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUF_SIZE];
    char *filename;
    FILE *fp;
    int n;

    if (argc!= 3) {
        printf("Usage:./ftp_client <ip_address> <filename>\n");
        exit(0);
    }

    filename = argv[2];
    printf("Filename: %s\n", filename);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error_handling("Error opening socket");
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    inet_pton(AF_INET, argv[1], &serv_addr.sin_addr);
    serv_addr.sin_port = htons(PORT);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        error_handling("Error connecting");
    }

    printf("Connected to %s\n", argv[1]);

    clilen = sizeof(cli_addr);
    if (getsockname(sockfd, (struct sockaddr *) &cli_addr, &clilen) < 0) {
        error_handling("Error getting socket name");
    }

    printf("Local IP: %s\n", inet_ntoa(cli_addr.sin_addr));
    printf("Local port: %d\n", ntohs(cli_addr.sin_port));

    if (send(sockfd, filename, strlen(filename), 0) < 0) {
        error_handling("Error sending filename");
    }

    if (recv(sockfd, buffer, BUF_SIZE, 0) < 0) {
        error_handling("Error receiving file");
    }

    fp = fopen(buffer, "wb");
    if (fp == NULL) {
        error_handling("Error opening file");
    }

    while ((n = recv(sockfd, buffer, BUF_SIZE, 0)) > 0) {
        fwrite(buffer, 1, n, fp);
    }

    fclose(fp);

    close(sockfd);

    return 0;
}

void error_handling(char *message) {
    perror(message);
    exit(0);
}