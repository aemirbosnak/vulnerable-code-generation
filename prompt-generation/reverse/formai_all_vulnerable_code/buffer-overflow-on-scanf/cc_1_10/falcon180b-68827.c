//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: lively
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_LINE 1024
#define PORT 110

int main() {
    int sock;
    struct sockaddr_in server;
    char buffer[MAX_LINE];
    char *username, *password;
    char *host;
    int port;
    char *cmd;
    char *response;
    char *token;
    int status;

    printf("Enter POP3 server hostname: ");
    scanf("%s", host);

    printf("Enter POP3 server port: ");
    scanf("%d", &port);

    printf("Enter POP3 username: ");
    scanf("%s", username);

    printf("Enter POP3 password: ");
    scanf("%s", password);

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    inet_pton(AF_INET, host, &server.sin_addr);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    status = 0;
    while (status == 0) {
        memset(buffer, 0, MAX_LINE);
        printf("Enter command: ");
        scanf("%s", cmd);

        send(sock, cmd, strlen(cmd), 0);

        while (status == 0) {
            memset(buffer, 0, MAX_LINE);
            status = recv(sock, buffer, MAX_LINE, 0);
            if (status == -1) {
                printf("Error receiving data\n");
                exit(1);
            }
            printf("%s", buffer);
        }

        token = strtok(buffer, "\r\n");
        if (token == NULL) {
            printf("Error parsing response\n");
            exit(1);
        }

        response = strtok(NULL, "\r\n");
        if (response == NULL) {
            printf("Error parsing response\n");
            exit(1);
        }

        if (strcmp(response, "+OK") == 0) {
            status = 1;
        } else {
            printf("Error: %s\n", response);
        }
    }

    close(sock);
    return 0;
}