//Falcon-180B DATASET v1.0 Category: Building a IMAP Client ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_LINE_LEN 1024
#define IMAP_PORT 143
#define IMAP_DELIM "\r\n"

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in serv_addr;
    char send_line[MAX_LINE_LEN];
    char recv_line[MAX_LINE_LEN];
    int n;

    if (argc!= 4) {
        printf("Usage: %s <server_address> <username> <password>\n", argv[0]);
        return 1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error opening socket\n");
        return 1;
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(IMAP_PORT);
    inet_pton(AF_INET, argv[1], &serv_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        printf("Error connecting to server\n");
        return 1;
    }

    printf("Connected to server\n");

    sprintf(send_line, "LOGIN %s %s\r\n", argv[2], argv[3]);
    send(sockfd, send_line, strlen(send_line), 0);

    while ((n = recv(sockfd, recv_line, MAX_LINE_LEN, 0)) > 0) {
        recv_line[n - 1] = '\0';
        printf("%s", recv_line);
    }

    close(sockfd);
    return 0;
}