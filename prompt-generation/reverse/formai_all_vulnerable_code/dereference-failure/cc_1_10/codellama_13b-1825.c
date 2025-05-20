//Code Llama-13B DATASET v1.0 Category: Building a FTP Client ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>

#define PORT 21
#define BUFSIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <host> <file>\n", argv[0]);
        return 1;
    }

    char *host = argv[1];
    char *file = argv[2];

    struct hostent *server = gethostbyname(host);
    if (server == NULL) {
        perror("gethostbyname");
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr = *((struct in_addr *)server->h_addr);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return 1;
    }

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        return 1;
    }

    char buf[BUFSIZE];
    snprintf(buf, BUFSIZE, "USER %s\r\n", "anonymous");
    send(sock, buf, strlen(buf), 0);
    recv(sock, buf, BUFSIZE, 0);

    snprintf(buf, BUFSIZE, "PASS %s\r\n", "anonymous");
    send(sock, buf, strlen(buf), 0);
    recv(sock, buf, BUFSIZE, 0);

    snprintf(buf, BUFSIZE, "CWD %s\r\n", "/");
    send(sock, buf, strlen(buf), 0);
    recv(sock, buf, BUFSIZE, 0);

    snprintf(buf, BUFSIZE, "TYPE I\r\n");
    send(sock, buf, strlen(buf), 0);
    recv(sock, buf, BUFSIZE, 0);

    snprintf(buf, BUFSIZE, "PASV\r\n");
    send(sock, buf, strlen(buf), 0);
    recv(sock, buf, BUFSIZE, 0);

    char *pasv = strchr(buf, '(');
    if (pasv == NULL) {
        printf("Invalid PASV response\n");
        return 1;
    }

    int data_port = atoi(pasv + 1);

    struct sockaddr_in data_addr;
    memset(&data_addr, 0, sizeof(data_addr));
    data_addr.sin_family = AF_INET;
    data_addr.sin_port = htons(data_port);
    data_addr.sin_addr = *((struct in_addr *)server->h_addr);

    int data_sock = socket(AF_INET, SOCK_STREAM, 0);
    if (data_sock < 0) {
        perror("socket");
        return 1;
    }

    if (connect(data_sock, (struct sockaddr *)&data_addr, sizeof(data_addr)) < 0) {
        perror("connect");
        return 1;
    }

    FILE *fp = fopen(file, "r");
    if (fp == NULL) {
        perror("fopen");
        return 1;
    }

    char c;
    while ((c = fgetc(fp)) != EOF) {
        send(data_sock, &c, 1, 0);
    }

    fclose(fp);

    snprintf(buf, BUFSIZE, "QUIT\r\n");
    send(sock, buf, strlen(buf), 0);
    recv(sock, buf, BUFSIZE, 0);

    close(sock);
    close(data_sock);

    return 0;
}