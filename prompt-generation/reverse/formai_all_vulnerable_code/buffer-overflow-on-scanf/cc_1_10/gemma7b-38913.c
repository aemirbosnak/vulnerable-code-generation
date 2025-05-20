//Gemma-7B DATASET v1.0 Category: Building a FTP Client ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>

#define MAX_BUF_SIZE 1024

int main() {
    int sockfd, n, i, port, server_port;
    char buf[MAX_BUF_SIZE], filename[256];
    struct sockaddr_in server_addr;

    printf("Enter server port: ");
    scanf("%d", &server_port);

    sockfd = socket(AF_INET, SOCK_STREAM, htons(6));
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(server_port);
    server_addr.sin_addr.s_addr = inet_addr("localhost");

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    printf("Enter filename: ");
    scanf("%s", filename);

    n = send(sockfd, filename, strlen(filename) + 1, 0);
    if (n < 0) {
        perror("Error sending filename");
        exit(1);
    }

    n = recv(sockfd, buf, MAX_BUF_SIZE, 0);
    if (n < 0) {
        perror("Error receiving file");
        exit(1);
    }

    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }

    fwrite(buf, n, 1, fp);
    fclose(fp);

    close(sockfd);
    return 0;
}