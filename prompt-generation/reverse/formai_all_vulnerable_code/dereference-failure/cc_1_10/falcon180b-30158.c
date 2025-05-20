//Falcon-180B DATASET v1.0 Category: Building a IMAP Client ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_LINE_LEN 1024
#define MAX_RESPONSE_LEN 4096
#define IMAP_PORT 143

int main() {
    int sockfd;
    char *server_addr = "localhost";
    char *username = "user";
    char *password = "pass";
    char *cmd = "LOGIN user pass\r\n";
    char *response;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    struct sockaddr_in server_addr_in;
    server_addr_in.sin_family = AF_INET;
    server_addr_in.sin_port = htons(IMAP_PORT);
    inet_pton(AF_INET, server_addr, &server_addr_in.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr_in, sizeof(server_addr_in)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    send(sockfd, cmd, strlen(cmd), 0);

    response = malloc(MAX_RESPONSE_LEN);
    memset(response, 0, MAX_RESPONSE_LEN);

    int n = recv(sockfd, response, MAX_RESPONSE_LEN, 0);
    if (n <= 0) {
        printf("Error receiving response\n");
        exit(1);
    }

    printf("Response: %s\n", response);

    close(sockfd);
    free(response);

    return 0;
}