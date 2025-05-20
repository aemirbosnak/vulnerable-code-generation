//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define PORT 21
#define MAX_LINE_LENGTH 1024

int main() {
    int sockfd, portno;
    char hostname[50];
    struct hostent *server;
    struct sockaddr_in serv_addr;
    char sendline[MAX_LINE_LENGTH];
    char recvline[MAX_LINE_LENGTH];
    char *token;
    FILE *fp;

    printf("Enter the hostname: ");
    scanf("%s", hostname);

    printf("Enter the port number (default is 21): ");
    scanf("%d", &portno);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        printf("Error opening socket\n");
        exit(1);
    }

    server = gethostbyname(hostname);

    if (server == NULL) {
        printf("Error getting hostname\n");
        exit(1);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    serv_addr.sin_addr = *((struct in_addr *)server->h_addr);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to %s\n", hostname);

    fp = fopen("ftp_commands.txt", "r");

    if (fp == NULL) {
        printf("Error opening file\n");
        exit(1);
    }

    while (fgets(sendline, MAX_LINE_LENGTH, fp)!= NULL) {
        send(sockfd, sendline, strlen(sendline), 0);

        memset(recvline, 0, MAX_LINE_LENGTH);

        if (recv(sockfd, recvline, MAX_LINE_LENGTH, 0) <= 0) {
            printf("No response from server\n");
            exit(1);
        }

        printf("Server response: %s", recvline);
    }

    close(sockfd);

    fclose(fp);

    return 0;
}