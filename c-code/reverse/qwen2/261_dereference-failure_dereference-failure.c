#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE];
    FILE *fp;

    if (argc != 5) {
        fprintf(stderr,"Usage: %s <ip> <port> <username> <filename>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[2]));

    if (inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) <= 0) {
        error("Invalid address/ Address not supported");
    }

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        error("Connection failed");

    send(sockfd, "USER ", 5, 0);
    send(sockfd, argv[3], strlen(argv[3]), 0);
    send(sockfd, "\r\n", 2, 0);

    recv(sockfd, buffer, BUFFER_SIZE-1, 0);
    printf("%s", buffer);

    send(sockfd, "PASS ", 5, 0);
    send(sockfd, argv[4], strlen(argv[4]), 0);
    send(sockfd, "\r\n", 2, 0);

    recv(sockfd, buffer, BUFFER_SIZE-1, 0);
    printf("%s", buffer);

    send(sockfd, "RETR ", 5, 0);
    send(sockfd, argv[4], strlen(argv[4]), 0);
    send(sockfd, "\r\n", 2, 0);

    fp = fopen(argv[4], "wb");
    if (fp == NULL) {
        error("Error opening file");
    }

    while ((recv(sockfd, buffer, BUFFER_SIZE-1, 0)) > 0) {
        fwrite(buffer, 1, BUFFER_SIZE-1, fp);
    }

    fclose(fp);
    close(sockfd);

    return 0;
}
