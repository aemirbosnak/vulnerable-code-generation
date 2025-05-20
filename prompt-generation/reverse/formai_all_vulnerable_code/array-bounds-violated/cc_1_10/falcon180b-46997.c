//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>

#define BUF_SIZE 1024
#define SERVER "localhost"
#define PORT 110
#define USER "user"
#define PASS "pass"

int main(int argc, char *argv[]) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    char send_buf[BUF_SIZE], recv_buf[BUF_SIZE];
    char *cmd = "USER ";
    char *user = USER;
    char *pass = PASS;
    int auth = 0;
    time_t start_time, end_time;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    inet_pton(AF_INET, SERVER, &serv_addr.sin_addr);
    serv_addr.sin_port = htons(PORT);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    start_time = time(NULL);
    send(sockfd, cmd, strlen(cmd), 0);
    send(sockfd, user, strlen(user), 0);
    send(sockfd, "\r\n", 2, 0);

    while (1) {
        memset(recv_buf, 0, BUF_SIZE);
        n = recv(sockfd, recv_buf, BUF_SIZE, 0);
        if (n <= 0) {
            break;
        }
        recv_buf[n] = '\0';
        printf("%s", recv_buf);
    }

    end_time = time(NULL);
    printf("Total Time: %ld seconds\n", end_time - start_time);

    close(sockfd);

    return 0;
}