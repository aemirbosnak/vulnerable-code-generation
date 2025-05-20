//Falcon-180B DATASET v1.0 Category: Email Client ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>

#define MAX 1000
#define PORT 110

int main() {
    int sockfd, newsockfd, portno, clilen, i, n;
    char buffer[MAX];
    struct sockaddr_in serv_addr, cli_addr;
    char username[50], password[50];
    char *ptr;

    printf("Enter the POP3 server IP address: ");
    scanf("%s", &ptr);
    inet_pton(AF_INET, ptr, &serv_addr.sin_addr);
    portno = PORT;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error creating socket");
        exit(1);
    }

    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    printf("Connected to server\n");

    while (1) {
        bzero(buffer, MAX);
        printf("Enter command (USER/PASS/STAT/LIST/RETR/DELE/QUIT): ");
        scanf("%s", buffer);

        if (strcmp(buffer, "USER") == 0) {
            printf("Enter username: ");
            scanf("%s", username);
            sprintf(buffer, "USER %s\r\n", username);
        } else if (strcmp(buffer, "PASS") == 0) {
            printf("Enter password: ");
            scanf("%s", password);
            sprintf(buffer, "PASS %s\r\n", password);
        } else if (strcmp(buffer, "STAT") == 0) {
            sprintf(buffer, "STAT\r\n");
        } else if (strcmp(buffer, "LIST") == 0) {
            sprintf(buffer, "LIST\r\n");
        } else if (strcmp(buffer, "RETR") == 0) {
            printf("Enter message number: ");
            scanf("%d", &n);
            sprintf(buffer, "RETR %d\r\n", n);
        } else if (strcmp(buffer, "DELE") == 0) {
            printf("Enter message number: ");
            scanf("%d", &n);
            sprintf(buffer, "DELE %d\r\n", n);
        } else if (strcmp(buffer, "QUIT") == 0) {
            sprintf(buffer, "QUIT\r\n");
        }

        send(sockfd, buffer, strlen(buffer), 0);

        bzero(buffer, MAX);
        n = recv(sockfd, buffer, MAX, 0);
        buffer[n] = '\0';
        printf("%s", buffer);
    }

    close(sockfd);
    return 0;
}