//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define BUF_SIZE 1024
#define PORT 110

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    char sendline[BUF_SIZE], recvline[BUF_SIZE];

    if (argc!= 4) {
        printf("Usage:./pop3_client <server_address> <username> <password>\n");
        exit(1);
    }

    strcpy(sendline, "USER ");
    strcat(sendline, argv[2]);
    strcat(sendline, "\r\n");

    strcpy(sendline, "PASS ");
    strcat(sendline, argv[3]);
    strcat(sendline, "\r\n");

    strcpy(sendline, "STAT\r\n");

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Error opening socket\n");
        exit(1);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, argv[1], &serv_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    write(sockfd, sendline, strlen(sendline));
    read(sockfd, recvline, BUF_SIZE);

    printf("Server response: %s", recvline);

    close(sockfd);

    return 0;
}