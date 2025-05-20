//Falcon2-11B DATASET v1.0 Category: Building a FTP Client ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>

#define BUFF_SIZE 1024

int main() {
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    char buffer[BUFF_SIZE];
    char hostname[BUFF_SIZE];
    char username[BUFF_SIZE];
    char password[BUFF_SIZE];

    printf("Enter FTP server address: ");
    scanf("%s", hostname);

    printf("Enter FTP username: ");
    scanf("%s", username);

    printf("Enter FTP password: ");
    scanf("%s", password);

    portno = 21;
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);

    if (inet_pton(AF_INET, hostname, &serv_addr.sin_addr) <= 0) {
        fprintf(stderr, "Invalid address/dns name\n");
        exit(1);
    }

    connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    if (send(sockfd, username, strlen(username), 0) == -1) {
        perror("send error");
        exit(1);
    }

    if (send(sockfd, password, strlen(password), 0) == -1) {
        perror("send error");
        exit(1);
    }

    if (recv(sockfd, buffer, BUFF_SIZE, 0) == -1) {
        perror("recv error");
        exit(1);
    }

    printf("Connected to FTP server\n");

    while (1) {
        printf("ftp> ");
        fflush(stdout);
        if (recv(sockfd, buffer, BUFF_SIZE, 0) == -1) {
            perror("recv error");
            exit(1);
        }

        printf("%s\n", buffer);

        if (strcmp(buffer, "quit") == 0)
            break;

        if (strcmp(buffer, "get") == 0) {
            if (send(sockfd, "recv", strlen("recv"), 0) == -1) {
                perror("send error");
                exit(1);
            }
        }

        if (strcmp(buffer, "put") == 0) {
            if (send(sockfd, "send", strlen("send"), 0) == -1) {
                perror("send error");
                exit(1);
            }
        }

        if (strcmp(buffer, "close") == 0) {
            if (close(sockfd) == -1) {
                perror("close error");
                exit(1);
            }
            break;
        }

        if (strcmp(buffer, "help") == 0) {
            if (send(sockfd, "help", strlen("help"), 0) == -1) {
                perror("send error");
                exit(1);
            }
        }
    }

    close(sockfd);
    return 0;
}