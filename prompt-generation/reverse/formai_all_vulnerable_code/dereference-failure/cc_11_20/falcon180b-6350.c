//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_LINE 1024
#define MAX_SERVER 256
#define POP3_PORT 110

int main() {
    int sock, port, bytes_read;
    char buf[MAX_LINE];
    struct sockaddr_in server_addr;
    char server[MAX_SERVER];
    char user[MAX_LINE];
    char pass[MAX_LINE];
    char cmd[MAX_LINE];
    char response[MAX_LINE];
    FILE *fp;
    int ret;

    printf("Enter POP3 server: ");
    fgets(server, MAX_SERVER, stdin);
    printf("Enter username: ");
    fgets(user, MAX_LINE, stdin);
    printf("Enter password: ");
    fgets(pass, MAX_LINE, stdin);

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);
    inet_pton(AF_INET, server, &server_addr.sin_addr);

    ret = connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (ret == -1) {
        perror("connect");
        exit(1);
    }

    printf("Connected to %s\n", server);

    fp = fdopen(sock, "r+");
    if (fp == NULL) {
        perror("fdopen");
        exit(1);
    }

    ret = fprintf(fp, "USER %s\r\n", user);
    if (ret <= 0) {
        perror("fprintf");
        exit(1);
    }

    ret = fprintf(fp, "PASS %s\r\n", pass);
    if (ret <= 0) {
        perror("fprintf");
        exit(1);
    }

    bytes_read = fread(buf, 1, MAX_LINE, fp);
    if (bytes_read <= 0) {
        perror("fread");
        exit(1);
    }

    buf[bytes_read] = '\0';
    printf("Server response: %s", buf);

    ret = fprintf(fp, "STAT\r\n");
    if (ret <= 0) {
        perror("fprintf");
        exit(1);
    }

    bytes_read = fread(buf, 1, MAX_LINE, fp);
    if (bytes_read <= 0) {
        perror("fread");
        exit(1);
    }

    buf[bytes_read] = '\0';
    printf("Server response: %s", buf);

    ret = fprintf(fp, "QUIT\r\n");
    if (ret <= 0) {
        perror("fprintf");
        exit(1);
    }

    bytes_read = fread(buf, 1, MAX_LINE, fp);
    if (bytes_read <= 0) {
        perror("fread");
        exit(1);
    }

    buf[bytes_read] = '\0';
    printf("Server response: %s", buf);

    fclose(fp);
    close(sock);

    return 0;
}