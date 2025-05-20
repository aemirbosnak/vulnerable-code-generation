//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <pwd.h>
#include <grp.h>

#define MAX_COMMAND_LEN 1024
#define MAX_RESPONSE_LEN 10240

int main(int argc, char *argv[]) {
    char *server = "localhost";
    int port = 110;
    char username[MAX_COMMAND_LEN];
    char password[MAX_COMMAND_LEN];
    char command[MAX_COMMAND_LEN];
    char response[MAX_RESPONSE_LEN];
    int sockfd;
    struct sockaddr_in serv_addr;
    int opt = 1;
    int n;

    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    inet_pton(AF_INET, server, &serv_addr.sin_addr);

    connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    sprintf(command, "USER %s\r\n", username);
    send(sockfd, command, strlen(command), 0);

    sprintf(command, "PASS %s\r\n", password);
    send(sockfd, command, strlen(command), 0);

    while (1) {
        memset(response, 0, MAX_RESPONSE_LEN);
        n = recv(sockfd, response, MAX_RESPONSE_LEN, 0);
        if (n <= 0) {
            printf("Error receiving response\n");
            exit(1);
        }
        printf("%s", response);
    }

    close(sockfd);
    return 0;
}