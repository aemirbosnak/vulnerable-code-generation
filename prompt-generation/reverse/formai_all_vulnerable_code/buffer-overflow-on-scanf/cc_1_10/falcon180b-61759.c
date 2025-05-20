//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 21
#define MAX_COMMAND_LENGTH 1024

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    char sendbuf[MAX_COMMAND_LENGTH], recvbuf[MAX_COMMAND_LENGTH];
    char username[20], password[20];

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        printf("Error opening socket\n");
        exit(1);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    sprintf(sendbuf, "USER %s\r\n", username);
    send(sockfd, sendbuf, strlen(sendbuf), 0);

    recv(sockfd, recvbuf, MAX_COMMAND_LENGTH, 0);

    printf("Server response: %s", recvbuf);

    sprintf(sendbuf, "PASS %s\r\n", password);
    send(sockfd, sendbuf, strlen(sendbuf), 0);

    recv(sockfd, recvbuf, MAX_COMMAND_LENGTH, 0);

    printf("Server response: %s", recvbuf);

    close(sockfd);

    return 0;
}