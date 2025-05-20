//Falcon-180B DATASET v1.0 Category: Wireless Network Scanner ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX 10

void main() {
    int sock;
    struct sockaddr_in server;
    char buffer[1024];
    char *token;
    int i = 0;

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        printf("socket failed with error %d\n", errno);
        exit(0);
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(12345);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
        printf("connect failed with error %d\n", errno);
        exit(0);
    }

    while (1) {
        bzero(buffer, 1024);
        fgets(buffer, sizeof(buffer), stdin);

        if (strcmp(buffer, "scan") == 0) {
            for (i = 0; i < MAX; i++) {
                sprintf(buffer, "wlan%d", i);
                send(sock, buffer, strlen(buffer), 0);
            }
        } else if (strcmp(buffer, "stop") == 0) {
            break;
        } else {
            token = strtok(buffer, " ");
            send(sock, token, strlen(token), 0);
        }
    }

    close(sock);
}