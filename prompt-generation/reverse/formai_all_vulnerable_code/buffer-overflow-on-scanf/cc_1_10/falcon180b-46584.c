//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_LINE 1024
#define PORT 21

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in serveraddr;
    char buffer[MAX_LINE];
    char username[MAX_LINE];
    char password[MAX_LINE];
    char hostname[MAX_LINE];
    char command[MAX_LINE];
    char *ptr;
    int n;

    printf("Enter FTP server hostname: ");
    scanf("%s", hostname);

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(PORT);
    inet_pton(AF_INET, hostname, &serveraddr.sin_addr);

    connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr));

    send(sockfd, username, strlen(username), 0);
    send(sockfd, password, strlen(password), 0);

    while (1) {
        memset(buffer, 0, MAX_LINE);
        n = recv(sockfd, buffer, MAX_LINE, 0);

        if (n <= 0) {
            break;
        }

        ptr = strtok(buffer, "\r\n");
        while (ptr!= NULL) {
            printf("%s", ptr);

            if (strncmp(ptr, "220", 3) == 0) {
                printf("Connected to FTP server.\n");
            } else if (strncmp(ptr, "230", 3) == 0) {
                printf("Login successful.\n");
            } else if (strncmp(ptr, "250", 3) == 0) {
                printf("Directory changed successfully.\n");
            } else if (strncmp(ptr, "257", 3) == 0) {
                printf("Directory changed successfully.\n");
            }

            ptr = strtok(NULL, "\r\n");
        }
    }

    close(sockfd);

    return 0;
}