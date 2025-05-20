//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server;
    char *host, *user, *pass;
    int port;
    char buf[BUF_SIZE];
    int n;

    if (argc!= 5) {
        printf("Usage: %s <host> <port> <username> <password>\n", argv[0]);
        exit(1);
    }

    host = argv[1];
    port = atoi(argv[2]);
    user = argv[3];
    pass = argv[4];

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    inet_pton(AF_INET, host, &server.sin_addr);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    if (send(sock, user, strlen(user), 0) == -1) {
        printf("Error sending username\n");
        exit(1);
    }

    if (send(sock, pass, strlen(pass), 0) == -1) {
        printf("Error sending password\n");
        exit(1);
    }

    while (1) {
        n = recv(sock, buf, BUF_SIZE, 0);
        if (n == -1) {
            printf("Error receiving data\n");
            exit(1);
        } else if (n == 0) {
            break;
        }

        buf[n] = '\0';
        printf("%s", buf);
    }

    close(sock);
    return 0;
}