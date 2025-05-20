//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 21
#define BUFFER_SIZE 1024
#define USER "anonymous"
#define PASS "anonymous@example.com"

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = inet_addr("ftp.example.com");

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("Failed to connect to FTP server\n");
        close(sock);
        exit(1);
    }

    char *login = "USER ";
    strcat(login, USER);
    strcat(login, "\r\n");
    send(sock, login, strlen(login), 0);

    char *pass = "PASS ";
    strcat(pass, PASS);
    strcat(pass, "\r\n");
    send(sock, pass, strlen(pass), 0);

    char buffer[BUFFER_SIZE];
    while (1) {
        memset(buffer, 0, BUFFER_SIZE);
        int bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);
        if (bytes_received <= 0) {
            printf("Disconnected from FTP server\n");
            close(sock);
            exit(0);
        }
        printf("%s", buffer);
    }

    return 0;
}