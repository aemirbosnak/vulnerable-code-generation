//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define PORT 21
#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sock = 0, ret = 0;
    struct sockaddr_in server_addr;
    char *host = argv[1];
    char buffer[BUF_SIZE];

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        perror("socket");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr(host);

    ret = connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));

    if (ret == -1) {
        perror("connect");
        exit(1);
    }

    printf("Connected to FTP server.\n");

    while (1) {
        memset(buffer, 0, BUF_SIZE);
        printf("Enter command: ");
        fgets(buffer, BUF_SIZE, stdin);

        if (strcmp(buffer, "bye") == 0) {
            break;
        }

        ret = send(sock, buffer, strlen(buffer), 0);

        if (ret == -1) {
            perror("send");
            exit(1);
        }

        memset(buffer, 0, BUF_SIZE);
        ret = recv(sock, buffer, BUF_SIZE, 0);

        if (ret == -1) {
            perror("recv");
            exit(1);
        }

        buffer[ret] = '\0';
        printf("Received: %s\n", buffer);
    }

    close(sock);
    return 0;
}