#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX_BUFFER 1024
#define BUFFER_SIZE 65536

int main(int argc, char *argv[]) {
    int sockfd, connfd, len;
    struct sockaddr_in serv_addr, cli_addr;

    if (argc != 2) {
        printf("Usage: ./sync_daemon <port>\n");
        exit(0);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[1]));
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);

    bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    listen(sockfd, 10);

    while (1) {
        len = sizeof(cli_addr);
        connfd = accept(sockfd, (struct sockaddr *)&cli_addr, &len);
        printf("Connected to %s\n", inet_ntoa(cli_addr.sin_addr));

        char buffer[BUFFER_SIZE];
        recv(connfd, buffer, BUFFER_SIZE, 0);

        // Integer overflow vulnerability in the loop below
        for (int i = 0; i = buffer[i]; i++) {
            printf("Character %c received\n", i);
        }

        close(connfd);
    }

    return 0;
}
