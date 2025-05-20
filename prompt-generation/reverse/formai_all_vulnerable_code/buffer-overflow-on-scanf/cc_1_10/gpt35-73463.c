//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 21
#define BUF_SIZE 1024

void error(char *msg) {
    fprintf(stderr, "%s\n", msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, n;
    char buffer[BUF_SIZE];
    struct sockaddr_in serv_addr;
    char hostname[100];
    char username[100];
    char password[100];
    char filename[100];
    char command[100];
    char response[3];
    FILE *fp;

    if (argc < 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");

    strcpy(hostname, argv[1]);
    printf("Enter username: ");
    scanf("%s", username);
    printf("Enter password: ");
    scanf("%s", password);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR connecting");

    // login to server
    bzero(buffer, BUF_SIZE);
    sprintf(buffer, "USER %s\r\n", username);
    send(sockfd, buffer, strlen(buffer), 0);
    bzero(buffer, BUF_SIZE);
    n = recv(sockfd, buffer, BUF_SIZE, 0);
    printf("%s", buffer);
    if (buffer[0] == '5') {
        error("Invalid username");
    }

    bzero(buffer, BUF_SIZE);
    sprintf(buffer, "PASS %s\r\n", password);
    send(sockfd, buffer, strlen(buffer), 0);
    bzero(buffer, BUF_SIZE);
    n = recv(sockfd, buffer, BUF_SIZE, 0);
    printf("%s", buffer);
    if (buffer[0] == '5') {
        error("Invalid password");
    }

    // main loop
    while (1) {
        printf("ftp> ");
        scanf("%s", command);
        if (strcmp(command, "quit") == 0) {
            close(sockfd);
            break;
        } else if (strcmp(command, "get") == 0) {
            scanf("%s", filename);
            bzero(buffer, BUF_SIZE);
            sprintf(buffer, "RETR %s\r\n", filename);
            send(sockfd, buffer, strlen(buffer), 0);
            bzero(buffer, BUF_SIZE);
            n = recv(sockfd, buffer, BUF_SIZE, 0);
            if (buffer[0] == '5') {
                error("File not found");
            }
            fp = fopen(filename, "wb");
            while ((n = recv(sockfd, buffer, BUF_SIZE, 0)) > 0) {
                fwrite(buffer, sizeof(char), n, fp);
            }
            fclose(fp);
            n = recv(sockfd, buffer, BUF_SIZE, 0);
            printf("%s", buffer);
        } else {
            printf("Invalid command\n");
        }
    }
    return 0;
}