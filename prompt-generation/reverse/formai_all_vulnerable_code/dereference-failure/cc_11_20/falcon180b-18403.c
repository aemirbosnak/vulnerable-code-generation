//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX_LINE 1024
#define PORT 21

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char username[50], password[50];
    char hostname[100];
    char line[MAX_LINE];
    char *token;
    FILE *fp;
    int port;

    if (argc!= 4) {
        printf("Usage:./ftp_client <hostname> <username> <password>\n");
        exit(1);
    }

    strcpy(hostname, argv[1]);
    strcpy(username, argv[2]);
    strcpy(password, argv[3]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error: Could not create socket.\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, hostname, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error: Could not connect to server.\n");
        exit(1);
    }

    printf("Connected to server.\n");

    fp = fdopen(sockfd, "r+");
    if (fp == NULL) {
        printf("Error: Could not create file pointer.\n");
        exit(1);
    }

    do {
        printf("Enter command: ");
        fgets(line, MAX_LINE, stdin);
        token = strtok(line, " ");
        if (token!= NULL && strcmp(token, "USER") == 0) {
            strcat(line, " ");
            strcat(line, username);
            send(sockfd, line, strlen(line), 0);
        } else if (token!= NULL && strcmp(token, "PASS") == 0) {
            strcat(line, " ");
            strcat(line, password);
            send(sockfd, line, strlen(line), 0);
        } else if (token!= NULL && strcmp(token, "LIST") == 0) {
            send(sockfd, line, strlen(line), 0);
        } else if (token!= NULL && strcmp(token, "RETR") == 0) {
            strcat(line, " ");
            send(sockfd, line, strlen(line), 0);
        } else if (token!= NULL && strcmp(token, "STOR") == 0) {
            strcat(line, " ");
            send(sockfd, line, strlen(line), 0);
        } else if (token!= NULL && strcmp(token, "QUIT") == 0) {
            send(sockfd, line, strlen(line), 0);
            break;
        } else {
            printf("Invalid command.\n");
        }
    } while (1);

    close(sockfd);
    fclose(fp);

    return 0;
}