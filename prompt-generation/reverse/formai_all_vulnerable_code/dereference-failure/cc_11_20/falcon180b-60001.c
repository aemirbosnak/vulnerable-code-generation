//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>

#define MAX_LINE 1024
#define PORT 21

int main(int argc, char *argv[]) {
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    char sendline[MAX_LINE], recvline[MAX_LINE];
    char *username = "anonymous";
    char *password = "anonymous@example.com";
    char *host;
    int n;
    FILE *fp;

    if (argc!= 3) {
        printf("Usage: %s <hostname> <filename>\n", argv[0]);
        exit(1);
    }

    host = argv[1];
    fp = fopen(argv[2], "rb");
    if (fp == NULL) {
        printf("Cannot open file %s\n", argv[2]);
        exit(1);
    }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        printf("socket failed\n");
        exit(1);
    }

    if (inet_pton(AF_INET, host, &serv_addr.sin_addr) <= 0) {
        printf("Invalid address/hostname\n");
        exit(1);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("connect failed\n");
        exit(1);
    }

    printf("Connected to %s\n", host);

    if (send(sockfd, username, strlen(username), 0)!= strlen(username)) {
        printf("send failed\n");
        exit(1);
    }

    if (send(sockfd, password, strlen(password), 0)!= strlen(password)) {
        printf("send failed\n");
        exit(1);
    }

    while ((n = fread(sendline, 1, MAX_LINE, fp)) > 0) {
        sendline[n] = '\0';
        if (send(sockfd, sendline, n, 0)!= n) {
            printf("send failed\n");
            exit(1);
        }
    }

    fclose(fp);

    while ((n = recv(sockfd, recvline, MAX_LINE, 0)) > 0) {
        recvline[n] = '\0';
        printf("%s", recvline);
    }

    close(sockfd);

    return 0;
}