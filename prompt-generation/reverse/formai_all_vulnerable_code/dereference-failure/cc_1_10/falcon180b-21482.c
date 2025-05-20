//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_LINE 1024
#define SERVER_PORT 25
#define SERVER_ADDR "localhost"
#define FROM_ADDR "user@localhost"
#define TO_ADDR "recipient@localhost"
#define SUBJECT "Hello, world!"
#define BODY "This is a test message.\r\n"

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[MAX_LINE];
    char *response;
    int response_len;
    char *line;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_ADDR, &server_addr.sin_addr);

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        exit(1);
    }

    printf("Connected to server.\r\n");

    response = (char *)malloc(MAX_LINE);
    response_len = 0;

    while (fgets(buffer, MAX_LINE, stdin)!= NULL) {
        line = strchr(buffer, '\n');
        *line = '\0';
        send(sock, buffer, strlen(buffer), 0);

        response_len = 0;
        while ((response_len = recv(sock, response, MAX_LINE - 1, 0)) > 0) {
            response[response_len] = '\0';
            printf("%s", response);
        }
        response[response_len] = '\0';
    }

    close(sock);
    free(response);
    return 0;
}