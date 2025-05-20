//Code Llama-13B DATASET v1.0 Category: Building a FTP Client ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

#define FTP_PORT 21
#define FTP_BUF_SIZE 1024
#define MAX_FTP_CMDS 10

typedef struct {
    char *name;
    char *value;
} ftp_cmd_t;

ftp_cmd_t ftp_cmds[MAX_FTP_CMDS] = {
    { "USER", "USER anonymous" },
    { "PASS", "PASS anonymous" },
    { "PWD", "PWD" },
    { "CWD", "CWD" },
    { "LIST", "LIST" },
    { "RETR", "RETR" },
    { "STOR", "STOR" },
    { "DELE", "DELE" },
    { "RNFR", "RNFR" },
    { "RNTO", "RNTO" },
};

int main(int argc, char *argv[]) {
    int sock, res, i;
    struct sockaddr_in server_addr;
    char *host, *port, *cmd;
    char *buf = malloc(FTP_BUF_SIZE);
    size_t buf_size = FTP_BUF_SIZE;

    if (argc != 4) {
        fprintf(stderr, "Usage: %s <host> <port> <command>\n", argv[0]);
        exit(1);
    }

    host = argv[1];
    port = argv[2];
    cmd = argv[3];

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(port));
    res = inet_pton(AF_INET, host, &server_addr.sin_addr);
    if (res < 0) {
        perror("inet_pton");
        exit(1);
    }

    res = connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (res < 0) {
        perror("connect");
        exit(1);
    }

    for (i = 0; i < MAX_FTP_CMDS; i++) {
        if (strcmp(ftp_cmds[i].name, cmd) == 0) {
            res = send(sock, ftp_cmds[i].value, strlen(ftp_cmds[i].value), 0);
            if (res < 0) {
                perror("send");
                exit(1);
            }
        }
    }

    res = recv(sock, buf, buf_size, 0);
    if (res < 0) {
        perror("recv");
        exit(1);
    }

    printf("%s\n", buf);

    free(buf);
    close(sock);

    return 0;
}