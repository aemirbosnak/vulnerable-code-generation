//Code Llama-13B DATASET v1.0 Category: Building a FTP Client ; Style: shocked
/*
 * A shocked FTP client example program in C
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <host> <port> <filename>\n", argv[0]);
        return 1;
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return 1;
    }

    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(argv[2]));

    if (inet_pton(AF_INET, argv[1], &server.sin_addr) <= 0) {
        fprintf(stderr, "Invalid address\n");
        return 1;
    }

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("connect");
        return 1;
    }

    char buf[1024];
    int n;

    // send the FTP command to the server
    n = snprintf(buf, sizeof(buf), "GET %s\r\n", argv[3]);
    if (send(sock, buf, n, 0) < 0) {
        perror("send");
        return 1;
    }

    // receive the response from the server
    n = recv(sock, buf, sizeof(buf), 0);
    if (n < 0) {
        perror("recv");
        return 1;
    }

    printf("%s", buf);

    close(sock);

    return 0;
}