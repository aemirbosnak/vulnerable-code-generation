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
    char filename[256];

    if (argc != 3) {
        fprintf(stderr,"Usage: %s <hostname> <filename>\n", argv[0]);
        exit(1);
    }

    strcpy(filename, argv[2]);

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        error("ERROR opening socket");

    memset(&serv_addr, 0, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(21);

    if(inet_pton(AF_INET, argv[1], &serv_addr.sin_addr)<=0) {
        error("Invalid address/ Address not supported");
    }

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR connecting");

    send(sockfd, "USER anonymous\r\n", 17, 0);
    send(sockfd, "PASS anonymous\r\n", 17, 0);
    send(sockfd, "CWD /\r\n", 8, 0);
    send(sockfd, "RETR ", 5, 0);
    send(sockfd, filename, strlen(filename), 0);
    send(sockfd, "\r\n", 2, 0);

    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        error("Error opening file");
    }

    while (1) {
        int n = read(sockfd, buffer, BUFFER_SIZE - 1);
        if (n <= 0) break;
        buffer[n] = '\0';
        fwrite(buffer, 1, n, fp);
    }

    fclose(fp);
    close(sockfd);

    return 0;
}
