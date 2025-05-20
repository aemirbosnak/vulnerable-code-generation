//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUF_SIZE 1024
#define PORT 110
#define USER "your_username"
#define PASS "your_password"
#define SERVER "pop.gmail.com"

int main(int argc, char *argv[]) {
    int sock, n;
    struct sockaddr_in server_addr;
    char buffer[BUF_SIZE];
    char *username = USER;
    char *password = PASS;
    char *server_name = SERVER;

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr(server_name);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    send(sock, username, strlen(username), 0);
    send(sock, "\r\n", 2, 0);

    while ((n = recv(sock, buffer, BUF_SIZE, 0)) > 0) {
        buffer[n] = '\0';
        printf("%s", buffer);
    }

    close(sock);

    return 0;
}