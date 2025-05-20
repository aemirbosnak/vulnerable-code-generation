//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define PORT 21
#define TIMEOUT 5

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int connect_to_server(const char *ip, int port) {
    int sockfd;
    struct sockaddr_in server_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        error("socket failed");
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, ip, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        error("connect failed");
    }

    return sockfd;
}

int send_command(int sockfd, const char *cmd) {
    int ret;

    ret = send(sockfd, cmd, strlen(cmd), 0);
    if (ret == -1) {
        error("send failed");
    }

    return ret;
}

int receive_response(int sockfd, char *buf, int len) {
    int ret;

    ret = recv(sockfd, buf, len, 0);
    if (ret == -1) {
        error("recv failed");
    }

    buf[ret] = '\0';
    return ret;
}

int main(int argc, char *argv[]) {
    int sockfd;
    char ip[16];
    char user[64];
    char pass[64];
    char cmd[1024];

    printf("Enter IP address: ");
    scanf("%s", ip);

    printf("Enter username: ");
    scanf("%s", user);

    printf("Enter password: ");
    scanf("%s", pass);

    sprintf(cmd, "USER %s\r\n", user);
    send_command(sockfd, cmd);

    sprintf(cmd, "PASS %s\r\n", pass);
    send_command(sockfd, cmd);

    while (1) {
        printf("Enter command (quit to exit): ");
        scanf("%s", cmd);

        if (strcmp(cmd, "quit") == 0) {
            break;
        }

        send_command(sockfd, cmd);
        receive_response(sockfd, cmd, BUFFER_SIZE);
        printf("%s", cmd);
    }

    close(sockfd);
    return 0;
}