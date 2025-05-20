#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define MAX_BUFFER 1024

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in serv_addr;
    char buffer[MAX_BUFFER];
    char filename[256];

    if (argc != 4) {
        fprintf(stderr,"Usage: %s <hostname> <port> <filename>\n", argv[0]);
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

    send(sockfd, "USER anonymous\r\n", 17, 0);
    recv(sockfd, buffer, MAX_BUFFER-1, 0);
    printf("%s", buffer);

    send(sockfd, "PASS anonymous\r\n", 13, 0);
    recv(sockfd, buffer, MAX_BUFFER-1, 0);
    printf("%s", buffer);

    snprintf(buffer, MAX_BUFFER, "RETR %s\r\n", argv[3]);
    send(sockfd, buffer, strlen(buffer), 0);
    recv(sockfd, buffer, MAX_BUFFER-1, 0);
    printf("%s", buffer);

    FILE *fp = fopen(argv[3], "wb");
    if (fp == NULL) {
        error("Error opening local file");
    }

    while ((recv(sockfd, buffer, MAX_BUFFER-1, 0)) > 0) {
        fwrite(buffer, 1, strlen(buffer), fp);
    }

    fclose(fp);
    close(sockfd);

    return 0;
}
