//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_LINE 1024
#define MAX_RESPONSE 1024

int main(int argc, char *argv[])
{
    int sock;
    struct sockaddr_in server;
    char *host, *user, *pass, *command;
    int port, ret, i;
    char line[MAX_LINE];
    char response[MAX_RESPONSE];

    // Check arguments
    if (argc!= 6) {
        fprintf(stderr, "Usage: %s host port user pass command\n", argv[0]);
        exit(1);
    }

    host = argv[1];
    port = atoi(argv[2]);
    user = argv[3];
    pass = argv[4];
    command = argv[5];

    // Connect to server
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        exit(1);
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    inet_pton(AF_INET, host, &server.sin_addr);

    ret = connect(sock, (struct sockaddr *)&server, sizeof(server));
    if (ret == -1) {
        perror("connect");
        exit(1);
    }

    // Auth
    send(sock, "USER ", 5, 0);
    send(sock, user, strlen(user), 0);
    recv(sock, line, MAX_LINE, 0);
    send(sock, "PASS ", 5, 0);
    send(sock, pass, strlen(pass), 0);
    recv(sock, line, MAX_LINE, 0);

    // Send command
    send(sock, command, strlen(command), 0);
    recv(sock, response, MAX_RESPONSE, 0);

    printf("%s\n", response);

    close(sock);
    exit(0);
}