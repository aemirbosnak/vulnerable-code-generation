//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_COMMAND_LENGTH 1024
#define FTP_PORT 21

int main(int argc, char *argv[]) {
    int sockfd, portno;
    char ip[16];
    char username[50], password[50];
    char command[MAX_COMMAND_LENGTH];
    char response[1024];
    struct sockaddr_in serv_addr;
    int n, i;

    printf("Enter IP address: ");
    scanf("%s", ip);

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        printf("Error opening socket\n");
        exit(1);
    }

    portno = FTP_PORT;

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(ip);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to %s\n", ip);

    while (1) {
        printf("Enter command: ");
        fgets(command, MAX_COMMAND_LENGTH, stdin);

        if (send(sockfd, command, strlen(command), 0) < 0) {
            printf("Error sending command\n");
            exit(1);
        }

        memset(response, 0, sizeof(response));

        n = recv(sockfd, response, sizeof(response), 0);

        if (n < 0) {
            printf("Error receiving response\n");
            exit(1);
        }

        printf("Response: %s", response);

        if (strcmp(command, "bye") == 0) {
            break;
        }
    }

    close(sockfd);

    return 0;
}