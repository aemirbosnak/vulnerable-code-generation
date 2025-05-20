//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_CMD_LEN 1024
#define MAX_RESP_LEN 4096
#define MAX_LINE_LEN 512

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }

    char *hostname = argv[1];
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(21);
    if (inet_pton(AF_INET, hostname, &serv_addr.sin_addr) <= 0) {
        error("ERROR invalid hostname");
    }

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0){
        error("ERROR connecting");
    }

    char buffer[MAX_RESP_LEN];
    memset(buffer, '\0', sizeof(buffer));
    recv(sockfd, buffer, MAX_RESP_LEN, 0);
    printf("%s\n", buffer);

    char cmd[MAX_CMD_LEN];
    char resp[MAX_RESP_LEN];
    memset(cmd, '\0', sizeof(cmd));
    memset(resp, '\0', sizeof(resp));

    while(1) {
        printf("ftp> ");
        fgets(cmd, MAX_CMD_LEN, stdin);
        if (strncmp(cmd, "quit", 4) == 0) {
            break;
        }

        int n = strlen(cmd);
        if (cmd[n-1] == '\n') {
            cmd[n-1] = '\0';
        }

        send(sockfd, cmd, strlen(cmd), 0);
        memset(resp, '\0', sizeof(resp));
        recv(sockfd, resp, MAX_RESP_LEN, 0);
        printf("%s\n", resp);
    }

    close(sockfd);
    return 0;
}