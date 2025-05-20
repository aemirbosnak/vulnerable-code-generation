//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>

#define BUF_SIZE 1024
#define USER "user"
#define PASS "password"

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char buf[BUF_SIZE];
    char *user_name = USER;
    char *pass_word = PASS;
    char *host_name = "localhost";
    int port_num = 110;
    int ret;
    char *cmd;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error in socket creation\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(host_name);
    server_addr.sin_port = htons(port_num);

    ret = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (ret < 0) {
        printf("Error in connection\n");
        exit(1);
    }

    printf("Connected successfully\n");
    printf("Enter the command: ");
    scanf("%s", cmd);

    send(sockfd, cmd, strlen(cmd), 0);

    while (1) {
        memset(buf, 0, BUF_SIZE);
        ret = recv(sockfd, buf, BUF_SIZE, 0);
        if (ret <= 0) {
            printf("Error in receiving data\n");
            exit(1);
        }

        printf("%s", buf);
    }

    close(sockfd);
    return 0;
}