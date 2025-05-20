//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>

#define BUF_SIZE 1024
#define PORT 21

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server;
    char username[50], password[50];
    char buffer[BUF_SIZE];
    int n;
    char *ptr;
    FILE *fp;

    if (argc!= 4) {
        printf("Usage: %s <server> <username> <password>\n", argv[0]);
        exit(1);
    }

    strcpy(username, argv[2]);
    strcpy(password, argv[3]);

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1)
        error("socket failed");

    server.sin_family = AF_INET;
    server.sin_port = htons(PORT);
    inet_pton(AF_INET, argv[1], &server.sin_addr);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1)
        error("connect failed");

    printf("Connected to %s\n", argv[1]);

    send(sock, username, strlen(username), 0);
    send(sock, password, strlen(password), 0);

    while ((n = recv(sock, buffer, BUF_SIZE, 0)) > 0) {
        buffer[n] = '\0';
        printf("%s", buffer);
    }

    close(sock);
    return 0;
}