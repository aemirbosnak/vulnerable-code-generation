//Code Llama-13B DATASET v1.0 Category: Socket programming ; Style: secure
/*
 * A unique C Socket programming example program in a secure style
 *
 * Compile: gcc -o socket_secure socket_secure.c
 *
 * Usage: ./socket_secure <port> <file>
 *
 * Example: ./socket_secure 8080 file.txt
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUFSIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <port> <file>\n", argv[0]);
        exit(1);
    }

    int port = atoi(argv[1]);
    char *file = argv[2];

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket() failed");
        exit(1);
    }

    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = INADDR_ANY;

    if (bind(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("bind() failed");
        exit(1);
    }

    if (listen(sock, 1) < 0) {
        perror("listen() failed");
        exit(1);
    }

    struct sockaddr_in client;
    socklen_t client_len = sizeof(client);

    int client_sock = accept(sock, (struct sockaddr *)&client, &client_len);
    if (client_sock < 0) {
        perror("accept() failed");
        exit(1);
    }

    FILE *fp = fopen(file, "r");
    if (fp == NULL) {
        perror("fopen() failed");
        exit(1);
    }

    char buf[BUFSIZE];
    while (fgets(buf, BUFSIZE, fp) != NULL) {
        if (send(client_sock, buf, strlen(buf), 0) < 0) {
            perror("send() failed");
            exit(1);
        }
    }

    fclose(fp);
    close(client_sock);
    close(sock);

    return 0;
}