//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define FTP_PORT 21
#define FTP_USER "anonymous"
#define FTP_PASS "your_email@example.com"

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int ftp_connect(const char *host, int port) {
    int sockfd;
    struct sockaddr_in serv_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("socket failed");
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    inet_pton(AF_INET, host, &serv_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        error("connect failed");
    }

    return sockfd;
}

int ftp_login(int sockfd) {
    char username[64];
    char password[64];
    char buf[1024];

    snprintf(username, sizeof(username), "%s", FTP_USER);
    snprintf(password, sizeof(password), "%s", FTP_PASS);

    send(sockfd, username, strlen(username), 0);
    send(sockfd, password, strlen(password), 0);

    memset(buf, 0, sizeof(buf));
    if (recv(sockfd, buf, sizeof(buf), 0) < 0) {
        error("recv failed");
    }

    printf("FTP server response: %s\n", buf);

    return 0;
}

int ftp_download(int sockfd, const char *filename) {
    char cmd[1024];

    snprintf(cmd, sizeof(cmd), "RETR %s\r\n", filename);

    if (send(sockfd, cmd, strlen(cmd), 0) < 0) {
        error("send failed");
    }

    FILE *fp = fopen(filename, "wb");
    if (fp == NULL) {
        error("fopen failed");
    }

    char buf[1024];
    while (1) {
        memset(buf, 0, sizeof(buf));
        if (recv(sockfd, buf, sizeof(buf), 0) < 0) {
            error("recv failed");
        }

        if (strncmp(buf, "226", 3) == 0) {
            break;
        }

        if (fwrite(buf, 1, strlen(buf), fp) < 0) {
            error("fwrite failed");
        }
    }

    fclose(fp);

    return 0;
}

int main(int argc, char *argv[]) {
    const char *host = "ftp.gnu.org";
    const char *filename = "README";

    int sockfd = ftp_connect(host, FTP_PORT);
    ftp_login(sockfd);
    ftp_download(sockfd, filename);

    close(sockfd);

    return 0;
}