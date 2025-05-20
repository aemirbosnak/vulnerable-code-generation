//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUF_SIZE 4096

int main(int argc, char *argv[]) {
    if(argc != 3) {
        printf("Usage: %s <server_ip> <server_port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int sock_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(sock_fd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_port = htons(atoi(argv[2]));

    if(connect(sock_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    char buf[BUF_SIZE], user[BUF_SIZE], pass[BUF_SIZE];
    int len = 0;
    while(1) {
        printf("> ");
        fgets(buf, BUF_SIZE, stdin);
        if(strncmp(buf, "login", 5) == 0) {
            len = strlen(buf + 6);
            if(buf[6 + len - 1] == '\n') {
                buf[6 + len - 1] = '\0';
            }
            strncpy(user, buf + 6, BUF_SIZE);
            printf("Password: ");
            fflush(stdout);
            fgets(pass, BUF_SIZE, stdin);
            len = strlen(pass);
            if(pass[len - 1] == '\n') {
                pass[len - 1] = '\0';
            }
            strcat(user, " ");
            strcat(user, pass);
            if(send(sock_fd, user, strlen(user), 0) == -1) {
                perror("send");
                exit(EXIT_FAILURE);
            }
            if(recv(sock_fd, buf, BUF_SIZE, 0) == -1) {
                perror("recv");
                exit(EXIT_FAILURE);
            }
            if(strncmp(buf, "OK LOGIN completed", 18) != 0) {
                printf("%s", buf);
            }
        } else if(strncmp(buf, "logout", 6) == 0) {
            if(send(sock_fd, "logout\r\n", 8, 0) == -1) {
                perror("send");
                exit(EXIT_FAILURE);
            }
            if(recv(sock_fd, buf, BUF_SIZE, 0) == -1) {
                perror("recv");
                exit(EXIT_FAILURE);
            }
            if(strncmp(buf, "BYE LOGOUT completed", 20) == 0) {
                printf("%s", buf);
                close(sock_fd);
                exit(EXIT_SUCCESS);
            } else {
                printf("%s", buf);
            }
        } else if(strncmp(buf, "list", 4) == 0) {
            if(send(sock_fd, "list\r\n", 6, 0) == -1) {
                perror("send");
                exit(EXIT_FAILURE);
            }
            if(recv(sock_fd, buf, BUF_SIZE, 0) == -1) {
                perror("recv");
                exit(EXIT_FAILURE);
            }
            printf("%s", buf);
        } else {
            printf("Unknown command: %s", buf);
        }
    }

    return 0;
}