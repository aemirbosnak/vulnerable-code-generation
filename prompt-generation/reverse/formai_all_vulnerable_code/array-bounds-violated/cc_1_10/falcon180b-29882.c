//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_LINE 1024
#define POP3_PORT 110
#define USER "username"
#define PASS "password"

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server;
    char buffer[MAX_LINE];
    char *host = "mail.example.com";

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        perror("socket");
        exit(1);
    }

    memset(&server, 0, sizeof(server));

    server.sin_family = AF_INET;
    server.sin_port = htons(POP3_PORT);
    server.sin_addr.s_addr = inet_addr(host);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
        perror("connect");
        exit(1);
    }

    printf("Connected to %s on port %d\n", host, POP3_PORT);

    char *login = "USER ";
    strcat(login, USER);
    strcat(login, "\r\n");

    send(sock, login, strlen(login), 0);

    char *response = "";
    int bytes_received = 0;

    while ((bytes_received = recv(sock, buffer, MAX_LINE, 0)) > 0) {
        buffer[bytes_received] = '\0';
        response = strcat(response, buffer);
    }

    printf("Response: %s", response);

    char *pass = "PASS ";
    strcat(pass, PASS);
    strcat(pass, "\r\n");

    send(sock, pass, strlen(pass), 0);

    bytes_received = 0;

    while ((bytes_received = recv(sock, buffer, MAX_LINE, 0)) > 0) {
        buffer[bytes_received] = '\0';
        response = strcat(response, buffer);
    }

    printf("Response: %s", response);

    close(sock);
    return 0;
}