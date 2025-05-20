//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 21
#define MAX 1024

void error(char *msg) {
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in serv_addr;
    char buffer[MAX];

    if (argc < 3) {
        printf("Usage:./ftp_client <IP Address> <Port Number>\n");
        return 0;
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock < 0)
        error("socket failed");

    bzero(&serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    inet_pton(AF_INET, argv[1], &serv_addr.sin_addr);
    serv_addr.sin_port = htons(atoi(argv[2]));

    if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        error("connect failed");

    printf("Connected to %s:%d\n", inet_ntoa(serv_addr.sin_addr), ntohs(serv_addr.sin_port));

    while (1) {
        printf("Enter command (ls/get/put/quit): ");
        scanf("%s", buffer);

        if (send(sock, buffer, strlen(buffer), 0) < 0)
            error("send failed");

        bzero(buffer, MAX);

        if (recv(sock, buffer, MAX, 0) < 0)
            error("recv failed");

        printf("%s\n", buffer);

        if (strcmp(buffer, "quit") == 0)
            break;
    }

    close(sock);
    return 0;
}