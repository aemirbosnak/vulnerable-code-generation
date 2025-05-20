//Code Llama-13B DATASET v1.0 Category: Building a POP3 Client ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>
#include <stdbool.h>

#define POP3_PORT 110
#define POP3_USER "user"
#define POP3_PASS "password"
#define POP3_HOST "pop.example.com"

int main(int argc, char *argv[]) {
    int sock, bytes_read;
    char buffer[1024];
    struct sockaddr_in server_addr;
    struct hostent *server;

    if ((server = gethostbyname(POP3_HOST)) == NULL) {
        perror("gethostbyname");
        exit(1);
    }

    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);
    server_addr.sin_addr = *((struct in_addr *) server->h_addr);

    if (connect(sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        exit(1);
    }

    if (send(sock, "USER ", 5, 0) == -1) {
        perror("send");
        exit(1);
    }
    if (send(sock, POP3_USER, strlen(POP3_USER), 0) == -1) {
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
    if (send(sock, POP3_PASS, strlen(POP3_PASS), 0) == -1) {
        perror("send");
        exit(1);
    }
    if (send(sock, "\r\n", 2, 0) == -1) {
        perror("send");
        exit(1);
    }

    if (send(sock, "LIST\r\n", 6, 0) == -1) {
        perror("send");
        exit(1);
    }

    while ((bytes_read = recv(sock, buffer, sizeof(buffer), 0)) > 0) {
        buffer[bytes_read] = '\0';
        printf("%s", buffer);
    }

    if (bytes_read == -1) {
        perror("recv");
        exit(1);
    }

    if (send(sock, "QUIT\r\n", 6, 0) == -1) {
        perror("send");
        exit(1);
    }

    close(sock);
    return 0;
}