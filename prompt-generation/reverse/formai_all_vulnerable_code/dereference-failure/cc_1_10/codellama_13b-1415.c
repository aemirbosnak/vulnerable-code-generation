//Code Llama-13B DATASET v1.0 Category: Building a FTP Client ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define FTP_PORT 21

int main(int argc, char *argv[]) {
    int sock, res;
    struct sockaddr_in server_addr;
    char *server_ip = "192.168.1.1";
    char *server_port = "21";
    char *username = "user";
    char *password = "pass";

    if (argc < 2) {
        printf("Usage: %s <server_ip> <server_port> <username> <password>\n", argv[0]);
        return 1;
    }

    server_ip = argv[1];
    server_port = argv[2];
    username = argv[3];
    password = argv[4];

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return 1;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(server_ip);
    server_addr.sin_port = htons(atoi(server_port));

    res = connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (res < 0) {
        perror("connect");
        return 1;
    }

    printf("Connected to server.\n");

    send(sock, "USER ", 5, 0);
    send(sock, username, strlen(username), 0);
    send(sock, "\r\n", 2, 0);
    send(sock, "PASS ", 5, 0);
    send(sock, password, strlen(password), 0);
    send(sock, "\r\n", 2, 0);

    char buffer[256];
    res = recv(sock, buffer, sizeof(buffer), 0);
    if (res < 0) {
        perror("recv");
        return 1;
    }

    printf("Server response: %s\n", buffer);

    close(sock);

    return 0;
}