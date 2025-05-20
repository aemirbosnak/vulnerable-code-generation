//Falcon-180B DATASET v1.0 Category: Building a IMAP Client ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LINE_LEN 1024

int main(int argc, char *argv[]) {
    char *host, *username, *password;
    int port;
    char command[MAX_LINE_LEN];
    char response[MAX_LINE_LEN];
    char *token;
    int i;

    printf("Enter host: ");
    scanf("%s", host);

    printf("Enter port: ");
    scanf("%d", &port);

    printf("Enter username: ");
    scanf("%s", username);

    printf("Enter password: ");
    scanf("%s", password);

    snprintf(command, MAX_LINE_LEN, "LOGIN %s %s", username, password);
    send(command);

    while (1) {
        memset(response, 0, MAX_LINE_LEN);
        if (recv(response, MAX_LINE_LEN) <= 0) {
            printf("Disconnected from server.\n");
            break;
        }

        token = strtok(response, " ");
        if (strcmp(token, "OK") == 0) {
            printf("Logged in successfully.\n");
        } else if (strcmp(token, "NO") == 0) {
            printf("Login failed.\n");
            break;
        } else {
            printf("Unexpected response: %s\n", response);
        }
    }

    return 0;
}