//Code Llama-13B DATASET v1.0 Category: Building a HTTP Client ; Style: innovative
/*
 * A simple HTTP client program in C
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 80
#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <host> [port]\n", argv[0]);
        return 1;
    }

    char *host = argv[1];
    int port = argc > 2 ? atoi(argv[2]) : PORT;

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return 1;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(host);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        return 1;
    }

    char buffer[MAX_BUFFER_SIZE];
    sprintf(buffer, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", host);
    send(sock, buffer, strlen(buffer), 0);

    while (1) {
        int n = recv(sock, buffer, MAX_BUFFER_SIZE, 0);
        if (n < 0) {
            perror("recv");
            return 1;
        }
        if (n == 0) {
            break;
        }
        printf("%.*s", n, buffer);
    }

    close(sock);
    return 0;
}