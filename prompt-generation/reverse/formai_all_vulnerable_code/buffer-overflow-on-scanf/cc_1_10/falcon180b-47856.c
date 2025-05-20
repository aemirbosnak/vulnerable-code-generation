//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_LINE 1024
#define PORT 21
#define MAX_PORT_NUM 65535

int main(int argc, char *argv[]) {
    char hostname[MAX_LINE];
    int port;
    int sockfd, newsockfd;
    struct sockaddr_in serv_addr, cli_addr;
    socklen_t clilen;
    char buffer[MAX_LINE];
    FILE *fp;
    int n;

    printf("FTP Client\n");

    printf("Enter hostname: ");
    scanf("%s", hostname);

    printf("Enter port number (1-%d): ", MAX_PORT_NUM);
    scanf("%d", &port);

    if (port < 1 || port > MAX_PORT_NUM) {
        printf("Invalid port number.\n");
        return 1;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket.\n");
        return 1;
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    inet_pton(AF_INET, hostname, &serv_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        printf("Error connecting to server.\n");
        return 1;
    }

    printf("Connected to server.\n");

    while (1) {
        printf("Enter command: ");
        fgets(buffer, MAX_LINE, stdin);
        buffer[strcspn(buffer, "\r\n")] = '\0';

        if (strlen(buffer) == 0) {
            continue;
        }

        if (strcmp(buffer, "quit") == 0) {
            break;
        }

        n = send(sockfd, buffer, strlen(buffer), 0);
        if (n == -1) {
            printf("Error sending command.\n");
            return 1;
        }

        memset(buffer, 0, MAX_LINE);
        n = recv(sockfd, buffer, MAX_LINE, 0);
        if (n == -1) {
            printf("Error receiving response.\n");
            return 1;
        }

        printf("%s", buffer);
    }

    close(sockfd);
    return 0;
}