//Falcon-180B DATASET v1.0 Category: Building a IMAP Client ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_LINE 1024
#define IMAP_PORT 143

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char buffer[MAX_LINE];
    char *username = "user";
    char *password = "pass";
    char *host = "localhost";
    int port = IMAP_PORT;
    int n;
    char *command = "LOGIN user pass\r\n";

    if (argc < 5) {
        printf("Usage: %s host port username password\n", argv[0]);
        exit(1);
    }

    host = argv[1];
    port = atoi(argv[2]);
    username = argv[3];
    password = argv[4];

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, host, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    send(sockfd, command, strlen(command), 0);

    while ((n = recv(sockfd, buffer, MAX_LINE, 0)) > 0) {
        buffer[n] = '\0';
        printf("%s", buffer);
    }

    close(sockfd);
    return 0;
}