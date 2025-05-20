//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define PORT 110
#define USER "username"
#define PASS "password"

int main() {
    int sock;
    struct sockaddr_in server;
    char buffer[BUFFER_SIZE];
    int n;

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    server.sin_addr.s_addr = inet_addr("pop.example.com");

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
        perror("connect");
        exit(1);
    }

    if (send(sock, "USER ", 5, 0) == -1) {
        perror("send");
        exit(1);
    }

    if (send(sock, USER, strlen(USER), 0) == -1) {
        perror("send");
        exit(1);
    }

    if (send(sock, "\r\n", 2, 0) == -1) {
        perror("send");
        exit(1);
    }

    if (send(sock, "PASS ", 5, 0) == -1) {
        perror("send");
        exit(1);
    }

    if (send(sock, PASS, strlen(PASS), 0) == -1) {
        perror("send");
        exit(1);
    }

    if (send(sock, "\r\n", 2, 0) == -1) {
        perror("send");
        exit(1);
    }

    while ((n = recv(sock, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[n] = '\0';
        printf("%s", buffer);
    }

    close(sock);
    return 0;
}