//Falcon-180B DATASET v1.0 Category: Wireless Network Scanner ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX 10
#define PORT "3490"

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sock, newsock, len;
    struct sockaddr_in server, client;
    char buffer[1024];
    int count = 0;
    char **clients = (char **)malloc(MAX * sizeof(char *));

    if (argc!= 2) {
        printf("Usage: %s <IP Address>\n", argv[0]);
        exit(1);
    }

    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock == -1)
        error("socket");

    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(PORT));
    inet_pton(AF_INET, argv[1], &server.sin_addr);

    while (1) {
        memset(buffer, 0, sizeof(buffer));
        len = recvfrom(sock, buffer, sizeof(buffer), 0, NULL, NULL);
        if (len <= 0)
            continue;

        printf("Received message: %s\n", buffer);
        if (count >= MAX) {
            printf("Maximum number of clients reached!\n");
            continue;
        }

        clients[count] = (char *)malloc(sizeof(char) * (len + 1));
        strcpy(clients[count], buffer);
        count++;
    }

    return 0;
}