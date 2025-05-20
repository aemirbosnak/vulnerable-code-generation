//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_LINE_LENGTH 1024
#define POP3_PORT 110
#define POP3_USER "user@example.com"
#define POP3_PASS "password"

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[MAX_LINE_LENGTH];
    char command[MAX_LINE_LENGTH];
    char response[MAX_LINE_LENGTH];
    int n;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(POP3_PORT);
    server_addr.sin_addr.s_addr = inet_addr("localhost");

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    if (login(sock, POP3_USER, POP3_PASS) == -1) {
        printf("Error logging in\n");
        exit(1);
    }

    printf("Logged in successfully\n");

    while (1) {
        memset(buffer, 0, MAX_LINE_LENGTH);
        memset(command, 0, MAX_LINE_LENGTH);
        memset(response, 0, MAX_LINE_LENGTH);

        printf("Enter command: ");
        fgets(command, MAX_LINE_LENGTH, stdin);

        strcat(command, "\r\n");
        n = send(sock, command, strlen(command), 0);
        if (n == -1) {
            printf("Error sending command\n");
            exit(1);
        }

        n = recv(sock, buffer, MAX_LINE_LENGTH, 0);
        if (n == -1) {
            printf("Error receiving response\n");
            exit(1);
        }

        response[n] = 0;
        printf("Response: %s", response);
    }

    close(sock);
    return 0;
}