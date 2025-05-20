//Falcon-180B DATASET v1.0 Category: Building a IMAP Client ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_LINE_LEN 1024

int main(int argc, char **argv) {
    int sockfd;
    struct sockaddr_in server_addr;
    char hostname[64];
    char username[64];
    char password[64];
    char command[MAX_LINE_LEN];
    char line[MAX_LINE_LEN];
    char *token;
    int port = 143; // IMAP port

    printf("Enter hostname: ");
    scanf("%s", hostname);

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, hostname, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    while (1) {
        printf("Enter command: ");
        scanf("%s", command);

        send(sockfd, command, strlen(command), 0);

        memset(line, 0, MAX_LINE_LEN);
        recv(sockfd, line, MAX_LINE_LEN, 0);

        printf("Received response: %s\n", line);

        token = strtok(line, " ");
        while (token!= NULL) {
            printf("%s ", token);
            token = strtok(NULL, " ");
        }
        printf("\n");
    }

    close(sockfd);
    return 0;
}