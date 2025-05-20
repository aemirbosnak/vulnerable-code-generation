//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define PORT 21
#define BUF_SIZE 1024
#define USER "anonymous"
#define PASS "anonymous@example.com"

void error_handling(char *message);

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server;
    char buffer[BUF_SIZE];

    if (argc!= 4) {
        printf("Usage:./ftp_client <server_ip> <port_number> <file_name>\n");
        exit(1);
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        error_handling("socket failed");
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(argv[2]));
    server.sin_addr.s_addr = inet_addr(argv[1]);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        error_handling("connect failed");
    }

    if (login(sock, USER, PASS)!= 0) {
        error_handling("login failed");
    }

    char mode[10];
    strcpy(mode, "RETR");

    if (send(sock, mode, strlen(mode), 0) < 0) {
        error_handling("send failed");
    }

    if (send(sock, argv[3], strlen(argv[3]), 0) < 0) {
        error_handling("send failed");
    }

    while (1) {
        memset(buffer, 0, BUF_SIZE);
        int bytes_received = recv(sock, buffer, BUF_SIZE, 0);

        if (bytes_received <= 0) {
            break;
        }

        printf("%s", buffer);
    }

    close(sock);

    return 0;
}

void error_handling(char *message) {
    perror(message);
    exit(0);
}