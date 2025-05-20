//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_COMMAND_LEN 512
#define MAX_RESPONSE_LEN 1024
#define SERVER "127.0.0.1"
#define PORT 110

int main(void) {
    int sockfd;
    struct sockaddr_in server_addr;
    char username[MAX_COMMAND_LEN];
    char password[MAX_COMMAND_LEN];
    char command[MAX_COMMAND_LEN];
    char response[MAX_RESPONSE_LEN];
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

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, SERVER, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    sprintf(command, "USER %s\r\n", username);
    send(sockfd, command, strlen(command), 0);

    if ((n = recv(sockfd, response, MAX_RESPONSE_LEN, 0)) < 0) {
        printf("Error receiving response\n");
        exit(1);
    }

    response[n] = '\0';
    printf("Server response: %s", response);

    sprintf(command, "PASS %s\r\n", password);
    send(sockfd, command, strlen(command), 0);

    if ((n = recv(sockfd, response, MAX_RESPONSE_LEN, 0)) < 0) {
        printf("Error receiving response\n");
        exit(1);
    }

    response[n] = '\0';
    printf("Server response: %s", response);

    close(sockfd);

    return 0;
}