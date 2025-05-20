//Falcon-180B DATASET v1.0 Category: Building a FTP Client ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>

#define BUF_SIZE 1024
#define PORT 21

void error(const char* msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char* argv[]) {
    if (argc!= 4) {
        fprintf(stderr, "Usage: %s <host> <username> <password>\n", argv[0]);
        exit(1);
    }

    char* host = argv[1];
    char* username = argv[2];
    char* password = argv[3];

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        error("socket");
    }

    struct addrinfo hints, *servinfo;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(host, "21", &hints, &servinfo)!= 0) {
        error("getaddrinfo");
    }

    struct sockaddr_in* sockaddr = (struct sockaddr_in*) servinfo->ai_addr;
    inet_ntop(AF_INET, &sockaddr->sin_addr, host, sizeof(host));

    connect(sock, servinfo->ai_addr, servinfo->ai_addrlen);
    freeaddrinfo(servinfo);

    char login[BUF_SIZE];
    snprintf(login, BUF_SIZE, "USER %s\r\n", username);
    send(sock, login, strlen(login), 0);

    char pass[BUF_SIZE];
    snprintf(pass, BUF_SIZE, "PASS %s\r\n", password);
    send(sock, pass, strlen(pass), 0);

    char buffer[BUF_SIZE];
    while (recv(sock, buffer, BUF_SIZE, 0) > 0) {
        fprintf(stdout, "%s", buffer);
    }

    close(sock);

    return 0;
}