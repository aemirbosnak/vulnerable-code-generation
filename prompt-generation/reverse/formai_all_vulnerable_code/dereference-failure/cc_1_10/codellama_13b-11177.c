//Code Llama-13B DATASET v1.0 Category: Building a FTP Client ; Style: protected
/*
 * A simple FTP client program in C using protected style
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define FTP_PORT 21
#define BUF_SIZE 1024

typedef struct {
    char host[256];
    char user[256];
    char pass[256];
    int port;
} ftp_info_t;

void ftp_login(ftp_info_t *info) {
    int sock, n;
    struct sockaddr_in server;
    char buffer[BUF_SIZE];

    // Create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        exit(1);
    }

    // Setup server address
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(info->host);
    server.sin_port = htons(info->port);

    // Connect to server
    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("connect");
        exit(1);
    }

    // Send username and password
    sprintf(buffer, "USER %s\r\n", info->user);
    n = send(sock, buffer, strlen(buffer), 0);
    if (n < 0) {
        perror("send");
        exit(1);
    }

    sprintf(buffer, "PASS %s\r\n", info->pass);
    n = send(sock, buffer, strlen(buffer), 0);
    if (n < 0) {
        perror("send");
        exit(1);
    }

    // Wait for response
    n = recv(sock, buffer, BUF_SIZE, 0);
    if (n < 0) {
        perror("recv");
        exit(1);
    }

    // Print response
    printf("%s", buffer);

    // Close socket
    close(sock);
}

int main(int argc, char *argv[]) {
    ftp_info_t info;

    // Get FTP server address, username, and password
    if (argc < 4) {
        printf("Usage: %s host user pass\n", argv[0]);
        exit(1);
    }

    strcpy(info.host, argv[1]);
    strcpy(info.user, argv[2]);
    strcpy(info.pass, argv[3]);
    info.port = FTP_PORT;

    // Login to FTP server
    ftp_login(&info);

    return 0;
}