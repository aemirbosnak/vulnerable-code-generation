//Code Llama-13B DATASET v1.0 Category: Building a FTP Client ; Style: real-life
/*
 * FTP Client
 *
 * A simple FTP client program that connects to an FTP server,
 * lists the files in the current working directory, and downloads
 * a file from the server.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>

#define PORT 21
#define BUF_SIZE 1024

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

    char buf[BUF_SIZE];
    if (recv(sock, buf, BUF_SIZE, 0) < 0) {
        perror("recv");
        return 1;
    }

    printf("Connected to %s\n", host);
    printf("Server message: %s\n", buf);

    char *cmd = "LIST\r\n";
    if (send(sock, cmd, strlen(cmd), 0) < 0) {
        perror("send");
        return 1;
    }

    if (recv(sock, buf, BUF_SIZE, 0) < 0) {
        perror("recv");
        return 1;
    }

    printf("Server response: %s\n", buf);

    cmd = "RETR ";
    cmd = strcat(cmd, file);
    cmd = strcat(cmd, "\r\n");
    if (send(sock, cmd, strlen(cmd), 0) < 0) {
        perror("send");
        return 1;
    }

    if (recv(sock, buf, BUF_SIZE, 0) < 0) {
        perror("recv");
        return 1;
    }

    printf("Server response: %s\n", buf);

    close(sock);

    return 0;
}