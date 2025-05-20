//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    char hostname[256];
    int port, sockfd;
    struct sockaddr_in server_addr;
    char username[50], password[50];
    char command[BUFFER_SIZE];
    char response[BUFFER_SIZE];
    FILE *fp;

    printf("Enter hostname: ");
    scanf("%s", hostname);

    printf("Enter port number: ");
    scanf("%d", &port);

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(hostname);

    connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

    printf("Connected to %s:%d\n", hostname, port);

    while (1) {
        printf("Enter command: ");
        scanf("%s", command);

        if (strcmp(command, "quit") == 0) {
            break;
        }

        send(sockfd, command, strlen(command), 0);

        memset(response, 0, BUFFER_SIZE);
        recv(sockfd, response, BUFFER_SIZE, 0);

        printf("Server response: %s\n", response);
    }

    close(sockfd);

    return 0;
}